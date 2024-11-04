cmake_minimum_required(VERSION 3.5)
project(theodolite_node)

## Compile as C++11, supported in ROS2
add_compile_options(-std=c++11)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(theodolite_node_msgs REQUIRED)
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(${EIGEN_INCLUDE_DIR})

## Generate added messages and services
# This is not needed in ROS2 as messages are generated automatically

ament_export_dependencies(rclcpp std_msgs theodolite_node_msgs Eigen3)

if(LIBUSB_1_LIBRARIES AND LIBUSB_1_INCLUDE_DIRS)
    set(LIBUSB_FOUND TRUE)
else()
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
    endif()

    if (LIBUSB_1_FOUND)
        message(STATUS "Found libusb-1.0:")
        message(STATUS " - Includes: ${LIBUSB_1_INCLUDE_DIRS}")
        message(STATUS " - Libraries: ${LIBUSB_1_LIBRARIES}")
    else()
        message(FATAL_ERROR "Could not find libusb")
    endif()
endif()

if(WIRINGPI_LIBRARIES AND WIRINGPI_INCLUDE_DIRS)
    set(WIRINGPI_FOUND TRUE)
else()
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
    endif()

    if (WIRINGPI_FOUND)
        message(STATUS "Found wiringPi:")
        message(STATUS " - Includes: ${WIRINGPI_INCLUDE_DIRS}")
        message(STATUS " - Libraries: ${WIRINGPI_LIBRARIES}")
    else()
        message(FATAL_ERROR "Could not find wiringPi")
    endif()
endif()

file(GLOB LIBRARIES_SO "lib/*.so")
set(PROJECT_LIBRARY_LINK ${LIBRARIES_SO})

include_directories(
        # ${LIBRARIES_FOLDER}/include 
        # ${LIBRARIES_FOLDER}/src 
        ${LIBUSB_1_INCLUDE_DIR}
        ${WIRINGPI_INCLUDE_DIRS}
        )

file(GLOB SOURCES "src/Obs*" "src/Ssi*" "src/TCP*" "src/USB*" "src/Video*")

add_executable(theodolite_master src/theodolite_master.cpp src/lora_radio.cpp src/radio_message_serialize.cpp)
ament_target_dependencies(theodolite_master rclcpp std_msgs theodolite_node_msgs Eigen3)
target_link_libraries(theodolite_master ${WIRINGPI_LIBRARIES})

install(TARGETS
  theodolite_master
  DESTINATION lib/${PROJECT_NAME})

ament_package()
