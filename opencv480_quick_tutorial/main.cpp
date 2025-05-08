#include <opencv2/opencv.hpp>
#include <iostream>
#include "quickopencv.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv) {
	//Mat src = imread("lena.png", IMREAD_GRAYSCALE);
	//B  G   R  每个占一个字节即8位，有0-255种选择，所以图像颜色有255*255*255种选择
	//如果还有透明通道，则是4通道，又增加0-255种选择
	Mat src = imread("lena.png");
	if (src.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("输入窗口", WINDOW_FREERATIO);
	imshow("输入窗口", src);

	QuickDemo qd;
	//qd.colorSpace_demo(src);
	//qd.pixel_visit_demo(src);
	//qd.operators_demo(src);
	qd.track_bar_demo(src);

	waitKey(0);
	destroyAllWindows();
	return 0;
}