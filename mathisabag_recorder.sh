#!/bin/bash
rosbag record -b 1024 --lz4 /belt/odom /cmd_vel \
/imu/data /imu/magnetometer /lwheel \
/lwheel_vtarget /rwheel /rwheel_vtarget /tf /tf_static /twist_au \
/twist_joy \
/zed2/zed_node/odom /zed2/zed_node/path_map /zed2/zed_node/path_odom \
/zed2/zed_node/pose /zed2/zed_node/pose_with_covariance \
/odometry/filtered /odometry/filtered_map
