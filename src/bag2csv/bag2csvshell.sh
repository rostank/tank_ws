#!/bin/bash
# Input: ./bag2csvshell.sh filename(without .bag)
rosbag filter /home/tank/tank_ws/sensorbags/$1.bag $1_filtered.bag "topic == '/belt/odom' or topic == '/gps/fix' or topic == '/gps/fix_velocity' or topic == '/imu/acceleration' or topic == '/imu/data' or topic == '/twist_joy' or topic == '/zed2/zed_node/odom' or topic == '/zed2/zed_node/pose'"
wait $!
python3 bag2csv.py $1_filtered.bag
