#include<iostream>
#include<opencv2\opencv.hpp>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("test.jpg");
	int height = srcMat.rows;  //行数，即图片的高
	int width = srcMat.cols;   //列数，即图片的宽
	for (int j = 0; j < height; j++) {
		//单行处理结束
		for (int i = 0; i < width; i++) {
			//------开始处理每个像素------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] +
				             srcMat.at<Vec3b>(j, i)[1] +
			        	     srcMat.at<Vec3b>(j, i)[2]) / 3;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
			//-----结束每个像素的处理-----------
		}
	}
	imshow("src", srcMat);
	waitKey(0);
	return 0;
}