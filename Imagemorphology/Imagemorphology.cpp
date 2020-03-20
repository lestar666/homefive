
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat srcMat = imread("coin.png",0);
	cv::Mat binaryMat;
	cv::threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);

	Mat elementSizel = getStructuringElement(MORPH_ELLIPSE, Size(9, 11));
	Mat out;
	Mat oout;
	Mat om;
	Mat cm;
	dilate(binaryMat, out, elementSizel);
	imshow("pengzhang", out);
	erode(binaryMat, oout, elementSizel);
	imshow("fushi", out);
	morphologyEx(binaryMat, om, MORPH_OPEN, elementSizel);
	imshow("binaryMat", binaryMat);
	morphologyEx(binaryMat, cm, MORPH_CLOSE, elementSizel);
	imshow("binaryMat", binaryMat);
	waitKey(0);
	return 0;

}

