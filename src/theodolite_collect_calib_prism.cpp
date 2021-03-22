#include "ros/ros.h"

#include "theodolite_node_msgs/TheodoliteCoordsStamped.h"
#include "theodolite_node_msgs/TheodoliteTimeCorrection.h"

#include "lora_radio.h"
#include "radio_message_serialize.h"

#include <sstream>
#include <fstream>
#include <chrono>
#include <math.h>
#include<Eigen/Dense>
#include <list>

//#include <mutex>
//#include <deque>
//#include <thread>
#include <iostream>
#include <condition_variable>
#include <chrono>

#define RECEIVE_TIMEOUT_MS 2000
#define TIME_BEFORE_NEXT_TX_ATTEMPT 10000
#define TIME_BEFORE_NEXT_TX_ATTEMPT_COLLECT 2000
#define MAX_ATTEMPTS_BEFORE_SHUTDOWN 3

using namespace std;

// #############################################
// #############################################
//

//Option selected in launchfile
bool show_data = true;   //Option to see data on terminal when received
int rate = 10;           //Rate of listener in Hz
bool received_data = false;
bool received_dOk = false;
bool received_dNo = false;
bool received_nOk = false;
bool received_nNo = false;
bool received_measurement = false;
int iterator_bad_status_received = 0;
bool bad_status_error = false;

byte status;
byte theodolite_number;
double elevation;
double azimuth;
double meas_distance;
uint32_t secs;
uint32_t nsecs;
uint32_t former_nsecs=0;

struct TheodoliteMeasurement{
    byte theodolite_number;    
    byte status;    
    double azimuth;    
    double elevation;    
    double meas_distance;
    uint32_t sec;
    uint32_t nsec;

    TheodoliteMeasurement():theodolite_number(0), status(255), azimuth(0.0), elevation(0.0), meas_distance(0.0), sec(0), nsec(0){};
};    
     
std::list<TheodoliteMeasurement> list_direct_measurement = {};

void Received_data_check()
{
    std::vector<byte> message;
    unsigned int receivedbytes;
    bool data_CRC_ok = false;
    bool corrupted_message = false;
    int iterator_vector = 0;

    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    received_data = false;
    received_dOk = false;
    received_dNo = false;
    received_nOk = false;
    received_nNo = false;
    received_measurement = false;


    while(received_data == false)
    {
        if(receivepacket(message, data_CRC_ok, show_data)){
            if(data_CRC_ok){
                
			    receivedbytes = message.size();

                if(receivedbytes >= 2)
                {
                    if(message[0]>0 && message[0]<10 )
                    {
                        // looking for the theodolite data
                        corrupted_message = !( unpack_theodolite_message_from_bytes(message,
                                                                                   theodolite_number,
                                                                                   status,
                                                                                   elevation,
                                                                                   azimuth,
                                                                                   meas_distance,
                                                                                   secs,
                                                                                   nsecs) );                      

                        if(show_data && !corrupted_message)
                        {
                            ROS_INFO("Theodolite: %d ; HA: %f ; VA: %f ; Distance: %f ; Time server sec: %d ; Time server nsec: %d ; Status: %d \n", 
                               theodolite_number,
                               azimuth,
                               elevation,
                               meas_distance,
                               secs,
                               nsecs,
                               status);
                        }
                        else{
                            ROS_INFO("Not a coordinate messsage or malformed.");                        
                        }

                        if(!corrupted_message){
                            received_data = true;
                            received_measurement = true;
                        }else{
                            received_data = true;
                        }
                        break;
                    }
                       
                    if(message[0]=='s')
                    {
                        received_data = true;
                        uint32_t secs, nsecs;
                        byte command_code;
                        
                        corrupted_message = !( unpack_theodolite_time_from_bytes(message,
                                                                                 command_code,
                                                                                 secs,
                                                                                 nsecs));
                        if(!corrupted_message){
                            ROS_INFO("Theodolite responded this time: sec: %d; nsec: %d\n", 
                               secs,
                               nsecs);                                             
                        }     
                        received_data = true;                   
                        break;
                    }
            
                    if(receivedbytes == 3)
                    {
                        if(message[0] == 'd'){
                            if(message[1] == 'O' && message[2] == 'k') {received_dOk = true; received_data = true; break;}
                            else if (message[1] == 'N' && message[2] == 'o') {received_dNo = true; received_data = true; break;}                            
                        }
    
                        if(message[0] == 'n'){
                            if(message[1] == 'O' && message[2] == 'k') {received_nOk = true; received_data = true; break;}
                            else if (message[1] == 'N' && message[2] == 'o') {received_nNo = true; received_data = true; break;}                            
                        }
                    }
                    
                    

                }
            }
            else{
                ROS_WARN("Received corrupted message (bad CRC)");
                corrupted_message=true;       
            }
            break;
        }
        else{
            delay(1);
            if(std::chrono::steady_clock::now() - start > std::chrono::milliseconds(RECEIVE_TIMEOUT_MS))
            {
               received_data = false;
               std::cout << "Waiting..." << std::endl;
               break;
            }
        }
        
    }
    
}

