cmake_minimum_required(VERSION 2.8.3)
project(exercise_one)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )



## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES exercise_one
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)



add_executable(user_info_driver src/user_info_driver.cpp)
target_link_libraries(user_info_driver ${catkin_LIBRARIES})
add_dependencies(user_info_driver exercise_one_generate_messages_cpp)

add_executable(data_processing src/data_processing.cpp)
target_link_libraries(data_processing ${catkin_LIBRARIES})
add_dependencies(data_processing exercise_one_generate_messages_cpp)
