#!/usr/bin/env python
import utm
import rospy
from tf.transformations import*
from geometry_msgs.msg import*
import tf_conversions
def publisher():
    # Load goalpoint from file
    fileObject = open("goal.txt")
    goalPosition = fileObject.readlines()
    latitude = float(goalPosition[0])
    longitude = float(goalPosition[1])
    yaw = float(goalPosition[2])
    fileObject.close()
    print('Given goal:\nLatitude: ', latitude, '\nLongitude: ', longitude, '\nYaw: ', yaw, '\n')
    # Conversion to UTM coordinates
    utmconvert = utm.from_latlon(latitude, longitude)
    print('UTM coordinates:\n', utmconvert)
    # Initialize ROS
    rospy.init_node("latlonconverter")
    goalPointPublisher = rospy.Publisher("move_base_simple/goal", PoseStamped, queue_size=1)
    goalPoint = PoseStamped()
    goalPoint.header.seq = 1
    goalPoint.header.stamp = rospy.Time.now()
    goalPoint.header.frame_id = "utm"
    # Define the goal point in a ROS message
    goalPoint.pose.position.x = utmconvert[0]
    goalPoint.pose.position.y = utmconvert[1]
    goalPoint.pose.position.z = 0.0
    goalPoint.pose.orientation = geometry_msgs.msg.Quaternion(*tf_conversions.transformations.quaternion_from_euler(0, 0, yaw))
    rospy.sleep(1)
    goalPointPublisher.publish(goalPoint)

if __name__ == '__main__':
    try:
        publisher()
    except rospy.ROSInterruptException:
        rospy.loginfo("Interrupted")
