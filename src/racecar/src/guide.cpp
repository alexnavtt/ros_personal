#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"
#include <math.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "guide");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<std_msgs::Float64MultiArray>("center_location",100);

	ros::Rate loop_rate(100);

	int x_stretch;
	int y_stretch;

	nh.getParam("/guide/x_stretch", x_stretch);
	nh.getParam("/guide/y_stretch", y_stretch);

	ROS_INFO("%i", x_stretch);
	ROS_INFO("%i", y_stretch);

	double t = 0.0;

	while(ros::ok())
	{
		double x = 300 + x_stretch*50*std::sin(t/25.0);
		double y = 300 + y_stretch*50*std::cos(t/25.0);
		std_msgs::Float64MultiArray center;
		
		center.data.push_back(x);
		center.data.push_back(y);

		//ROS_INFO("Pushed Data");
		pub.publish(center);

		t++;

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;

}