void print_marker_table(std::vector<std::vector<TheodoliteMeasurement>> markers_data_structure){
    int number_of_theodolites = markers_data_structure.size();
    if(!number_of_theodolites) return;
    int number_of_markers = markers_data_structure[0].size();
    if(!number_of_markers) return;

    std::cout << std::endl << "Markers collected so far: (X == not yet, ▓ == collected)" << std::endl ;
    std::cout << "Theodolite:\t| " ;
    for(int i = 0; i < number_of_theodolites; i++){
        std::cout << i+1 << "\t| " ;        
    }
    std::cout << std::endl;

    for(int i = 0; i < number_of_markers; i++){
        std::cout << "Marker " << i+1 << ":\t| ";
        for(int j = 0; j < number_of_theodolites; j++){
            std::cout << (markers_data_structure[j][i].status==255 ? "X" : "▓") << "\t| ";        
        }
        std::cout << std::endl;
    }
}

Matrix4f ptp_minimization(Matrix3f P, Matrix3f Q)
{
	Vector3f mean_p(0, 0, 0);
	Vector3f mean_q(0, 0, 0);

	mean_p(0) = (P.block<1,P.cols()>(0,0)).mean();
	mean_p(1) = (P.block<1,P.cols()>(1,0)).mean();
	mean_p(2) = (P.block<1,P.cols()>(2,0)).mean();
	mean_q(0) = (Q.block<1,Q.cols()>(0,0)).mean();
	mean_q(1) = (Q.block<1,Q.cols()>(1,0)).mean();
	mean_q(2) = (Q.block<1,Q.cols()>(2,0)).mean();

	Matrix3f P_mean = (P).colwise() - mean_p;
	Matrix3f Q_mean = (Q).colwise() - mean_q;
	
	Matrix3f H = P_mean*Q_mean.transpose();

	JacobiSVD<MatrixXf> svd(H, ComputeThinU | ComputeThinV);
	Matrix3f V = svd.matrixV();
	Matrix3f U = svd.matrixU();
	Matrix3f R = V.transpose()*U.transpose();

	if(R.determinant()<0)
	{
		Matrix3f V_t = V.transpose();
		V_t.block<3,1>(0,2)=-V_t.block<3,1>(0,2);
		R = V_t*U.transpose();
	}

	Vector3f t = mean_q - R*mean_p;
	std::cout << "rotation :" << R << std::endl;
	std::cout << "translation: " << t << std::endl; 

	Matrix4f T = Matrix4f::Identity();
	T.block<3,3>(0,0)=R;
	T.block<3,1>(0,3)=t;

	return T;
}

Vector4f give_points(float d, float ha, float va)
{
	d = d + 0.01; // add 10mm because measurments done by raspi
	x=d*cos(-ha)*cos(acos(0.0)-va);
	y=d*sin(-ha)*cos(acos(0.0)-va);
	z=d*sin(acos(0.0)-va);
	Vector4f result(x, y, z, 1);
	return result;
}

