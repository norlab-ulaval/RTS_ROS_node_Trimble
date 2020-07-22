#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64MultiArray.h"

#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>
#include <signal.h>
#include <stdlib.h>

#include <sys/ioctl.h>

#include <wiringPi.h>
#include <wiringPiSPI.h>

using namespace std;

// #############################################
// #############################################

#define REG_FIFO                    0x00
#define REG_OPMODE                  0x01
#define REG_FIFO_ADDR_PTR           0x0D
#define REG_FIFO_TX_BASE_AD         0x0E
#define REG_FIFO_RX_BASE_AD         0x0F
#define REG_RX_NB_BYTES             0x13
#define REG_FIFO_RX_CURRENT_ADDR    0x10
#define REG_IRQ_FLAGS               0x12
#define REG_DIO_MAPPING_1           0x40
#define REG_DIO_MAPPING_2           0x41
#define REG_MODEM_CONFIG            0x1D
#define REG_MODEM_CONFIG2           0x1E
#define REG_MODEM_CONFIG3           0x26
#define REG_SYMB_TIMEOUT_LSB  		0x1F
#define REG_PKT_SNR_VALUE			0x19
#define REG_PAYLOAD_LENGTH          0x22
#define REG_IRQ_FLAGS_MASK          0x11
#define REG_MAX_PAYLOAD_LENGTH 		0x23
#define REG_HOP_PERIOD              0x24
#define REG_SYNC_WORD				0x39
#define REG_VERSION	  				0x42

#define PAYLOAD_LENGTH              0x40

// LOW NOISE AMPLIFIER
#define REG_LNA                     0x0C
#define LNA_MAX_GAIN                0x23
#define LNA_OFF_GAIN                0x00
#define LNA_LOW_GAIN		    	0x20

#define RegDioMapping1                             0x40 // common
#define RegDioMapping2                             0x41 // common

#define RegPaConfig                                0x09 // common
#define RegPaRamp                                  0x0A // common
#define RegPaDac                                   0x5A // common

#define SX72_MC2_FSK                0x00
#define SX72_MC2_SF7                0x70
#define SX72_MC2_SF8                0x80
#define SX72_MC2_SF9                0x90
#define SX72_MC2_SF10               0xA0
#define SX72_MC2_SF11               0xB0
#define SX72_MC2_SF12               0xC0

#define SX72_MC1_LOW_DATA_RATE_OPTIMIZE  0x01 // mandated for SF11 and SF12

// sx1276 RegModemConfig1
#define SX1276_MC1_BW_125                0x70
#define SX1276_MC1_BW_250                0x80
#define SX1276_MC1_BW_500                0x90
#define SX1276_MC1_CR_4_5            0x02
#define SX1276_MC1_CR_4_6            0x04
#define SX1276_MC1_CR_4_7            0x06
#define SX1276_MC1_CR_4_8            0x08

#define SX1276_MC1_IMPLICIT_HEADER_MODE_ON    0x01

// sx1276 RegModemConfig2
#define SX1276_MC2_RX_PAYLOAD_CRCON        0x04

// sx1276 RegModemConfig3
#define SX1276_MC3_LOW_DATA_RATE_OPTIMIZE  0x08
#define SX1276_MC3_AGCAUTO                 0x04

// preamble for lora networks (nibbles swapped)
#define LORA_MAC_PREAMBLE                  0x34

#define RXLORA_RXMODE_RSSI_REG_MODEM_CONFIG1 0x0A
#ifdef LMIC_SX1276
#define RXLORA_RXMODE_RSSI_REG_MODEM_CONFIG2 0x70
#elif LMIC_SX1272
#define RXLORA_RXMODE_RSSI_REG_MODEM_CONFIG2 0x74
#endif

// FRF
#define        REG_FRF_MSB              0x06
#define        REG_FRF_MID              0x07
#define        REG_FRF_LSB              0x08

