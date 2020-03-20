
#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{

		Mat srcMat = imread("coin.png",0);
		Mat binaryMat;
		Mat em, dm, om, cm;

		threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
		Mat element = getStructuringElement(MORPH_RECT, Size(3,3));

		erode(binaryMat, em, element);
		dilate(binaryMat, dm, element);
		morphologyEx(binaryMat, om, MORPH_OPEN, element);
		morphologyEx(binaryMat, cm, MORPH_CLOSE, element);

		imshow("frame", srcMat);
		imshow("binaryMat", binaryMat);
		imshow("erode", em);
		imshow("dilate", dm);
		imshow("opening", om);
		imshow("closing", cm);

		waitKey(0);

}

