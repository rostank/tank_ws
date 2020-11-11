#!/bin/bash
rosbag record -b 1024 --lz4 /gps/navsat /imu/data /imu/magnetometer /gps/fix /gps/fix_velocity
