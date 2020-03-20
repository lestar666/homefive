#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("coin.png",0);
	Mat binaryMat;
	Mat labelMat;
	Mat statsMat;
	Mat centrMat;
	Mat resultMat;

	threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	//获得连通域
	int nComp = connectedComponentsWithStats(binaryMat, labelMat, statsMat, centrMat, 8, CV_32S);
	//输出连通域信息
	for (int i = 0; i < nComp; i++)
	{//信息保存在statsMat
		cout << "connected Components NO. " << i << endl;
		cout << "pixels = " << statsMat.at<int>(i, 4) << endl;
		cout << "width = " << statsMat.at<int>(i, 2) << endl;
		cout << "height = " << statsMat.at<int>(i, 3) << endl;
		cout << endl;
	}
	//包括背景
	cout << "the munber is = " << nComp - 1 << endl;  //exclude background
	//绘制
	for (int i = 1; i < nComp; i++)
	{
		Rect bndbx;

		bndbx.x = statsMat.at<int>(i, 0);
		bndbx.y = statsMat.at<int>(i, 1);

		bndbx.width = statsMat.at<int>(i, 2);
		bndbx.height = statsMat.at<int>(i, 3);

		rectangle(binaryMat, bndbx, CV_RGB(255, 255, 255), 1, 8, 0);
	}
 
	imshow("binaryMat", binaryMat);
	imshow("frame", srcMat);
	imwrite("results", binaryMat);
	waitKey(0);
	return 0;
}
