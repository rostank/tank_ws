#!/bin/bash
# Run with ./fixedSpeed.sh speed rotation wait
rostopic pub -r 10 /twist_au geometry_msgs/Twist '{linear:  {x: 0.0, y: 0.0, z: 0.0}, angular: {x: 0.0,y: 0.0,z: 0.6}}'
