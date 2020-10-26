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

#import atexit
import RPi.GPIO as GPIO
#import time
import subprocess
#import rostopic
#import rospy
#import roslaunch
import rospy
import roslib
from std_msgs.msg import Float32

# Pin Definitions:
start_pin = 40
stop_pin = 36
middle_pin = 38
#red_pin = 13
#green_pin = 11

proc = None

#atexit.register(GPIO.cleanup())

# blink LED 2 quickly 5 times when button pressed
def start(channel):
    global proc
    #GPIO.setup([red_pin, green_pin], GPIO.OUT)
    #i=0
    #while i < 5:
    #    GPIO.output(red_pin,GPIO.HIGH)
    #    time.sleep(0.1)
    #    GPIO.output(red_pin,GPIO.LOW)
    #    time.sleep(0.1)
    #    i += 1
    #GPIO.cleanup()
    #os.setuid(1000)
    #os.setgid(1000)
    #my_env = os.environ.copy()
    #subprocess.Popen("/home/tank/launcher.sh &", shell=True)
    #subprocess.call(["/home/tank/launcher.sh", "&>", "out.log", "&"])
    proc = subprocess.Popen(["roslaunch", "launchers", "sensor_drive.launch"])
    #uuid = roslaunch.rlutil.get_or_generate_uuid(None, False)
    #roslaunch.configure_logging(uuid)
    #launch = roslaunch.parent.ROSLaunchParent(uuid, ['/home/tank/tank_ws/launch/sensor_drive.launch'])
    #launch.start()
    #is_rosmaster_running = True
    #while is_rosmaster_running==True:
    #    try:
    #        # Checkif rosmaster is running or not.
    #        rostopic.get_topic_class('/rosout')
    #        is_rosmaster_running = True
    #    except rostopic.ROSTopicIOException as e:
    #        is_rosmaster_running = False
    #        pass
    #    rospy.logwarn('Online')
    #    time.sleep(5)
    #GPIO.setmode(GPIO.BOARD)
    #GPIO.setup(but_pin, GPIO.IN)
    #GPIO.add_event_detect(but_pin, GPIO.FALLING, callback=start, bouncetime=10)
    #GPIO.setup([red_pin, green_pin], GPIO.OUT)
    #exit()

def stop(channel):
    #global proc
    print("STOPPING")
    #rospy.logwarn("Killing Nodes")
    #call(["rosnode", "kill", "-a"])
    #rospy.sleep(5)
    #setvtarget()
    rospy.logwarn("Killing Process")
    proc.kill()
    #rospy.sleep(3)
    #rospy.logwarn("Killing ROS")
    #call(["killall", "roscore"])
    #call(["killall", "-9", "rosmaster"])

def nothing(channel):
    print("Nothing has been done")
    

def setvtarget():
    rospy.logwarn("Setting velocities to 0")


    pub_lmotor = rospy.Publisher('lwheel_vtarget', Float32, queue_size=10)
    pub_rmotor = rospy.Publisher('rwheel_vtarget', Float32, queue_size=10)
    pub_arm = rospy.Publisher('arm_turn', Float32, queue_size=10)

    rate = rospy.Rate(10)
    i = 1
    while i < 30:
        pub_lmotor.publish(0)
        pub_rmotor.publish(0)
        pub_arm.publish(0)
    #rospy.logwarn(i)
        i =+ 1
        rate.sleep()

def main():
    # Pin Setup:
    GPIO.setmode(GPIO.BOARD)  # BOARD pin-numbering scheme
    #GPIO.setup([red_pin, green_pin], GPIO.OUT)  # LED pins set as output
    GPIO.setup([start_pin, middle_pin, stop_pin], GPIO.IN)  # button pin set as input
    GPIO.setwarnings(False)
    GPIO.add_event_detect(start_pin, GPIO.FALLING, callback=start, bouncetime=100)
    GPIO.add_event_detect(stop_pin, GPIO.FALLING, callback=stop, bouncetime=100)
    GPIO.add_event_detect(middle_pin, GPIO.FALLING, callback=nothing, bouncetime=100)

    #GPIO.output(red_pin,GPIO.LOW)
    #GPIO.output(green_pin, GPIO.HIGH)
    #time.sleep(5)
    #GPIO.output(green_pin, GPIO.LOW)

    rospy.init_node('button_listener', anonymous=True)

    try:
        while True:
#            if rosgraph.is_master_online():
#                continue
#            else:
#                GPIO.setmode(GPIO.BOARD)
#                GPIO.setup(but_pin, GPIO.IN)
#                GPIO.add_event_detect(but_pin, GPIO.FALLING, callback=start, bouncetime=10)
#                GPIO.setup([red_pin, green_pin], GPIO.OUT)
#                GPIO.output(red_pin, GPIO.HIGH)
#                GPIO.output(green_pin, GPIO.HIGH)
#                time.sleep(1)
#                GPIO.output(red_pin, GPIO.LOW)
#                GPIO.output(green_pin, GPIO.LOW)
            rospy.sleep(5)
    except (KeyboardInterrupt, SystemExit):
        GPIO.cleanup()
    finally:
        GPIO.cleanup()  # cleanup all GPIOs

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        GPIO.cleanup()
