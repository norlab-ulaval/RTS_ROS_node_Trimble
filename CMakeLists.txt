cmake_minimum_required(VERSION 2.8.3)
project(theodolite_node)

set(LIBRARIES_FOLDER "/home/pi/catkin_ws/src/theodolite_node_ROS")

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES theodolite_node_ROS
  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

file(GLOB SOURCES "src/*.cpp" "src/*.h")
add_executable(theodolite_node ${SOURCES})

target_include_directories(theodolite_node PUBLIC
        ${catkin_INCLUDE_DIRS} 
        ${LIBRARIES_FOLDER}/include 
        ${LIBRARIES_FOLDER}/src 
        ${LIBRARIES_FOLDER}/include/asio 
        ${LIBRARIES_FOLDER}/include/asio/asio 
        ${LIBRARIES_FOLDER}/include/Common/Connection 
        ${LIBRARIES_FOLDER}/include/Trimble.Contracts/SpatialImaging 
        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.DriverManagement 
        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/Common 
        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/GNSS 
        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/Scanner 
        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/TotalStation 
        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/Vision)


file(GLOB LIBRARIES_SO "lib/*.so")
target_link_libraries(theodolite_node ${LIBRAIRIES_SO} ${catkin_LIBRARIES})