float accuracy_measurements(int number_of_theodolites, std::vector<std::vector<TheodoliteMeasurement>> markers_data_structure, int number_of_markers)
{
	//Create point cloud	
	list<Matrix4f> pointclouds = {};
	for(int j = 0; j < number_of_theodolites; j++)
	{
		// Read points already taken
		list<Vector4f> points = {};
		for(int i = 0; i < number_of_markers; i++)
		{
			if(markers_data_structure[j][i].status!=255)
			{
				float meas_distance = markers_data_structure[j][i].meas_distance;     
				float azimuth = markers_data_structure[j][i].azimuth;
				float elevation = markers_data_structure[j][i].elevation;  
				points.push_back(give_points(meas_distance, azimuth, elevation));
			}
		}
		Matrix4f pointcloud(4, points.size());
		for (auto it = points.begin(); it != points.end(); ++it)
		{
			pointcloud.block<4,1>(0,it) = *it
		}
	}
	std::cout << "pointcloud: " << pointcloud << std::endl;

	//Point to point minimization
	list<float> inter_distance = {};
	Matrix4f Q = pointcloud.front();
	
	for (auto it = pointcloud.begin()+1; it != pointcloud.end(); ++it)
	{
		Matrix4f P = *it;
		Matrix4f T = ptp_minimization(P, Q);
		Matrix4f corrected_points = T*P;
		
		for(int i = 0; i < corrected_points.cols(); i++)
		{
			inter_distance.push_back((corrected_points.block<3,1>(0,i)-Q.block<3,1>(0,i)).norm());
		}
	}

	//Compute results (max inter-distance between corrected point cloud)
	float accuracy = std::max_element(inter_distance, inter_distance + inter_distance.size()-1);

	return accuracy;	
}

// #############################################
// #############################################
// Main program

