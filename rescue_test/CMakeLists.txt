cmake_minimum_required(VERSION 3.0.2)
project(rescue_test)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  mobile_base_msgs

)

catkin_package(
  LIBRARIES 
  CATKIN_DEPENDS mobile_base_msgs roscpp std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(rescue_test src/rescue_test.cpp)

target_link_libraries(rescue_test
  ${catkin_LIBRARIES}
)