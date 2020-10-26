#!/usr/bin/env python

import RPi.GPIO as GPIO
import datetime, time
import rospy
import subprocess
from std_msgs.msg import Float32

start_pin = 40
stop_pin = 36
middle_pin = 38

proc = None

def nothing(channel):
    # Placeholder function for the middle button
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
    # Starting launch file
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
    # Stopping the process created by start
    global old_time
    new_time = rospy.get_rostime()
    time_since_last = new_time.to_sec() - old_time.to_sec()
    rospy.sleep(0.1)
    if time_since_last > 0.2:
        rospy.loginfo("Killing Process")
        proc.terminate()
        rospy.sleep(2)
        setvtarget()
        old_time = rospy.get_rostime()
    else:
        return

def setvtarget():
    # Sending zero velocity commands to the arduino
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
    GPIO.setmode(GPIO.BOARD)
    GPIO.setup([start_pin, middle_pin, stop_pin], GPIO.IN)
    GPIO.add_event_detect(start_pin, GPIO.FALLING, callback=start, bouncetime=10)
    GPIO.add_event_detect(middle_pin, GPIO.FALLING, callback=nothing, bouncetime=10)
    GPIO.add_event_detect(stop_pin, GPIO.FALLING, callback=kill, bouncetime=10)

    rospy.init_node('button_listener', anonymous=True)
    rate = rospy.Rate(0.1)
    old_time = rospy.get_rostime()

    try:
        while not rospy.is_shutdown():
            rate.sleep()
    finally:
        GPIO.cleanup()

if __name__ == '__main__':
    main()
