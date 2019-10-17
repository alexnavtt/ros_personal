#include "ros/ros.h"
#include "std_msgs/String.h"

void shoutHeard(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO(msg->data.c_str());
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("echoed_words", 1000, shoutHeard);

    ros::spin();

    return 0;
}
