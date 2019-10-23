#include "ros/ros.h"
#include "std_msgs/Float64MultiArray.h"
#include "opencv2/highgui.hpp"
#include <cv_bridge/cv_bridge.h>
#include <math.h>
#include <iostream>

cv::Point center = cv::Point(0.0, 0.0);
cv::VideoCapture cap(0);

void update_center(const std_msgs::Float64MultiArray::ConstPtr& center_loc)
{
	center.x = center_loc->data[0];
	center.y = center_loc->data[1];
}

void plot_image()
{
	//cv::VideoCapture cap(0);

	cv::Mat frame;
	cap >> frame;

	//Size of the image
	int x_max = frame.cols;
        int y_max = frame.rows;

        //Define parameters for a circle to overlay on frame
        int radius = 50;
        int linewidth = 1;
	int linetype = 8;
	int shift = 0;
	cv::Scalar color = cv::Scalar(0, 0, 255);

       
	//Apply circle to frame
        circle(frame, center, radius, color, linewidth, linetype, shift);

	//Show frame
	cv::imshow("Video_Feed", frame);
	cv::waitKey(1);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "show_image");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("center_location", 20, update_center);
	ros::Rate r(60);

	while(ros::ok())
	{
		plot_image();
		ros::spinOnce();
		r.sleep();

		/*Escape condition (press ESC)
                char c=(char)cv::waitKey(25);
                if (c==27){
                        return -1;
                }*/

	}

	return 0;
}
