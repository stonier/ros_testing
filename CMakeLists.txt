cmake_minimum_required(VERSION 2.8.3)
project(dude)
find_package(catkin REQUIRED COMPONENTS roscpp nodelet pluginlib)

catkin_package(
   CATKIN_DEPENDS roscpp nodelet pluginlib std_msgs
)

include_directories(include ${catkin_INCLUDE_DIRS})

add_library(dude_nodelet dude.cpp)

target_link_libraries(dude_nodelet ${catkin_LIBRARIES})

