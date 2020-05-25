cmake_minimum_required(VERSION 2.8.3)
project(theodolite_node)

set(PATH_LIBRARY "include/")

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES inv_node
  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(include)
include_directories(lib)
include_directories(src)
include_directories(include/asio)
include_directories(include/asio/asio)
include_directories(include/Common/Connection)
include_directories(include/Trimble.Contracts/SpatialImaging)
include_directories(include/Trimble.Ssi.DriverManagement)
include_directories(include/Trimble.Ssi.Interfaces/Common)
include_directories(include/Trimble.Ssi.Interfaces/GNSS)
include_directories(include/Trimble.Ssi.Interfaces/Scanner)
include_directories(include/Trimble.Ssi.Interfaces/TotalStation)
include_directories(include/Trimble.Ssi.Interfaces/Vision)

include_directories(include/Common/Connection/IConnectionStateChangedListener.h)

#target_include_directories(theodolite_node include)
#target_include_directories(theodolite_node src)


#file(GLOB SOURCES "src/*.cpp")
#add_executable(theodolite_node ${SOURCES})

add_executable(theodolite_node src/theodolite_node.cpp)

target_link_libraries(theodolite_node ${catkin_LIBRARIES})
