# Repository for the Tank

## Important Commands

### Push to github:
git add .

git commit -m "Some Message"

git push ssh://git@ssh.github.com:443/rostank/tank_ws.git master

### Run ROS
roscore

### Run Packages
cd tank_ws

source devel/setup.bash

### If running multiple machines:
cd tank_ws

export ROS_MASTER_URI=http://10.122.12.106:11311

export ROS_IP=10.122.12.106

source devel/setup.bash



###  Run GPS
roslaunch ublox_gps ublox_device.launch node_name:=gps param_file_name:=navigps
 
### Run Stereo Camera
roslaunch zed_wrapper zed2.launch

### Run IMU
rosrun imutfb publisher.py
 
### Run Diff_drive
rosrun differential_drive twist_to_motors.py
 
 
### Selector
roslaunch twist_mux twist_mux.launch

rostopic echo /twist_mux/cmd_vel



rostopic pub /joy_priority std_msgs/Bool true

rostopic pub -r 5 /twist_au geometry_msgs/Twist '{linear:  {x: 0.1, y: 0.0, z: 0.0}, angular: {x: 0.1,y: 0.2,z: 0.3}}'

### Run Arduino
rosrun rosserial_python serial_node.py /dev/ttyUSB0

### Send drive signal to Arduino
rostopic pub -r 1 /lwheel_vtarget std_msgs/Float32 '{data: 0.0}'
