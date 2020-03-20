#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat binaryMat;
	Mat labelMat, statsMat, centrMat, resultMat;
	Mat srcMat;

    srcMat = imread("IMG_1989.JPG", 0);

	bitwise_not(srcMat, srcMat);

	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);

	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(9, 11));
	morphologyEx(binaryMat, binaryMat, MORPH_OPEN, element);

	int nComp = connectedComponentsWithStats(binaryMat, labelMat, statsMat, centrMat, 8, CV_32S);

	cout << "the number is = " << nComp - 1 << endl;

	for (int i = 1; i < nComp; i++)
	{
		Rect bndbox;
		bndbox.x = statsMat.at<int>(i, 0);
		bndbox.y = statsMat.at<int>(i, 1);
		bndbox.width = statsMat.at<int>(i, 2);
		bndbox.height = statsMat.at<int>(i, 3);
		rectangle(binaryMat, bndbox, CV_RGB(255, 255, 255), 1, 8, 0);
	}

	imshow("binaryMat", binaryMat);
	imshow("option", srcMat);
	waitKey(0);
	return 0;
}
