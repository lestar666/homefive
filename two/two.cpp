#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat binaryMat;
	Mat labelMat, statsMat, centrMat, resultMat;
	Mat srcMat;

	srcMat = imread("coin.png", 0);

	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);

	int nComp = connectedComponentsWithStats(binaryMat, labelMat, statsMat, centrMat, 8, CV_32S);

	for (int i = 0; i < nComp; i++)
	{
		cout << "connected Components NO. " << i << endl;
		cout << "pixels = " << statsMat.at<int>(i, 4) << endl;
		cout << "width = " << statsMat.at<int>(i, 2) << endl;
		cout << "height = " << statsMat.at<int>(i, 3) << endl;
		cout << endl;
	}
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
