cmake_minimum_required(VERSION 2.8.3)
project(theodolite_node)

set(LIBRARIES_FOLDER "/home/pi/catkin_ws/src/theodolite_node_ROS")

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  roslaunch
  message_generation
  theodolite_node_msgs
)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES theodolite_node_ROS
  CATKIN_DEPENDS roscpp rospy std_msgs message_runtime theodolite_node_msgs
#  DEPENDS system_lib
)

roslaunch_add_file_check(launch)

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

if(WIRINGPI_LIBRARIES AND WIRINGPI_INCLUDE_DIRS)
    set(WIRINGPI_FOUND TRUE)
else(WIRINGPI_LIBRARIES AND WIRINGPI_INCLUDE_DIRS)
    find_path(WIRINGPI_INCLUDE_DIR
        NAMES
	    wiringPi.h
        PATHS
          /usr/include
          /usr/local/include
          /opt/local/include
          /sw/include
	    PATH_SUFFIXES
	      wiringPi
    )

    find_library(WIRINGPI_LIBRARY
        NAMES
          wiringPi
        PATHS
          /usr/lib
          /usr/local/lib
          /opt/local/lib
          /sw/lib
    )

    set(WIRINGPI_INCLUDE_DIRS
        ${WIRINGPI_INCLUDE_DIR}
    )
    set(WIRINGPI_LIBRARIES
        ${WIRINGPI_LIBRARY}
    )

    if(WIRINGPI_INCLUDE_DIRS AND WIRINGPI_LIBRARIES)
        set(WIRINGPI_FOUND TRUE)
    endif(WIRINGPI_INCLUDE_DIRS AND WIRINGPI_LIBRARIES)

    if (WIRINGPI_FOUND)
        if (NOT wiringpi_FIND_QUIETLY)
            message(STATUS "Found wiringPi:")
	        message(STATUS " - Includes: ${WIRINGPI_INCLUDE_DIRS}")
	        message(STATUS " - Libraries: ${WIRINGPI_LIBRARIES}")
        endif (NOT wiringpi_FIND_QUIETLY)
    else (WIRINGPI_FOUND)
        if (wiringpi_FIND_REQUIRED)
        message(FATAL_ERROR "Could not find libusb")
        endif (wiringpi_FIND_REQUIRED)
    endif (WIRINGPI_FOUND)

endif (WIRINGPI_LIBRARIES AND WIRINGPI_INCLUDE_DIRS)

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
        ${WIRINGPI_INCLUDE_DIRS}
        )

file(GLOB SOURCES "src/Obs*" "src/Ssi*" "src/TCP*" "src/USB*" "src/Video*")
#add_executable(theodolite_node ${SOURCES})

add_executable(theodolite_master src/theodolite_master.cpp src/lora_radio.cpp src/radio_message_serialize.cpp)
add_dependencies(theodolite_master ${catkin_EXPORTED_TARGETS})
target_link_libraries(theodolite_master 
        ${catkin_LIBRARIES} 
        ${WIRINGPI_LIBRARIES}
        )

add_executable(theodolite_interactive_master src/theodolite_interactive_master.cpp src/lora_radio.cpp src/radio_message_serialize.cpp)
add_dependencies(theodolite_interactive_master ${catkin_EXPORTED_TARGETS})
target_link_libraries(theodolite_interactive_master 
        ${catkin_LIBRARIES} 
        ${WIRINGPI_LIBRARIES}
        )

add_executable(theodolite_collect_markers src/theodolite_collect_markers.cpp src/lora_radio.cpp src/radio_message_serialize.cpp)
add_dependencies(theodolite_collect_markers ${catkin_EXPORTED_TARGETS})
target_link_libraries(theodolite_collect_markers 
        ${catkin_LIBRARIES} 
        ${WIRINGPI_LIBRARIES}
        )

add_executable(theodolite_node ${SOURCES} src/theodolite_node.cpp src/lora_radio.cpp src/radio_message_serialize.cpp)
target_link_libraries(theodolite_node 
        ${catkin_LIBRARIES} 
        ${PROJECT_LIBRARY_LINK}
        ${LIBUSB_1_LIBRARY}
        ${WIRINGPI_LIBRARIES}
        )

add_executable(theodolite_collect_calib_prisms src/theodolite_collect_calib_prism.cpp src/lora_radio.cpp src/radio_message_serialize.cpp)
add_dependencies(theodolite_collect_calib_prisms ${catkin_EXPORTED_TARGETS})
target_link_libraries(theodolite_collect_calib_prisms 
        ${catkin_LIBRARIES} 
        ${WIRINGPI_LIBRARIES}
        )


 










