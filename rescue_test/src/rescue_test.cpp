#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <mobile_base_msgs/mani_vision.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rescue_test");
  ros::NodeHandle nh;

  ros::Publisher num_pub = nh.advertise<std_msgs::Int32>("/dex_mode", 10);
  ros::Publisher mvis_pub = nh.advertise<mobile_base_msgs::mani_vision>("/mmvis_val", 10);

  ros::Rate loop_rate(30); // 30 Hz

  while (ros::ok())
  {
    std_msgs::Int32 msg;
    msg.data = 0;

    mobile_base_msgs::mani_vision mvis_msg;
    mvis_msg.mode = 12;
    mvis_msg.gradient = 0;
    mvis_msg.find_left = 1;
    mvis_msg.find_right = 0;
    mvis_msg.find_middle = 0;
    mvis_msg.center = 0;
    mvis_msg.box_square = 0;

    mvis_msg.missioning = false;
    mvis_msg.mission_complete = false;
    mvis_msg.grip = false;
    mvis_msg.in_cam = false;
    mvis_msg.in_center = false;

    mvis_msg.difference[0]=0.0;
    mvis_msg.difference[1]=0;
    mvis_msg.difference[2]=0;    
    mvis_msg.angle[0]=0;
    mvis_msg.angle[1]=0;
    mvis_msg.angle[2]=0;

    mvis_msg.center_depth=0;
    mvis_msg.high_depth=0;
    mvis_msg.low_depth=0;
    

    ROS_INFO("Publishing: %d", msg.data);

    num_pub.publish(msg);
    mvis_pub.publish(mvis_msg);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
