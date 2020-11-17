#!/bin/sh
# Connects to localhost:4223 by default, use --host and --port to change this

uid=6fXE6x # Change XXYYZZ to the UID of your IMU Brick 2.0

# Handle incoming quaternion callbacks
#tinkerforge dispatch imu-v2-brick $uid all-data &

tinkerforge call imu-v2-brick $uid get-sensor-fusion-mode &

# Set period for quaternion callback to 0.1s (100ms)
#tinkerforge call imu-v2-brick $uid set-all-data-period 1000

echo "Press key to exit"; read dummy

kill -- -$$ # Stop callback dispatch in background
