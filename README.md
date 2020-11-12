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
rosrun imutfb imumag.py
 
### Run Diff_drive
rosrun differential_drive twist_to_motors.py
 
 
### Selector
roslaunch twist_mux twist_mux.launch

rostopic echo /twist_mux/cmd_vel



rostopic pub /joy_priority std_msgs/Bool true

rostopic pub -r 5 /twist_au geometry_msgs/Twist '{linear:  {x: 0.1, y: 0.0, z: 0.0}, angular: {x: 0.1,y: 0.2,z: 0.3}}'

### led indicator
rosrun led_control led_listener.py

### Run Arduino
rosrun rosserial_python serial_node.py /dev/ttyUSB0 _baud:=115200

### Send drive signal to Arduino
rostopic pub -r 1 /lwheel_vtarget std_msgs/Float32 '{data: 0.0}'

### Launch for joystick control
#### Differential_drive
#### led_listener
#### twist_mux
#### serial_node
cd ~/tank_ws/launch
roslaunch joy_drive.launch

### Run Sensor Fusion
roslaunch robot_localization ekf_double.launch

### Launch Sensor drive 
cd ~/tank_ws/launch

roslaunch sensor_drive.launch

#### Copy over ssh:
scp tank@10.122.12.106:/home/tank/tank_ws/sensorbags/sensorbags.zip ~/Downloads

scp ~/Downloads/sensorbags.zip rostank@10.25.6.25:~/tank_ws/sensorbag


### Visualization
Tomtom:
https://api.tomtom.com/map/1/tile/basic/main/{z}/{x}/{y}.png?tileSize=512&key=S7FOifl6AGAQlYLoR3GmDBzLMelDrCe7

