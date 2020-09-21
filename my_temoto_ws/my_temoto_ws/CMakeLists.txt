cmake_minimum_required(VERSION 2.8.3)
project(my_temoto_ws)

# use c++11 standard
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  temoto_action_assistant
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# component_string_0
add_executable(component_string_0 src/component_string_0.cpp)
add_dependencies(component_string_0 ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})
target_link_libraries(component_string_0 ${catkin_LIBRARIES} )

# component_string_1
add_executable(component_string_1 src/component_string_1.cpp)
add_dependencies(component_string_1 ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})
target_link_libraries(component_string_1 ${catkin_LIBRARIES} )

# component_string_2
add_executable(component_string_2 src/component_string_2.cpp)
add_dependencies(component_string_2 ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})
target_link_libraries(component_string_2 ${catkin_LIBRARIES} )