#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_imu");
  ros::NodeHandle n;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;

  while(n.ok()){
    broadcaster.sendTransform(
      tf::StampedTransform(
        tf::Transform(tf::Quaternion(-0.0183769, -0.004596, 0.0, 0.9998206), tf::Vector3(0.0, 0.0, 0.1427)),
        ros::Time::now(),"base_link", "base_imu"));
    r.sleep();
  }
}
