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
import time
import subprocess
import rostopic
import rospy
import os

# Pin Definitions:
but_pin = 21
red_pin = 13
green_pin = 11

#atexit.register(GPIO.cleanup())

# blink LED 2 quickly 5 times when button pressed
def start(channel):
    
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
    #subprocess.Popen("/home/tank/launcher.sh", shell=True, env=my_env)
    subprocess.call("/home/tank/launcher.sh")
    is_rosmaster_running = True
    while is_rosmaster_running==True:
        try:
            # Checkif rosmaster is running or not.
            rostopic.get_topic_class('/rosout')
            is_rosmaster_running = True
        except rostopic.ROSTopicIOException as e:
            is_rosmaster_running = False
            pass
        rospy.logwarn('Online')
        time.sleep(5)
    #GPIO.setmode(GPIO.BOARD)
    #GPIO.setup(but_pin, GPIO.IN)
    #GPIO.add_event_detect(but_pin, GPIO.FALLING, callback=start, bouncetime=10)
    #GPIO.setup([red_pin, green_pin], GPIO.OUT)

def main():
    # Pin Setup:
    GPIO.setmode(GPIO.BCM)  # BOARD pin-numbering scheme
    #GPIO.setup([red_pin, green_pin], GPIO.OUT)  # LED pins set as output
    GPIO.setup(but_pin, GPIO.IN)  # button pin set as input
    GPIO.setwarnings(False)
    GPIO.add_event_detect(but_pin, GPIO.FALLING, callback=start, bouncetime=10)

    #GPIO.output(red_pin,GPIO.LOW)
    #GPIO.output(green_pin, GPIO.HIGH)
    #time.sleep(5)
    #GPIO.output(green_pin, GPIO.LOW)

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
            time.sleep(5)
    except (KeyboardInterrupt, SystemExit):
        GPIO.cleanup()
    finally:
        GPIO.cleanup()  # cleanup all GPIOs

if __name__ == '__main__':
    main()
