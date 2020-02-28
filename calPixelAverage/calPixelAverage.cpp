#include<iostream>
#include<opencv2\opencv.hpp>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("test.jpg");
	int height = srcMat.rows;  //��������ͼƬ�ĸ�
	int width = srcMat.cols;   //��������ͼƬ�Ŀ�
	for (int j = 0; j < height; j++) {
		//���д������
		for (int i = 0; i < width; i++) {
			//------��ʼ����ÿ������------------
			uchar average = (srcMat.at<Vec3b>(j, i)[0] +
				             srcMat.at<Vec3b>(j, i)[1] +
			        	     srcMat.at<Vec3b>(j, i)[2]) / 3;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
			//-----����ÿ�����صĴ���-----------
		}
	}
	imshow("src", srcMat);
	waitKey(0);
	return 0;
}