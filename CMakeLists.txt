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

if(LIBUSB_1_LIBRARIES AND LIBUSB_1_INCLUDE_DIRS)
    set(LIBUSB_FOUND TRUE)
else(LIBUSB_1_LIBRARIES AND LIBUSB_1_INCLUDE_DIRS)
    find_path(LIBUSB_1_INCLUDE_DIR
        NAMES
	    libusb.h
        PATHS
          /usr/include
          /usr/local/include
          /opt/local/include
          /sw/include
	    PATH_SUFFIXES
	      libusb-1.0
    )

    find_library(LIBUSB_1_LIBRARY
        NAMES
          usb-1.0 usb
        PATHS
          /usr/lib
          /usr/local/lib
          /opt/local/lib
          /sw/lib
    )

    set(LIBUSB_1_INCLUDE_DIRS
        ${LIBUSB_1_INCLUDE_DIR}
    )
    set(LIBUSB_1_LIBRARIES
        ${LIBUSB_1_LIBRARY}
    )

    if(LIBUSB_1_INCLUDE_DIRS AND LIBUSB_1_LIBRARIES)
        set(LIBUSB_1_FOUND TRUE)
    endif(LIBUSB_1_INCLUDE_DIRS AND LIBUSB_1_LIBRARIES)

    if (LIBUSB_1_FOUND)
        if (NOT libusb_1_FIND_QUIETLY)
            message(STATUS "Found libusb-1.0:")
	        message(STATUS " - Includes: ${LIBUSB_1_INCLUDE_DIRS}")
	        message(STATUS " - Libraries: ${LIBUSB_1_LIBRARIES}")
        endif (NOT libusb_1_FIND_QUIETLY)
    else (LIBUSB_1_FOUND)
        if (libusb_1_FIND_REQUIRED)
        message(FATAL_ERROR "Could not find libusb")
        endif (libusb_1_FIND_REQUIRED)
    endif (LIBUSB_1_FOUND)

endif (LIBUSB_1_LIBRARIES AND LIBUSB_1_INCLUDE_DIRS)

file(GLOB LIBRARIES_SO "lib/*.so")
set(PROJECT_LIBRARY_LINK ${LIBRARIES_SO})

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
        ${LIBUSB_1_INCLUDE_DIR}
        )

file(GLOB SOURCES "src/*.cpp" "src/*.h")
add_executable(theodolite_node ${SOURCES})

target_link_libraries(theodolite_node 
        ${catkin_LIBRARIES} 
        ${PROJECT_LIBRARY_LINK}
        ${LIBUSB_1_LIBRARY}
        )











