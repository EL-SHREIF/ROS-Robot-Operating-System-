cmake_minimum_required(VERSION 2.8.3)
project(our_model)


add_definitions(--std=c++11)

find_package(catkin REQUIRED COMPONENTS
  ackermann_msgs
  roscpp
  std_msgs
)

catkin_package(
INCLUDE_DIRS 
include
#LIBRARIES fisheye_camera
CATKIN_DEPENDS 
ackermann_msgs
roscpp 
std_msgs
#  DEPENDS system_lib
)

include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}
  src/${PROJECT_NAME}_node.cpp
  src/model.cpp
)

## Specify libraries to link a library or executable target against
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)
