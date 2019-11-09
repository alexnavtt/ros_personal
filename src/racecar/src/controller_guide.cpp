#include "ros/ros.h"
//#include "std_msgs/Float64MultiArray.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/Joy.h"

//double center_array[2] = {0.0,0.0};
geometry_msgs::Twist center;

void updateCenter(const sensor_msgs::Joy::ConstPtr& joystick)
{
	double x = joystick->axes[0];
	double y = joystick->axes[1];

	//center_array[0] = (300.0 - 100.0*x);
	//center_array[1] = (300.0 - 100.0*y);
	center.linear.x -= x;
	center.linear.y -= y;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "guide");
	ros::NodeHandle nh;
	
	ros::Subscriber joy_sub = nh.subscribe<sensor_msgs::Joy>("joy", 15, updateCenter);
	//ros::Publisher pub = nh.advertise<std_msgs::Float64MultiArray>("center_location",100);
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("center_location", 100);

	ros::Rate loop_rate(100);

	while(ros::ok())
	{
		/*std_msgs::Float64MultiArray center;
		center.data.push_back(center_array[0]);
		center.data.push_back(center_array[1]);
		*/

		pub.publish(center);

		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;

}