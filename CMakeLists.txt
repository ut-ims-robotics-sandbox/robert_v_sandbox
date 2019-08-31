cmake_minimum_required(VERSION 2.8.3)
project(robert_v_sandbox)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
  nodelet
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
  LIBRARIES calculator_nodelet
  CATKIN_DEPENDS roscpp rospy message_runtime nodelet
#  DEPENDS system_lib
) 

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest_gtest(calculator_test_node test/calculator_test_launch.test src/test/calculator_test.cpp)
  target_link_libraries(calculator_test_node ${catkin_LIBRARIES})
endif()

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

# calculator nodelet
add_library(calculator_nodelet
  src/calculator_nodelet.cpp
  src/my_math_operators.cpp
)

add_dependencies(calculator_nodelet
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
)
target_link_libraries(calculator_nodelet
  ${catkin_LIBRARIES}
)