#define        FRF_MSB                  0xD9 // 868.1 Mhz
#define        FRF_MID                  0x06
#define        FRF_LSB                  0x66

// ----------------------------------------
// Constants for radio registers
#define OPMODE_LORA      0x80
#define OPMODE_MASK      0x07
#define OPMODE_SLEEP     0x00
#define OPMODE_STANDBY   0x01
#define OPMODE_FSTX      0x02
#define OPMODE_TX        0x03
#define OPMODE_FSRX      0x04
#define OPMODE_RX        0x05
#define OPMODE_RX_SINGLE 0x06
#define OPMODE_CAD       0x07

// ----------------------------------------
// Bits masking the corresponding IRQs from the radio
#define IRQ_LORA_RXTOUT_MASK 0x80
#define IRQ_LORA_RXDONE_MASK 0x40
#define IRQ_LORA_CRCERR_MASK 0x20
#define IRQ_LORA_HEADER_MASK 0x10
#define IRQ_LORA_TXDONE_MASK 0x08
#define IRQ_LORA_CDDONE_MASK 0x04
#define IRQ_LORA_FHSSCH_MASK 0x02
#define IRQ_LORA_CDDETD_MASK 0x01

// DIO function mappings                D0D1D2D3
#define MAP_DIO0_LORA_RXDONE   0x00  // 00------
#define MAP_DIO0_LORA_TXDONE   0x40  // 01------
#define MAP_DIO1_LORA_RXTOUT   0x00  // --00----
#define MAP_DIO1_LORA_NOP      0x30  // --11----
#define MAP_DIO2_LORA_NOP      0xC0  // ----11--

// #############################################
// #############################################
//

//Define some type for LoRa antenna function
typedef bool boolean;
typedef unsigned char byte;
//Channel of communication
static const int CHANNEL = 0;
//Variable to receive the message transmitted
char message[256];
byte receivedbytes;
//Option set for LoRa antenna
bool sx1272 = true;
//Different types of configuration for antenna
enum sf_t { SF7=7, SF8, SF9, SF10, SF11, SF12 };
// SX1272 - Raspberry connections
int ssPin = 6;
int dio0  = 7;
int RST   = 0;
// Set spreading factor (SF7 - SF12)
sf_t sf = SF7;
// Set center frequency
uint32_t  freq = 868100000; // in Mhz! (868.1)
//Vector which will publish the data
std::vector<double> vec_data{0,0,0,0,0,0,0};
//Option selected in launchfile
bool show_data = false;  //Option to see data on terminal when received
int rate = 30;  //Rate of listener in Hz
int number_of_theodolite = 3; //Number of theodolite used

// #############################################
// #############################################
// Function for LoRa antenna

void die(const char *s)
{
    perror(s);
    exit(1);
}

void selectreceiver()
{
    digitalWrite(ssPin, LOW);
}

void unselectreceiver()
{
    digitalWrite(ssPin, HIGH);
}

byte readReg(byte addr)
{
    unsigned char spibuf[2];

    selectreceiver();
    spibuf[0] = addr & 0x7F;
    spibuf[1] = 0x00;
    wiringPiSPIDataRW(CHANNEL, spibuf, 2);
    unselectreceiver();

    return spibuf[1];
}

void writeReg(byte addr, byte value)
{
    unsigned char spibuf[2];

    spibuf[0] = addr | 0x80;
    spibuf[1] = value;
    selectreceiver();
    wiringPiSPIDataRW(CHANNEL, spibuf, 2);

    unselectreceiver();
}

static void opmode (uint8_t mode) {
    writeReg(REG_OPMODE, (readReg(REG_OPMODE) & ~OPMODE_MASK) | mode);
}

static void opmodeLora() {
    uint8_t u = OPMODE_LORA;
    if (sx1272 == false)
        u |= 0x8;   // TBD: sx1276 high freq
    writeReg(REG_OPMODE, u);
}


