cmake_minimum_required(VERSION 2.8.3)
project(robert_v_sandbox)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

add_service_files(
  FILES
  AddTwoNumbers.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  #LIBRARIES
  CATKIN_DEPENDS roscpp rospy message_runtime
#  DEPENDS system_lib
) 

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# calculator node
add_executable(calculator_node_cpp
  src/calculator_node.cpp
  src/my_math_operators.cpp
)

add_dependencies(calculator_node_cpp
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
)
target_link_libraries(calculator_node_cpp
  ${catkin_LIBRARIES}
)
