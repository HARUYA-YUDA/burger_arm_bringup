# Burger Arm Bringup
---
package for HappyBurger's robotic arm.

# Environment
Ubuntu 16.04
ROS Kinetic
labPC Alienware13
dynamixel mikata arm e54d5eb commit
HappyBurger

# How to Install
At first, you have to install dynamixel mikata arm
You can install dynamixel mikata arm at https://github.com/ROBOTIS-JAPAN-GIT/dynamixel_mikata_arm
and then, install burger arm bringup package.
```
$ cd ~/catkin_ws/src
$ git clone https://github.com/HARUYA-YUDA/burger_arm_bringup.git
$ cd ~/catkin_ws
$ catkin_make
```

# How to work
When you want arm work on cleaning mode which is the third motor work on torque mode
Follow these command.
This command is put "value 80" for example.
```
$ roslaunch burger_arm_bringup bringup.launch
$ rosservice call /disable_all
$ rosservice call /set_cleaning
$ rosservice call /enable_all
$ rostopic pub /dxl/goal_current mikata_arm_msgs/dxl_double "id:
- 3
data:
- 80"
```

