cmake_minimum_required(VERSION 2.8.3)
project(temoto_ws)

# use c++11 standard
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  temoto
  temoto_action_assistant
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
