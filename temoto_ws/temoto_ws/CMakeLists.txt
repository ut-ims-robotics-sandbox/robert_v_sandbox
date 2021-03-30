cmake_minimum_required(VERSION 2.8.3)
project(temoto_ws)

# use c++11 standard
add_compile_options(-std=c++14)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  temoto_er_manager
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(er_manager_client
  src/er_manager_client.cpp
)

add_dependencies(er_manager_client 
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
)

target_link_libraries(er_manager_client 
  ${catkin_LIBRARIES}
)
