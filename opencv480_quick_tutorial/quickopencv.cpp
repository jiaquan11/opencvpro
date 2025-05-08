#include "quickopencv.h"

void QuickDemo::colorSpace_demo(Mat& image){
	Mat gray, hsv;
	cvtColor(image, hsv, COLOR_BGR2HSV);
	//H 0-180, S, V 0-255
	cvtColor(image, gray, COLOR_BGR2GRAY);
	imshow("HSV", hsv);
	imshow("灰度", gray);
	imwrite("hsv.png", hsv);
	imwrite("gray.png", gray);
}

void QuickDemo::mat_creation_demo() {
	//Mat m1, m2;
	//m1 = image.clone();
	//image.copyTo(m2);

	//创建空白图像
	Mat m3 = Mat::zeros(Size(400, 400), CV_8UC3);
	m3 = Scalar(255, 0, 0);
	std::cout << "width: " << m3.cols << " height: " << m3.rows << " channels: " << m3.channels() << std::endl;
	//std::cout << m3 << std::endl;

	Mat m4;
	m3.copyTo(m4);
	m4 = Scalar(0, 255, 255);
	imshow("图像3", m3);
	imshow("图像4", m4);
}

void QuickDemo::pixel_visit_demo(Mat& image) {
	int w = image.cols;
	int h = image.rows;
	int dims = image.channels();

	/*for (int row = 0; row < h; row++) {
		for (int col = 0; col < w; col++) {
			if (dims == 1) {//灰度图像
				int pv = image.at<uchar>(row, col);
				image.at<uchar>(row, col) = 255 - pv;
			}
			if (dims == 3) {//彩色图像
				Vec3b bgr = image.at<Vec3b>(row, col);
				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
			}
		}
	}*/
	//使用指针访问像素
	for (int row = 0; row < h; row++) {
		uchar* current_row = image.ptr<uchar>(row);
		for (int col = 0; col < w; col++) {
			if (dims == 1) {//灰度图像
				int pv = *current_row;
				*current_row++ = 255 - pv;
			}
			if (dims == 3) {//彩色图像
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
				*current_row++ = 255 - *current_row;
			}
		}
	}
	imshow("像素读写显示", image);
}

void QuickDemo::operators_demo(Mat& image) {
	Mat dst;
	Mat m = Mat::zeros(image.size(), image.type());
	m = Scalar(2, 2, 2);
	multiply(image, m, dst);
	imshow("乘法操作", dst);
}

Mat src, dst, m;
int lightness = 50;
static void on_track(int, void*) {
	m = Scalar(lightness, lightness, lightness);
	subtract(src, m, dst);
	imshow("亮度调整", dst);
}

void QuickDemo::track_bar_demo(Mat& image) {
	namedWindow("亮度调整", WINDOW_AUTOSIZE);
	dst = Mat::zeros(image.size(), image.type());
	m = Mat::zeros(image.size(), image.type());
	src = image;
	int max_value = 100;
	createTrackbar("Value Bar:", "亮度调整", &lightness, max_value, on_track);//创建滑动条
	on_track(50, 0);
}
