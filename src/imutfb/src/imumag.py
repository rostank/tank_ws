#!/usr/bin/env python3
import rospy
from imutfb.msg import imu_message
from sensor_msgs.msg import Imu, MagneticField, Temperature
from collections import namedtuple

# Download with "sudo apt install python3-tinkerforge"
from tinkerforge.ip_connection import IPConnection
from tinkerforge.brick_imu_v2 import BrickIMUV2

# Sensor specific information
HOST = "localhost"
PORT = 4223
UID = "6fXE6x"

def StdDataHandler():
    msg = Imu()
    msg.header.stamp = rospy.get_rostime()
    msg.header.frame_id = "Std_IMU_Data"

    msg.linear_acceleration.x = imu.get_all_data().linear_acceleration[0]/100.0
    msg.linear_acceleration.y = imu.get_all_data().linear_acceleration[1]/100.0
    msg.linear_acceleration.z = imu.get_all_data().linear_acceleration[2]/100.0

    msg.angular_velocity.x = imu.get_all_data().angular_velocity[0]/16
    msg.angular_velocity.y = imu.get_all_data().angular_velocity[1]/16
    msg.angular_velocity.z = imu.get_all_data().angular_velocity[2]/16

    msg.orientation.w = imu.get_all_data().quaternion[0]/16383.0
    msg.orientation.x = imu.get_all_data().quaternion[1]/16383.0
    msg.orientation.y = imu.get_all_data().quaternion[2]/16383.0
    msg.orientation.z = imu.get_all_data().quaternion[3]/16383.0

    msg.orientation_covariance = [0.002,0.,0.,0.,0.002,0.,0.,0.,0.002]

    msg.angular_velocity_covariance = [0.003,0.,0.,0.,0.003,0.,0.,0.,0.003]

    msg.linear_acceleration_covariance = [0.60,0.,0.,0.,0.60,0.,0.,0.,0.60]

    return msg

def MagDataHandler():
    msg = MagneticField()
    msg.header.stamp = rospy.get_rostime()
    msg.header.frame_id = "Mag_IMU_Data"
    
    msg.magnetic_field.x = imu.get_all_data().magnetic_field[0]/16.0
    msg.magnetic_field.y = imu.get_all_data().magnetic_field[1]/16.0
    msg.magnetic_field.z = imu.get_all_data().magnetic_field[2]/16.0

    msg.magnetic_field_covariance = [0.002,0.,0.,0.,0.002,0.,0.,0.,0.002,]

    return msg

def TempDataHandler():
    msg = Temperature()
    msg.header.stamp = rospy.get_rostime()
    msg.header.frame_id = "Temp_IMU_Data"

    msg.temperature = imu.get_all_data().temperature

    return msg

def talker():
    #pub = rospy.Publisher('IMU_Brick', imu_message, queue_size=1)   # Name of the published ROS topic
    rospy.init_node('IMU_Brick_pub', anonymous=True)    # Name of the ROS Node
    pub1 = rospy.Publisher('imu/data', Imu, queue_size=1)   # Name of the published ROS topic
    pub2 = rospy.Publisher('imu/magnetometer', MagneticField, queue_size=1)   # Name of the published ROS topic
    pub3 = rospy.Publisher('imu/temperature', Temperature, queue_size=1)

    r = rospy.Rate(20)  #10hz
    
    msg = imu_message()
    
    while not rospy.is_shutdown():
        msg1 = StdDataHandler()
        msg2 = MagDataHandler()
        msg3 = TempDataHandler()
        #rospy.loginfo(msg)
        pub1.publish(msg1)
        pub2.publish(msg2)
        pub3.publish(msg3)
        r.sleep()

if __name__ == '__main__':
    ipcon = IPConnection() # Create IP connection
    imu = BrickIMUV2(UID, ipcon) # Create device object
    ipcon.connect(HOST, PORT) # Connect to brickd

    try:
        talker()
    except rospy.ROSInterruptException: pass
