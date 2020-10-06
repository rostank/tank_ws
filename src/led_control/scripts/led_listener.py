#!/usr/bin/env python
import rospy
import RPi.GPIO as GPIO
from std_msgs.msg import String
from std_msgs.msg import Bool

# Pin Definitions
output_pin_red  = 27  # BCM pin 18, BOARD pin 12
output_pin_green = 17
# Pin Setup:
GPIO.setmode(GPIO.BCM)  # BCM pin-numbering scheme from Raspberry Pi
# Pin set as Outpout with initial state of LOW
GPIO.setup(output_pin_red, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(output_pin_green,GPIO.OUT, initial=GPIO.LOW)


def callback(data):
#    rospy.loginfo(data.data)

    if data.data  == True:
       GPIO.output(output_pin_red, GPIO.HIGH)
       GPIO.output(output_pin_green, GPIO.LOW)
    else:
       GPIO.output(output_pin_red, GPIO.LOW)
       GPIO.output(output_pin_green, GPIO.HIGH)

def listener():
    rospy.init_node('listener', anonymous=True)

    # Substribes to the output of the joystick Autonomy switch
    rospy.Subscriber("au_priority", Bool, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
