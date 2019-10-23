#include "ros/ros.h"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <math>

void plot_image(const std_msgs::image_transport::ConstPtr& img)
{
	//Still need to look at image_transport data type
}

int main(argc, argv**)
{
	ros::init(argc, argv, "show_image");
	ros::NodeHandle nh;

	ros::Subsriber sub = nh.subscribe("rectangle_center_location", 20, plot_image);

	ros::spin();

	return 0;
}
