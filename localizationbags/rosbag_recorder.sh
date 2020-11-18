#!/bin/bash
# Run as ./rosbag_recorder file_to_use localization_settings
rosbag record -o $1_$2.bag  -b 1024 --lz4 /odometry/filtered /odometry/filtered_map /odometry/gps __name:=my_bag &
rosbag play -r 1 ~/tank_ws/sensorbags/$1.bag
rosnode kill /my_bag
