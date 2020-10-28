#!/bin/bash
rosbag record -b 1024 --lz4 /belt/odom /cmd_vel /gps/fix /gps/fix_velocity \
/imu/data /imu/gravity /imu/acceleration /imu/magnetometer /lwheel \
/lwheel_vtarget /rwheel /rwheel_vtarget /tf /tf_static /twist_au \
/twist_joy /zed2/zed_node/left/camera_info \
/zed2/zed_node/left/image_rect_gray/compressed \
/zed2/zed_node/left/image_rect_gray/compressed/parameter_descriptions \
/zed2/zed_node/left/image_rect_gray/compressed/parameter_updates \
/zed2/zed_node/odom /zed2/zed_node/path_map /zed2/zed_node/path_odom \
/zed2/zed_node/pose /zed2/zed_node/pose_with_covariance \
/zed2/zed_node/rgb/image_rect_gray/compressed \
/zed2/zed_node/rgb/image_rect_gray/compressed/parameter_descriptions \
/zed2/zed_node/rgb/image_rect_gray/compressed/parameter_updates \


