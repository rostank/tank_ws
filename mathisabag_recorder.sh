#!/bin/bash
rosbag record -b 1024 --lz4  /cmd_vel \
/imu/magnetometer  \
 /tf /tf_static /twist_au \
/twist_joy /move_base/TrajectoryPlannerROS/local_plan \
/move_base/GlobalPlanner/plan \
/zed2/zed_node/odom /zed2/zed_node/path_map /zed2/zed_node/path_odom \
/zed2/zed_node/pose /zed2/zed_node/pose_with_covariance \
/odometry/filtered /odometry/filtered_map
