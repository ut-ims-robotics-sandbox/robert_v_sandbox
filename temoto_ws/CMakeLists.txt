cmake_minimum_required(VERSION 2.8.3)
project(temoto_ws)

# use c++11 standard
add_compile_options(-std=c++17 -ggdb)

set(ACTION_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib/)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  temoto_action_assistant
  class_loader
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# Build the test app
add_executable(test_app
  src/test_app.cpp
)

add_dependencies(test_app
  ${catkin_EXPORTED_TARGETS}
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
)

target_link_libraries(test_app
  ${catkin_LIBRARIES}
)

# Build the test plugin
add_library(test_plugin_1
  src/test_plugin_1.cpp
)

file(MAKE_DIRECTORY ${ACTION_LIB_DIR})

set_target_properties(test_plugin_1
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${ACTION_LIB_DIR}
)
target_link_libraries(test_plugin_1
  ${class_loader_LIBRARIES}
  ${catkin_LIBRARIES}
)

class_loader_hide_library_symbols(test_plugin_1)

add_dependencies(test_plugin_1 ${catkin_EXPORTED_TARGETS})

# Build the test plugin
add_library(test_plugin_2
  src/test_plugin_2.cpp
)

file(MAKE_DIRECTORY ${ACTION_LIB_DIR})

set_target_properties(test_plugin_2
  PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${ACTION_LIB_DIR}
)
target_link_libraries(test_plugin_2
  ${class_loader_LIBRARIES}
  ${catkin_LIBRARIES}
)

class_loader_hide_library_symbols(test_plugin_2)

add_dependencies(test_plugin_2 ${catkin_EXPORTED_TARGETS})