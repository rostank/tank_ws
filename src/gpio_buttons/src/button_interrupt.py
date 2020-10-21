#!/usr/bin/env python

# Copyright (c) 2019, NVIDIA CORPORATION. All rights reserved.
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

import RPi.GPIO as GPIO
import time
from subprocess import call
import rospy
import roslib
from std_msgs.msg import Float32

# Pin Definitions:
but_pin = 36

# blink LED 2 quickly 5 times when button pressed
def kill(channel):
    rospy.logwarn("Killing Nodes")
    call(["rosnode", "kill", "-a"])
    rospy.sleep(2)
    setvtarget()
    rospy.sleep(1)
    rospy.logwarn("Killing ROS")
    call(["killall", "roscore"])
    call(["killall", "-9", "rosmaster"])
    GPIO.cleanup()

def setvtarget():
    rospy.logwarn("Setting velocities to 0")


    pub_lmotor = rospy.Publisher('lwheel_vtarget', Float32, queue_size=10)
    pub_rmotor = rospy.Publisher('rwheel_vtarget', Float32, queue_size=10)
    pub_arm = rospy.Publisher('arm_turn', Float32, queue_size=10)

    #rate = rospy.Rate(10)
    #i = 1
    #while i < 30:
    pub_lmotor.publish(0)
    pub_rmotor.publish(0)
    pub_arm.publish(0)
    #rospy.logwarn(i)
    #    i =+ 1
    #    rate.sleep()

    #call(["rostopic", "pub", "-1", "/lwheel_vtarget", "std_msgs/Float32", "'{data: 0.0}'"])
    #call(["rostopic", "pub", "-1", "/rwheel_vtarget", "std_msgs/Float32", "'{data: 0.0}'"])
    #call(["rostopic", "pub", "-1", "/arm_turn", "std_msgs/Float32", "'{data: 0.0}'"])
def main():
    # Pin Setup:
    GPIO.setmode(GPIO.BOARD)  # BOARD pin-numbering scheme
    GPIO.setup(but_pin, GPIO.IN)  # button pin set as input
    GPIO.setwarnings(False)
    GPIO.add_event_detect(but_pin, GPIO.RISING, callback=kill, bouncetime=10000)
    rospy.loginfo("Waiting anxiously for permission to kill ROS")

    rospy.init_node('velocity_stopper', anonymous=True)
    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        try:
            rate.sleep()
        except :
            GPIO.cleanup()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        GPIO.cleanup()
