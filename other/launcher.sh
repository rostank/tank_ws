#!/bin/bash
source /opt/ros/noetic/setup.bash
export ROS_MASTER_URI=http://10.122.12.106:11311 &
export ROS_IP=10.122.12.106 &
source /home/tank/tank_ws/devel/setup.bash
rs = roscore &
wait $rs
roslaunch gpio_buttons button_listener.launch &