void SetupLoRa()
{
    
    digitalWrite(RST, HIGH);
    delay(100);
    digitalWrite(RST, LOW);
    delay(100);

    byte version = readReg(REG_VERSION);

    if (version == 0x22) {
        // sx1272
        printf("SX1272 detected, starting.\n");
        sx1272 = true;
    } else {
        // sx1276?
        digitalWrite(RST, LOW);
        delay(100);
        digitalWrite(RST, HIGH);
        delay(100);
        version = readReg(REG_VERSION);
        if (version == 0x12) {
            // sx1276
            printf("SX1276 detected, starting.\n");
            sx1272 = false;
        } else {
            printf("Unrecognized transceiver.\n");
            //printf("Version: 0x%x\n",version);
            exit(1);
        }
    }

    opmode(OPMODE_SLEEP);

    // set frequency
    uint64_t frf = ((uint64_t)freq << 19) / 32000000;
    writeReg(REG_FRF_MSB, (uint8_t)(frf>>16) );
    writeReg(REG_FRF_MID, (uint8_t)(frf>> 8) );
    writeReg(REG_FRF_LSB, (uint8_t)(frf>> 0) );

    writeReg(REG_SYNC_WORD, 0x34); // LoRaWAN public sync word

    if (sx1272) {
        if (sf == SF11 || sf == SF12) {
            writeReg(REG_MODEM_CONFIG,0x0B);
        } else {
            writeReg(REG_MODEM_CONFIG,0x0A);
        }
        writeReg(REG_MODEM_CONFIG2,(sf<<4) | 0x04);
    } else {
        if (sf == SF11 || sf == SF12) {
            writeReg(REG_MODEM_CONFIG3,0x0C);
        } else {
            writeReg(REG_MODEM_CONFIG3,0x04);
        }
        writeReg(REG_MODEM_CONFIG,0x72);
        writeReg(REG_MODEM_CONFIG2,(sf<<4) | 0x04);
    }

    if (sf == SF10 || sf == SF11 || sf == SF12) {
        writeReg(REG_SYMB_TIMEOUT_LSB,0x05);
    } else {
        writeReg(REG_SYMB_TIMEOUT_LSB,0x08);
    }
    writeReg(REG_MAX_PAYLOAD_LENGTH,0x80);
    writeReg(REG_PAYLOAD_LENGTH,PAYLOAD_LENGTH);
    writeReg(REG_HOP_PERIOD,0xFF);
    writeReg(REG_FIFO_ADDR_PTR, readReg(REG_FIFO_RX_BASE_AD));

    writeReg(REG_LNA, LNA_MAX_GAIN);

}

boolean receive(char *payload) {
    // clear rxDone
    writeReg(REG_IRQ_FLAGS, 0x40);

    int irqflags = readReg(REG_IRQ_FLAGS);

    //  payload crc: 0x20
    if((irqflags & 0x20) == 0x20)
    {
        printf("CRC error\n");
        writeReg(REG_IRQ_FLAGS, 0x20);
        return false;
    } else {

        byte currentAddr = readReg(REG_FIFO_RX_CURRENT_ADDR);
        byte receivedCount = readReg(REG_RX_NB_BYTES);
        receivedbytes = receivedCount;

        writeReg(REG_FIFO_ADDR_PTR, currentAddr);

        for(int i = 0; i < receivedCount; i++)
        {
            payload[i] = (char)readReg(REG_FIFO);
        }
    }
    return true;
}

