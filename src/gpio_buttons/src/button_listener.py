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
import datetime, time
import rospy
import subprocess
from std_msgs.msg import Float32

# Pin Definitions:
#led_pin_1 = 11
#led_pin_2 = 13
start_pin = 40
stop_pin = 36
middle_pin = 38

proc = None

# blink LED 2 quickly 5 times when button pressed
#def blink(channel):
#    global old_time
#    new_time = rospy.get_rostime()
#    time_since_last = new_time - old_time
#    rospy.loginfo(time_since_last.to_sec())
#    if (time_since_last.to_sec() > 0.2):
#        rate = rospy.Rate(10)
#        rospy.loginfo("Blink LED 2")
#        for i in range(5):
#            GPIO.output(led_pin_2, GPIO.HIGH)
#            rate.sleep()
#            GPIO.output(led_pin_2, GPIO.LOW)
#            rate.sleep()
#        old_time = rospy.get_rostime()
#    else:
#        old_time = old_time

def nothing(channel):
    global old_time
    new_time = rospy.get_rostime()
    time_since_last = new_time.to_sec() - old_time.to_sec()
    rospy.sleep(0.1)
    if time_since_last > 0.2:
        rospy.loginfo("This Button does nothing")
        old_time = rospy.get_rostime()
    else:
        return

def start(channel):
    global old_time
    global proc
    new_time = rospy.get_rostime()
    time_since_last = new_time.to_sec() - old_time.to_sec()
    rospy.sleep(0.1)
    if time_since_last > 0.2:
        rospy.loginfo("Starting Launchfile")
        proc = subprocess.Popen(["roslaunch", "launchers", "sensor_drive.launch"])
        old_time = rospy.get_rostime()
    else:
        return


def kill(channel):
    global old_time
    #global proc
    new_time = rospy.get_rostime()
    time_since_last = new_time.to_sec() - old_time.to_sec()
    rospy.sleep(0.1)
    if time_since_last > 0.2:
        #rospy.loginfo("Killing Nodes")
        #subprocess.call(["rosnode", "kill", "-a"])
        #rospy.sleep(6)
        #setvtarget()
        #rospy.sleep(3)
        rospy.loginfo("Killing Process")
        proc.terminate()
        rospy.sleep(2)
        setvtarget()
        old_time = rospy.get_rostime()
    else:
        return

def setvtarget():
    rospy.logwarn("Setting velocities to 0")

    pub_lmotor = rospy.Publisher('lwheel_vtarget', Float32, queue_size=10)
    pub_rmotor = rospy.Publisher('rwheel_vtarget', Float32, queue_size=10)
    pub_arm = rospy.Publisher('arm_turn', Float32, queue_size=10)

    i = 1
    while i < 3:
        pub_lmotor.publish(0)
        pub_rmotor.publish(0)
        pub_arm.publish(0)
        rospy.logwarn(i)
        i += 1
        rospy.sleep(1)

def main():
    global old_time
    # Pin Setup:
    GPIO.setmode(GPIO.BOARD)  # BOARD pin-numbering scheme
    #GPIO.setup([led_pin_1, led_pin_2], GPIO.OUT)  # LED pins set as output
    GPIO.setup([start_pin, middle_pin, stop_pin], GPIO.IN)  # button pin set as input

    # Initial state for LEDs:
    #GPIO.output(led_pin_1, GPIO.LOW)
    #GPIO.output(led_pin_2, GPIO.LOW)

    GPIO.add_event_detect(start_pin, GPIO.FALLING, callback=start, bouncetime=10)
    GPIO.add_event_detect(middle_pin, GPIO.FALLING, callback=nothing, bouncetime=10)
    GPIO.add_event_detect(stop_pin, GPIO.FALLING, callback=kill, bouncetime=10)

    rospy.loginfo("Starting demo now! Press CTRL+C to exit")

    rospy.init_node('button_listener', anonymous=True)
    rate = rospy.Rate(1) # 10hz

    old_time = rospy.get_rostime()

    try:
        while not rospy.is_shutdown():
            # blink LED 1 slowly
            #GPIO.output(led_pin_1, GPIO.HIGH)
            rate.sleep()
            #GPIO.output(led_pin_1, GPIO.LOW)
            rate.sleep()
    finally:
        GPIO.cleanup()  # cleanup all GPIOs

if __name__ == '__main__':
#    try:
    main()
 #   except rospy.ROSInterruptException:
  #      pass
