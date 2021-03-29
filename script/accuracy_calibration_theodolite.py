import numpy as np
import math
from numpy import linalg
import sys
import rosbag

# Function to return a point according to the data of the theodolite as array
# Input:
# - d: distance in meter
# - ha: horizontale angle
# - va: verticale angle
# - param: 1 use angle in degrees, param: 2 use angle in radians
# Ouput: 4x1 array with the 3D coordinates according to the data
def give_points(d, ha, va, param):
	d = d + 0.01 # add 10mm because measurments done by raspi
	if(param ==1):
		x=d*math.cos((-ha)*np.pi/180)*math.cos((90-va)*np.pi/180)
		y=d*math.sin((-ha)*np.pi/180)*math.cos((90-va)*np.pi/180)
		z=d*math.sin((90-va)*np.pi/180)
	if(param ==2):
		x=d*math.cos(-ha)*math.cos(np.pi/2-va)
		y=d*math.sin(-ha)*math.cos(np.pi/2-va)
		z=d*math.sin(np.pi/2-va)
	return np.array([x, y, z, 1],dtype=np.float64)

# Function to add a point in a list of array according to the data of the theodolite 
# Input:
# - d: distance in meter
# - ha: horizontale angle
# - va: verticale angle
# - points: list of points which the result point will be add
# - param: 1 use angle in degrees, param: 2 use angle in radians
def add_point(d, ha, va, points, param):
	points.append(give_points(d, ha, va, param))

# Function which found the tf transform between two point clouds using point-to-point minimization, 
# where the matching was already done (mean each index of the point cloud for the reading and reference array match)
# Input:
# - P: the reading point cloud, can be 4xn or 3xn where n is the number of points
# - Q: the reference point cloud, can be 4xn or 3xn where n is the number of points
# Output: T a 4x4 pose matrix corresponding to the rigid transformation 
def point_to_point_minimization(P, Q):
	# Errors at the beginning
	errors_before = Q - P
	# Centroide of each pointcloud
	mu_p = np.mean(P[0:3,:],axis=1)
	mu_q = np.mean(Q[0:3,:], axis=1)
	# Center each pointcloud
	P_mu = np.ones((3, P.shape[1]))    
	Q_mu = np.ones((3, Q.shape[1])) 
	for i in range(0,P_mu.shape[1]):
		P_mu[0:3,i] = P[0:3,i] - mu_p
	for i in range(0,Q_mu.shape[1]):
		Q_mu[0:3,i] = Q[0:3,i] - mu_q
	# Compute cross covariance matrix
	H = P_mu@Q_mu.T
	# Use SVD decomposition
	U, s, V = np.linalg.svd(H)
	# Compute rotation
	R = V.T@U.T
	if(np.linalg.det(R)<0):
		#print(V.T)
		V_t = V.T
		V_t[:,2] = -V_t[:,2]
		R = V_t@U.T

	# Compute translation
	t = mu_q - R@mu_p
	# Compute rigid transformation obtained
	T = np.eye(4)
	T[0:3,0:3]=R
	T[0:3,3] = t
	return T

def calculate_distance(trimble_1, trimble_2, trimble_3, compteur):
	distance = []
	for i in range(0, compteur):
		distance.append(np.linalg.norm(trimble_1[0:3,i]-trimble_2[0:3,i]))
		distance.append(np.linalg.norm(trimble_1[0:3,i]-trimble_3[0:3,i]))
		distance.append(np.linalg.norm(trimble_2[0:3,i]-trimble_3[0:3,i]))
	return distance

