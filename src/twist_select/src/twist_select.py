#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool

au_priority_msg = None
Twist_selected = Twist()
timer_count = 0

pub = rospy.Publisher("cmd_vel", Twist, queue_size=10)

def callback_au(data):
     global au_priority_msg
     
     if au_priority_msg == True:
        if timer_count < 2:
           data.angular.z = data.angular.z*1.45
           pub.publish(data)
     
def callback_joy(data):
     global au_priority_msg
     global timer_count
     timer_count = 0
     
     if au_priority_msg == False:
     	pub.publish(data)

def setbool(data):
     global au_priority_msg
     au_priority_msg = data.data

def timeout_stop(data):
     global timer_count
     timer_count = timer_count+0.5 # Value must be the same as in the Timer function
     
     # Define timeout time in seconds
     if timer_count > 2:
        pub.publish(Twist())

     print(timer_count)

def selector():
    rospy.init_node('selector', anonymous=True)

    # Subscribing to the 3 topics. Each subscriber have a callback function 
    rospy.Subscriber("au_priority", Bool, setbool)
    rospy.Subscriber("twist_au", Twist, callback_au)
    rospy.Subscriber("twist_joy", Twist, callback_joy)
    # The timer that calls the timeout_stop function
    rospy.Timer(rospy.Duration(0.5), timeout_stop) 


if __name__ == '__main__':
    selector()
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

    
    
