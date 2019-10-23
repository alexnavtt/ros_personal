#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "shout");
    ros::NodeHandle nh;

    ros::Publisher shouting_person = nh.advertise<std_msgs::String>("yelled_words",1000);

    ros::Rate loop_rate(0.33);

    while(ros::ok())
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "Hello, I don't know";

        msg.data = ss.str();
        ROS_INFO("Yelled");
        shouting_person.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
