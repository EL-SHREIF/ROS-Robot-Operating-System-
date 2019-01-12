cmake_minimum_required(VERSION 2.8.3)
project(exercise_three)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)



## Generate messages in the 'msg' folder
add_message_files(
   FILES
   UserInfo.msg

 )



## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
CATKIN_DEPENDS message_runtime

)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


# catkin_add_nosetests(test)
add_executable(user_info_driver src/user_info_driver.cpp)
target_link_libraries(user_info_driver ${catkin_LIBRARIES})
add_dependencies(user_info_driver exercise_one_generate_messages_cpp)

add_executable(data_processing src/data_processing.cpp)
target_link_libraries(data_processing ${catkin_LIBRARIES})
add_dependencies(data_processing exercise_one_generate_messages_cpp)
