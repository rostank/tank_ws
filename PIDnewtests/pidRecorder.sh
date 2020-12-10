#!/bin/bash
rosbag record -b 1024 --lz4 -O $1 /belt/odom \
/lwheel /lwheel_vtarget /rwheel /rwheel_vtarget
