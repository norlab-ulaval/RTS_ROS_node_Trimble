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

find_path(LIBUSB_INCLUDE_DIR
    NAMES libusb.h
    PATH "/usr/include/"
    PATH_SUFFIXES "include" "libusb" "libusb-1.0")

find_library(LIBUSB_LIBRARY
    NAMES usb   
    HITS "/usr/lib/" "/usr/lib64" "/usr/include/"
    PATH_SUFFIXES "lib" "lib32" "lib64")

link_libraries(${LIBUSB_LIBRARY})

message(${LIBUSB_INCLUDE_DIR})
message(${LIBUSB_LIBRARY})

#target_include_directories(theodolite_node PUBLIC
#        ${catkin_INCLUDE_DIRS} 
#        ${LIBRARIES_FOLDER}/include 
#        ${LIBRARIES_FOLDER}/src 
#        ${LIBRARIES_FOLDER}/include/asio 
#        ${LIBRARIES_FOLDER}/include/asio/asio 
#        ${LIBRARIES_FOLDER}/include/Common/Connection 
#        ${LIBRARIES_FOLDER}/include/Trimble.Contracts/SpatialImaging 
#        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.DriverManagement 
#        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/Common 
#        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/GNSS 
#        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/Scanner 
#        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/TotalStation 
#        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/Vision)

file(GLOB LIBRARIES_SO "lib/*.so")
set(PROJECT_LIBRARY_LINK ${LIBRARIES_SO})
link_libraries(${LIBRARIES_FOLDER}/lib)

include_directories(${catkin_INCLUDE_DIRS}
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
        ${LIBRARIES_FOLDER}/include/Trimble.Ssi.Interfaces/Vision
        ${LIBUSB_INCLUDE_DIR})

file(GLOB SOURCES "src/*.cpp" "src/*.h")
add_executable(theodolite_node ${SOURCES})
#add_executable(theodolite_node src/theodolite_node.cpp)

#target_include_directories(theodolite_node ${LIBUSB_INCLUDE_DIR})

target_link_libraries(theodolite_node 
        ${catkin_LIBRARIES} 
        ${PROJECT_LIBRARY_LINK}
        ${LIBUSB_LIBRARY})











