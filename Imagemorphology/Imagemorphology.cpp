
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	cv::Mat srcMat = imread("coin.png");
	cv::Mat binaryMat;
	cv::threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);

	Mat elementSizel = getStructuringElement(MORPH_ELLIPSE, Size(9, 11));
	Mat out;
	dilate(binaryMat, out, elementSizel);
	imshow("pengzhang", out);
	erode(binaryMat, out, elementSizel);
	imshow("fushi", out);
	morphologyEx(binaryMat, binaryMat, MORPH_OPEN, elementSizel);
	imshow("binaryMat", binaryMat);
	morphologyEx(binaryMat, binaryMat, MORPH_CLOSE, elementSizel);
	imshow("binaryMat", binaryMat);
	return 0;

}