void receivepacket(ros::NodeHandle n, ros::Publisher data_pub) {

    long int SNR;
    int rssicorr;

    if(digitalRead(dio0) == 1)
    {
        if(receive(message)) {
            byte value = readReg(REG_PKT_SNR_VALUE);
            if( value & 0x80 ) // The SNR sign bit is 1
            {
                // Invert and divide by 4
                value = ( ( ~value + 1 ) & 0xFF ) >> 2;
                SNR = -value;
            }
            else
            {
                // Divide by 4
                SNR = ( value & 0xFF ) >> 2;
            }
            
            if (sx1272) {
                rssicorr = 139;
            } else {
                rssicorr = 157;
            }

            if(show_data)
            {
                printf("Packet RSSI: %d, ", readReg(0x1A)-rssicorr);
                printf("RSSI: %d, ", readReg(0x1B)-rssicorr);
                printf("SNR: %li, ", SNR);
                printf("Length: %i", (int)receivedbytes);
                printf("\n");
                printf("Payload: %s\n", message);   
            } 

            if((int)receivedbytes > 1)
            {

              //Convert char* to value desired
              //First theodolite number
              vec_data[0] = (int) message[0] - 48;
              //Second number target
              vec_data[1] = (int) message[2] - 48;

              //Obtain horizontal angle
              int new_iterator = 4;
              int old_iterator = 4;
              while(message[new_iterator]!=';')
              {
                  new_iterator+=1;
              }
              char* HA_char = new char[new_iterator-old_iterator];
              for(int i=0; i<new_iterator-old_iterator; i++)
              {
                  HA_char[i]= (char)message[i+old_iterator];
              }
              vec_data[2] = atof(HA_char);

              //Obtain vertical angle
              new_iterator += 1;
              old_iterator = new_iterator;
              while(message[new_iterator]!=';')
              {
                  new_iterator+=1;
              }
              char* VA_char = new char[new_iterator-old_iterator];
              for(int i=0; i<new_iterator-old_iterator; i++)
              {
                  VA_char[i]= (char)message[i+old_iterator];
              }
              vec_data[3] = atof(VA_char);

              //Obtain distance
              new_iterator += 1;
              old_iterator = new_iterator;
              while(message[new_iterator]!=';')
              {
                  new_iterator+=1;
              }
              char* dist_char = new char[new_iterator-old_iterator];
              for(int i=0; i<new_iterator-old_iterator; i++)
              {
                  dist_char[i]= (char)message[i+old_iterator];
              }
              vec_data[4] = atof(dist_char);

              //Obtain time of data
              new_iterator += 1;
              old_iterator = new_iterator;
              while(message[new_iterator]!=';')
              {
                  new_iterator+=1;
              }
              char* time_char = new char[new_iterator-old_iterator];
              for(int i=0; i<new_iterator-old_iterator; i++)
              {
                  time_char[i]= (char)message[i+old_iterator];
              }
              vec_data[5] = atof(time_char);

              //Finally obtain the error flag
              vec_data[6] = (int) message[new_iterator+1] - 48;
              
              std_msgs::Float64MultiArray msg;
              msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
              msg.layout.dim[0].size = 7;
              msg.layout.dim[0].stride=1;

              vector<double>::const_iterator itr, end(vec_data.end());
              for(itr = vec_data.begin(); itr!=end; ++itr) {
                  msg.data.push_back(*itr);
              }

              if(show_data)
              {
                  ROS_INFO("theodolite: %f \n target: %f \n HA: %f \n VA: %f \n Distance: %f \n Time: %f \n Error: %f \n", vec_data[0], vec_data[1], vec_data[2], vec_data[3], vec_data[4], vec_data[5], vec_data[6]);
              }

              data_pub.publish(msg);  
            }         

        } // received a message

    } // dio0=1
}

static void configPower (int8_t pw) {
    if (sx1272 == false) {
        // no boost used for now
        if(pw >= 17) {
            pw = 15;
        } else if(pw < 2) {
            pw = 2;
        }
        // check board type for BOOST pin
        writeReg(RegPaConfig, (uint8_t)(0x80|(pw&0xf)));
        writeReg(RegPaDac, readReg(RegPaDac)|0x4);

    } else {
        // set PA config (2-17 dBm using PA_BOOST)
        if(pw > 17) {
            pw = 17;
        } else if(pw < 2) {
            pw = 2;
        }
        writeReg(RegPaConfig, (uint8_t)(0x80|(pw-2)));
    }
}


