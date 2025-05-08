#pragma once

#include <opencv2/opencv.hpp>
using namespace cv;

class QuickDemo{
public:
	void colorSpace_demo(Mat& image);
	void mat_creation_demo();
	void pixel_visit_demo(Mat& image);
	void operators_demo(Mat& image);
	void track_bar_demo(Mat& image);
};