# Function to read a text file which contains the marker data for the calibration. The result given
# will be the different markers positions in one theodolite frame
# Input:
# - file_name: name of the file to read (the file should have the same structure than the usual one use by the raspi)
# - theodolite_reference_frame: number which indicates the frame where the markers positions will be
# Output: 
# - trimble_1: list of array markers points coordinates of the theodolite 1, in the frame chosen
# - trimble_2: list of array markers points coordinates of the theodolite 2, in the frame chosen
# - trimble_3: list of array markers points coordinates of the theodolite 3, in the frame chosen
# - T_.1: 4x4 rigid transform obtain according to the point-to-point minimization between the chosen frame and the theodolite 1 frame (Identity matrix if frame 1 chosen)
# - T_.2: 4x4 rigid transform obtain according to the point-to-point minimization between the chosen frame and the theodolite 2 frame (Identity matrix if frame 2 chosen)
# - T_.3: 4x4 rigid transform obtain according to the point-to-point minimization between the chosen frame and the theodolite 3 frame (Identity matrix if frame 3 chosen) 
def read_marker_file(file_name):
	Points_t1_rasp = []
	Points_t2_rasp = []
	Points_t3_rasp = []
	T_I = np.identity(4)
	compteur = 0

	# Read text file
	file = open(file_name, "r")
	line = file.readline()
	line = file.readline()
	while line:
		item = line.split(",")
		if(int(item[0])==1 and int(item[2])==0):
			add_point(float(item[5]),float(item[4]),float(item[3]),Points_t1_rasp, 2)
		if(int(item[0])==2 and int(item[2])==0):
			add_point(float(item[5]),float(item[4]),float(item[3]),Points_t2_rasp, 2)
		if(int(item[0])==3 and int(item[2])==0):
			add_point(float(item[5]),float(item[4]),float(item[3]),Points_t3_rasp, 2)
		line = file.readline()
		compteur = compteur +1
	file.close()
	compteur = int(compteur/3)
	print("Read", compteur, "marker positions !")

	# Array of points
	Points_t1_rasp_arr = np.array(Points_t1_rasp).T
	Points_t2_rasp_arr = np.array(Points_t2_rasp).T
	Points_t3_rasp_arr = np.array(Points_t3_rasp).T
	
	# Ptp minimization
	T_12_rasp = point_to_point_minimization(Points_t2_rasp_arr, Points_t1_rasp_arr)
	T_13_rasp = point_to_point_minimization(Points_t3_rasp_arr, Points_t1_rasp_arr)
	trimble_1 = Points_t1_rasp_arr
	trimble_2 = T_12_rasp@Points_t2_rasp_arr
	trimble_3 = T_13_rasp@Points_t3_rasp_arr

	distance = calculate_distance(trimble_1, trimble_2, trimble_3, compteur)

	print("Accuracy of measurements:")
	print("Mean: ", round(np.mean(distance),4)*1000, "mm , Std: ", round(np.std(distance),4)*1000, "mm , Max error: ", round(np.max(distance),4)*1000, "mm")
	if(round(np.max(distance),4)*1000>10):
		print("Measurement are not accurate enough ! Search of the bad measurements...")
		t1_list = []
		t2_list = []
		t3_list = []
		for i in range(2, compteur):
			t1_list.append(Points_t1_rasp_arr[:,0:i])
			t2_list.append(Points_t2_rasp_arr[:,0:i])
			t3_list.append(Points_t3_rasp_arr[:,0:i])

		max_distance = []
		for i,j,k in zip(t1_list, t2_list, t3_list):
			T_12_rasp = point_to_point_minimization(j, i)
			T_13_rasp = point_to_point_minimization(k, i)
			trimble_1 = i
			trimble_2 = T_12_rasp@j
			trimble_3 = T_13_rasp@k
			distance = calculate_distance(trimble_1, trimble_2, trimble_3, i.shape[1])
			max_distance.append(round(np.max(distance),4)*1000)

		if(np.max(max_distance)>10):
			T_12_rasp = point_to_point_minimization(Points_t2_rasp_arr[:,1:-1], Points_t1_rasp_arr[:,1:-1])
			T_13_rasp = point_to_point_minimization(Points_t3_rasp_arr[:,1:-1], Points_t1_rasp_arr[:,1:-1])
			trimble_1 = Points_t1_rasp_arr[:,1:-1]
			trimble_2 = T_12_rasp@Points_t2_rasp_arr[:,1:-1]
			trimble_3 = T_13_rasp@Points_t3_rasp_arr[:,1:-1]
			distance = calculate_distance(trimble_1, trimble_2, trimble_3, trimble_1.shape[1])

			if(round(np.max(distance),4)*1000<10):
				print("Measurement number 1 was bad. The new accuracy of the measurements without it is:")
				print("Mean: ", round(np.mean(distance),4)*1000, "mm , Std: ", round(np.std(distance),4)*1000, "mm , Max error: ", round(np.max(distance),4)*1000, "mm")
			else:
				t1 = np.zeros((4, compteur-1))
				t2 = np.zeros((4, compteur-1))
				t3 = np.zeros((4, compteur-1))
				t1[:,0] = Points_t1_rasp_arr[:,1]
				t1[:,1:-1] = Points_t1_rasp_arr[:,2:-1]
				t2[:,0] = Points_t2_rasp_arr[:,1]
				t2[:,1:-1] = Points_t2_rasp_arr[:,2:-1]				
				t3[:,0] = Points_t3_rasp_arr[:,1]
				t3[:,1:-1] = Points_t3_rasp_arr[:,2:-1]
	
				T_12_rasp = point_to_point_minimization(t2, t1)
				T_13_rasp = point_to_point_minimization(t3, t1)
				trimble_1 = t1
				trimble_2 = T_12_rasp@t2
				trimble_3 = T_13_rasp@t3
				distance = calculate_distance(trimble_1, trimble_2, trimble_3, trimble_1.shape[1])

				if(round(np.max(distance),4)*1000<10):
					print("Measurement number 2 was bad. The new accuracy of the measurements without it is:")
					print("Mean: ", round(np.mean(distance),4)*1000, "mm , Std: ", round(np.std(distance),4)*1000, "mm , Max error: ", round(np.max(distance),4)*1000, "mm")
				else:
					print("One or many marker measurments are not accurate enough. Please redo them !")
	
if __name__ == "__main__":
	file_name = str(sys.argv[1])
	read_marker_file(file_name)


