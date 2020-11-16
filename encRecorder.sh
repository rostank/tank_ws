#!/bin/bash
rosbag record -b 1024 --lz4 /belt/odom /cmd_vel /gps/fix /gps/fix_velocity \
/imu/data /lwheel /lwheel_vtarget /rwheel /rwheel_vtarget /twist_au /twist_joy
