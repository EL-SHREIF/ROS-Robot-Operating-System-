# ROS Script
* **roscore**
* **catkin build (package name)** 
* **echo "source ~/mybot_ws/devel/setup.bash" >> ~/.bashrc**
* **source ~/.bashrc**
* **roslaunch mybot_gazebo mybot_world.launch**
* **rostopic echo /navsat/fix**
* **rostopic echo /navsat/vel** 
* **rostopic echo /imu/data** 
==============================================================
<br>
**rostopic pub /cmd_vel geometry_msgs/Twist "linear:
  x: 0.0
  y: 0.0
  z: 0.0
angular:
  x: 0.0
  y: 0.0
  z: 0.0" **