int main(int argc, char **argv)
{   
    //ROS init
    ros::init(argc, argv, "theodolite_collect_calib_prisms");
    ros::NodeHandle n("~");
    //Publisher of the data in a vector
    n.getParam("show_data", show_data);

    //Configure LoRa antenna
    General_setup_lora();
    
    //general variables
    std::string tmp_string;
    enum State { INIT, SWITCH_THEODOLITES, WAIT_FOR_SWITCH_SUCCESS,COLLECT, COLLECT_MULTIPLE, COLLECT_DATA, WAIT_REPLY, SAVE, SWITCH_TO_TRACKING, WAIT_FOR_SWITCH2_SUCCESS, QUIT};
    enum TheodoliteState {UNKNOWN, COMMON_PRISM, PRIVATE_PRISM};

    std::vector<std::vector<TheodoliteMeasurement>> markers_data_structure;
    std::vector<TheodoliteState> theodolite_states;
    std::vector<int> theodolite_attempts;

    int number_of_theodolites = 0;
    int number_of_markers = 0;
    int theodolite_currently_talked_to = 0;
    int marker_currently_waited_for = 0;
    int prism_used_for_calibration = 1;

    std::chrono::steady_clock::time_point time_waiting_start;
    
    State s = INIT;

    //Interactively get all the markers
    while (ros::ok())
    {
        switch(s)
        {
            case INIT:
                std::cout << "How many theodolites do we have? "; 
                std::getline(std::cin, tmp_string);
                try{
                    number_of_theodolites = stoi(tmp_string);
                }                
                catch (exception& e){
                    if(std::cin.eof()){
                        std::cout << std::endl << "EOF received, shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }
                    std::cout << std::endl << "No no no, you have caused an exception in " << e.what() << ", c'mon..." << std::endl;
                    continue;
                }

                std::cout << "What is the prism number used for the calibration ? "; 
                std::getline(std::cin, tmp_string);
                try{
                    prism_used_for_calibration = stoi(tmp_string);
                }                
                catch (exception& e){
                    if(std::cin.eof()){
                        std::cout << std::endl << "EOF received, shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }
                    std::cout << std::endl << "No no no, you have caused an exception in " << e.what() << ", c'mon..." << std::endl;
                    continue;
                }

                std::cout << "How many prism poses do we have to do? "; 
                std::getline(std::cin, tmp_string);
                try{
                    number_of_markers = stoi(tmp_string);
                }                
                catch (exception& e){
                    if(std::cin.eof()){
                        std::cout << std::endl << "EOF received, shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }                    
                    std::cout << std::endl << "No no no, you have caused an exception in " << e.what() << ", c'mon..." << std::endl;
                    continue;
                }

                if(number_of_theodolites < 1 || number_of_markers < 1 || (prism_used_for_calibration < 1 && prism_used_for_calibration > 9)){
                    std::cout << std::endl << "Zero or minus number of theodolites or prism poses or prism number. C'mon... " << std::endl;
                    continue;
                }                

                markers_data_structure = std::vector<std::vector<TheodoliteMeasurement>>(number_of_theodolites, std::vector<TheodoliteMeasurement>(number_of_markers));
                theodolite_states = std::vector<TheodoliteState>(number_of_theodolites, UNKNOWN);
                theodolite_attempts = std::vector<int>(number_of_theodolites, 0);
                
                std::cout << "Memory reserved for the coordinates." << std::endl;
                print_marker_table(markers_data_structure);
                std::cout << std::endl;

                theodolite_currently_talked_to = 0;
                for (auto & theodolite_state : theodolite_states) {
                    if(theodolite_currently_talked_to+1 == prism_used_for_calibration){
                        theodolite_states[theodolite_currently_talked_to] = COMMON_PRISM;
                    }                  
                    theodolite_currently_talked_to++;                                       
                }
                                       
                s = SWITCH_THEODOLITES;
                //s = COLLECT;
            break;

            case SWITCH_THEODOLITES:
    
                theodolite_currently_talked_to = 0;
        
                for (auto & theodolite_state : theodolite_states) {
                    if(theodolite_state == UNKNOWN) break;                    
                    else theodolite_currently_talked_to++;                                       
                }
                
                if(theodolite_currently_talked_to == number_of_theodolites){
                    std::cout << "All theodolites in Direct Mode, let's go to the next step." << std::endl;
                    theodolite_currently_talked_to = 0; 
                    s = COLLECT;
                    continue;
                }else{    
                    std::cout << "Switching theodolite n." << theodolite_currently_talked_to+1 << " to Direct Mode." << std::endl;
                }
            
                Config_tx_mode();
                tmp_string = "n" + std::to_string(theodolite_currently_talked_to+1) + std::to_string(prism_used_for_calibration);
                std::cout << tmp_string << std::endl;                 
                txlora(tmp_string);
                Config_rx_mode();
                time_waiting_start = std::chrono::steady_clock::now();
                theodolite_attempts[theodolite_currently_talked_to] ++;
                std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " to reply." << std::endl;
                    
                s = WAIT_FOR_SWITCH_SUCCESS;
                
            break;

            case WAIT_FOR_SWITCH_SUCCESS:
                // Receive the message if there is one             
                Received_data_check();
                if(received_data){
                    if(received_nOk){
                        std::cout << "Success! Proceeding." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = COMMON_PRISM;
                        s = SWITCH_THEODOLITES;
                        continue;
                    }
                    if(received_nNo){
                        std::cout << "Theodolite reported error! Shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }
                else{
                        std::cout << "Received something, but not what we expected. Still waiting." << std::endl;
                        continue;
                    }
                }
                if(std::chrono::steady_clock::now() - time_waiting_start > std::chrono::milliseconds(TIME_BEFORE_NEXT_TX_ATTEMPT)){
                    std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " took longer than " << std::to_string(TIME_BEFORE_NEXT_TX_ATTEMPT/1000) << "s. ";
                    if(theodolite_attempts[theodolite_currently_talked_to] >= MAX_ATTEMPTS_BEFORE_SHUTDOWN){
                        std::cout << "Maximum number of attempts reached. Sorry, shutting down." << std::endl;
                        ros::shutdown();
                        continue;
                    }
                    std::cout << "Maybe packet lost. Will attempt again." << std::endl;
                    s = SWITCH_THEODOLITES;
                    continue;
                }
            break;
            
            case COLLECT:

								if(bad_status_error == true)
								{
										for(int j = 0; j < number_of_theodolites; j++){
												markers_data_structure[j][marker_currently_waited_for].status=255;        
										}
										bad_status_error = false;
										std::cout << "One theodolite was not able to target the prism. Direct measurement were not saved for this position. Check the setup !" << std::endl;
								}
			
                print_marker_table(markers_data_structure);
                std::cout << "to request a mesurement: d[x]. To exit CTRL+D." << std::endl;
                std::cout << "Input: ";
                
                std::getline(std::cin, tmp_string);
                if(std::cin.eof()){
                        std::cout << std::endl << "EOF received, saving and shutting down." << std::endl;
                        s = SAVE;                        
                        continue;
                }
                if(tmp_string.length() < 2) continue;

                if(tmp_string[0]=='d'){
                    try{
                        marker_currently_waited_for = stoi(tmp_string.substr(1, std::string::npos))-1;
                    }                
                    catch (exception& e){                  
                        std::cout << std::endl << "Invalid input." << std::endl;
                        continue;
                    }
                    if(marker_currently_waited_for < 0 || marker_currently_waited_for >= number_of_markers){                  
                        std::cout << std::endl << "Invalid prism pose." << std::endl;
                        continue;
                    }
                    std::cout << std::endl << "Requesting measurement of the prism" << marker_currently_waited_for+1 << std::endl;
                    theodolite_currently_talked_to=0; 
                    list_direct_measurement = {};
                    s = COLLECT_MULTIPLE;    
										iterator_bad_status_received = 0;
                }
                        
                continue;
            break;

            case COLLECT_MULTIPLE:

								//8 data in a raw taken
                if(list_direct_measurement.size()<=8){
                    s=COLLECT_DATA;
                    continue;
                }
                else{
                    for(auto it = list_direct_measurement.begin(); it!= list_direct_measurement.end(); ++it){
                        markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].status = 0;
                        markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].theodolite_number = theodolite_currently_talked_to+1;
                        markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].elevation += elevation;
                        markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].azimuth += azimuth;
                        markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].meas_distance += meas_distance;
                        markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].sec = secs;
                        markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].nsec = nsecs;
                    }
                    markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].elevation /= list_direct_measurement.size();
                    markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].azimuth /= list_direct_measurement.size();
                    markers_data_structure[theodolite_currently_talked_to][marker_currently_waited_for].meas_distance /= list_direct_measurement.size();
                    list_direct_measurement = {};
                    theodolite_currently_talked_to+=1;
										iterator_bad_status_received = 0;

                    if(theodolite_currently_talked_to == number_of_theodolites){
                        theodolite_currently_talked_to = 0;
												if(number_of_theodolites>1)
												{
													float accuracy = accuracy_measurements(number_of_theodolites, markers_data_structure, number_of_markers);
													std::cout << "Accuracy of the total measurements (max error inter distance in common frame): " << accuracy << "m" << std::endl;
													if(accuracy>0.01)
													{
														std::cout << "Measurements seems not good ! Should redo the last one or the first one !" << std::endl;
													}
												}
                        s = COLLECT;
                        break;
                    }else{    
                        s=COLLECT_MULTIPLE;
                        break;
                    }
                }
            break;

            case COLLECT_DATA:

                std::cout <<  list_direct_measurement.size() << std::endl;
                Config_tx_mode();
                tmp_string = "t" + std::to_string(theodolite_currently_talked_to+1);
                txlora(tmp_string);
                Config_rx_mode();
                time_waiting_start = std::chrono::steady_clock::now();
                std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " to reply with the measurement." << std::endl;
                s = WAIT_REPLY;
                continue;
            break;

            case WAIT_REPLY:
                   
                // Received the message if there is one
                Received_data_check();
                if(received_data){
                    if(received_measurement){
                        if(status!=0){
                            std::cout << "The theodolite responded with a non-zero status: " << (int)status << "which means an error. Check it." << std::endl;
														iterator_bad_status_received++;
														
														if(iterator_bad_status_received>10)
														{
																s = COLLECT;
																bad_status_error = true; 
																iterator_bad_status_received = 0;
																continue;
														}
                        }
                        else{
                            if(nsecs==former_nsecs){
                                std::cout << "The theodolite sent the same data." << std::endl;
                            }
                            else{
                                former_nsecs = nsecs;
                                TheodoliteMeasurement data_received;
                                data_received.status = status;
                                data_received.theodolite_number = theodolite_number;
                                data_received.elevation = elevation;
                                data_received.azimuth = azimuth;
                                data_received.meas_distance = meas_distance;
                                data_received.sec = secs;
                                data_received.nsec = nsecs;
                                list_direct_measurement.push_back(data_received);
                                std::cout << "Success! Storing the data for computation." << std::endl;
                            }
                        }                        
                        s = COLLECT_MULTIPLE;
                        continue;
                    }
                    else{
                        std::cout << "Received something, but not what we expected. Still waiting." << std::endl;
                        continue;
                    }
                }
                if(std::chrono::steady_clock::now() - time_waiting_start > std::chrono::milliseconds(TIME_BEFORE_NEXT_TX_ATTEMPT_COLLECT)){
                    std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " took longer than " << std::to_string(TIME_BEFORE_NEXT_TX_ATTEMPT_COLLECT/1000) << "s. ";
                    std::cout << "Maybe packet lost. Try again." << std::endl;
                    s = COLLECT_DATA;
                    continue;
                }
            
            break;

            case SAVE:
                {
                    ofstream output_file;
                    output_file.open("theodolite_reference_prisms.txt", ios::out | ios::trunc);
                    output_file << "theodolite_number , marker_number , status , elevation , azimuth , distance , sec , nsec" << std::endl;
                    for(int i = 0; i < number_of_theodolites; i++){
                        for(int j = 0; j < number_of_markers; j++){
                            output_file << i+1 << " , " << j+1 
                                << " , " << (int)markers_data_structure[i][j].status 
                                << " , " << markers_data_structure[i][j].elevation
                                << " , " << markers_data_structure[i][j].azimuth
                                << " , " << markers_data_structure[i][j].meas_distance
                                << " , " << markers_data_structure[i][j].sec
                                << " , " << markers_data_structure[i][j].nsec << std::endl;         
                        }
                    }
                    output_file.close();
                }
                theodolite_attempts = std::vector<int>(number_of_theodolites, 0);
                s = SWITCH_TO_TRACKING;
                continue;
            break;

            case SWITCH_TO_TRACKING:
                theodolite_currently_talked_to = 0;
        
                for (auto & theodolite_state : theodolite_states) {
                    if(theodolite_state == COMMON_PRISM) break;                    
                    else theodolite_currently_talked_to++;                                       
                }
                
                if(theodolite_currently_talked_to == number_of_theodolites){
                    std::cout << "All theodolites back in Tracking Mode or to be switched manually, we are done." << std::endl;
                    theodolite_currently_talked_to = 0; 
                    s = QUIT;
                    continue;
                }else{    
                    std::cout << "Switching theodolite n." << theodolite_currently_talked_to+1 << " to Tracking Mode." << std::endl;
                }
            
                Config_tx_mode();
                tmp_string = "n" + std::to_string(theodolite_currently_talked_to+1) + std::to_string(0);
                txlora(tmp_string);
                Config_rx_mode();
                time_waiting_start = std::chrono::steady_clock::now();
                theodolite_attempts[theodolite_currently_talked_to] ++;
                std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " to reply." << std::endl;
                    
                s = WAIT_FOR_SWITCH2_SUCCESS;

            break;

            case WAIT_FOR_SWITCH2_SUCCESS:
                // Receive the message if there is one             
                Received_data_check();
                if(received_data){
                    if(received_nOk){
                        std::cout << "Success! Proceeding." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = PRIVATE_PRISM;
                        s = SWITCH_TO_TRACKING;
                        continue;
                    }
                    if(received_nNo){
                        std::cout << "Theodolite " << theodolite_currently_talked_to << " reported error while switching to the tracking mode! Restart it manually." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = UNKNOWN;
                        continue;
                    }
                else{
                        std::cout << "Received something, but not what we expected. Still waiting." << std::endl;
                        continue;
                    }
                }
                if(std::chrono::steady_clock::now() - time_waiting_start > std::chrono::milliseconds(TIME_BEFORE_NEXT_TX_ATTEMPT)){
                    std::cout << "Waiting for theodolite n." << theodolite_currently_talked_to+1 << " took longer than " << std::to_string(TIME_BEFORE_NEXT_TX_ATTEMPT/1000) << "s. ";
                    if(theodolite_attempts[theodolite_currently_talked_to] >= MAX_ATTEMPTS_BEFORE_SHUTDOWN){
                        std::cout << "Maximum number of attempts to switch theo. " << theodolite_currently_talked_to+1 << " reached.. Do it manually." << std::endl;
                        theodolite_states[theodolite_currently_talked_to] = UNKNOWN;
                        continue;
                    }
                    std::cout << "Maybe packet lost. Will attempt again." << std::endl;
                    s = SWITCH_TO_TRACKING;
                    continue;
                }
                
            break;

            case QUIT:
                ros::shutdown();
                continue;
            break;
        }
        sleep(0.01);   
    }

    return 0;
}
