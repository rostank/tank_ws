#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Pose
from nav_msgs.msg import Odometry
from tf import TransformBroadcaster

class OdometryGenerator:
	def __init__(self):
		rospy.init_node('Driver')
		rospy.Subscriber("/base_pose",Pose,self.callback,queue_size=1)
		self.br = TransformBroadcaster()
	
	def callback(self,Pose):
		trans = (Pose.position.x, Pose.position.y, Pose.position.z)
		rot   = (Pose.orientation.x, Pose.orientation.y, Pose.orientation.z, Pose.orientation.w)
		self.br.sendTransform(trans, rot, rospy.Time.now(),"base_link","map")
       

if __name__ == '__main__':
	try:
		OdometryGenerator()
		rospy.spin()
	except rospy.ROSInterruptException:
		pass
