cmake_minimum_required(VERSION 3.0.2)
project(trajectory_recorder)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  sensor_msgs
  std_msgs
  trajectory_msgs
)

add_service_files(
  FILES
  TrajectoryRecorderControl.srv
  GetRecordedTrajectory.srv
)

generate_messages(
  DEPENDENCIES
  trajectory_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES trajectory_recorder
#  CATKIN_DEPENDS message_generation roscpp sensor_msgs std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Action engine node
add_executable(trajectory_recorder_node
  src/trajectory_recorder_node.cpp
  src/trajectory_recorder.cpp
)

add_dependencies(trajectory_recorder_node
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
)

target_link_libraries(trajectory_recorder_node
  ${catkin_LIBRARIES}
)