static void writeBuf(byte addr, byte *value, byte len) {                                                       
    unsigned char spibuf[256];                                                                          
    spibuf[0] = addr | 0x80;                                                                            
    for (int i = 0; i < len; i++) {                                                                         
        spibuf[i + 1] = value[i];                                                                       
    }                                                                                                   
    selectreceiver();                                                                                   
    wiringPiSPIDataRW(CHANNEL, spibuf, len + 1);                                                        
    unselectreceiver();                                                                                 
}

void txlora(byte *frame, byte datalen) {

    // set the IRQ mapping DIO0=TxDone DIO1=NOP DIO2=NOP
    writeReg(RegDioMapping1, MAP_DIO0_LORA_TXDONE|MAP_DIO1_LORA_NOP|MAP_DIO2_LORA_NOP);
    // clear all radio IRQ flags
    writeReg(REG_IRQ_FLAGS, 0xFF);
    // mask all IRQs but TxDone
    writeReg(REG_IRQ_FLAGS_MASK, ~IRQ_LORA_TXDONE_MASK);

    // initialize the payload size and address pointers
    writeReg(REG_FIFO_TX_BASE_AD, 0x00);
    writeReg(REG_FIFO_ADDR_PTR, 0x00);
    writeReg(REG_PAYLOAD_LENGTH, datalen);

    // download buffer to the radio FIFO
    writeBuf(REG_FIFO, frame, datalen);
    // now we actually start the transmission
    opmode(OPMODE_TX);

    printf("send: %s\n", frame);
}


// #############################################
// #############################################
// Main program

int main(int argc, char **argv)
{
    //ROS init
    ros::init(argc, argv, "theodolite_listener");
    ros::NodeHandle n;
    //Publisher of the data in a vector
    ros::Publisher data_pub = n.advertise<std_msgs::Float64MultiArray>("theodolite_data", 1000);
    n.getParam("/theodolite_listener/rate", rate);
    //Set the rate of the listener
    if(rate >100 or rate<1)
    {
        printf("Error in rate setting! Should be between 1 and 100Hz. Defaut rate of 30Hz is applying! \n");
        rate = 30;
    }
    ros::Rate loop_rate(rate);
    //Get number of theodolite involved
    n.getParam("/theodolite_listener/number_of_theodolite", number_of_theodolite);

    //Configure LoRa antenna
    wiringPiSetup () ;
    pinMode(ssPin, OUTPUT);
    pinMode(dio0, INPUT);
    pinMode(RST, OUTPUT);
    wiringPiSPISetup(CHANNEL, 500000);
    SetupLoRa();

    // radio init
    opmodeLora();
    opmode(OPMODE_STANDBY);
    opmode(OPMODE_RX);
    printf("Listening at SF%i on %.6lf Mhz.\n", sf,(double)freq/1000000);
    printf("------------------\n");

    //Iterator to call theodolite
    int iterator_theodolite =0;

    //Listen messages sent
    while (ros::ok())
    {
        //Ask a theodolite its data
        opmodeLora();
        opmode(OPMODE_STANDBY);
        opmode(OPMODE_TX);

        std::string data = "data;" + std::to_string(iterator_theodolite);
        unsigned char *send_message = new unsigned char[data.length()+1];
        strcpy((char *)send_message,data.c_str());
         
        if (argc > 2)
          strncpy((char *)send_message, argv[2], sizeof(send_message));

        txlora(send_message, strlen((char *)send_message));

        loop_rate.sleep();

        //Check if something arrived
        opmodeLora();
        opmode(OPMODE_STANDBY);
        opmode(OPMODE_RX);

        receivepacket(n, data_pub); 

        iterator_theodolite++;
        if(iterator_theodolite == number_of_theodolite-1)
        {
          iterator_theodolite=0;
        }
        
        ros::spinOnce();
        
    }


    return 0;
}
