#include <iostream>

#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
  cv::Mat grayimg(600, 800, CV_8UC1);
  cv::Mat colorimg(600, 800, CV_8UC3);

  for (int i = 0; i != grayimg.rows; ++i)
    {
      for(int j = 0; j != grayimg.cols; ++j)
	{
	  grayimg.at<uchar>(i, j) = (i+j)%255;
	}
    }

  for (int i = 0; i != colorimg.rows; ++i)
    {
      for (int j = 0; j != colorimg.cols; ++j)
	{
	  cv::Vec3b pixel;
	  pixel[0] = i % 255;
	  pixel[1] = j % 255;
	  pixel[2] = 0;

	  colorimg.at<cv::Vec3b>(i, j) = pixel;
	}
    }

  cv::namedWindow("grayimg", cv::WINDOW_AUTOSIZE);
  cv::imshow("grayimg", grayimg);
  cv::namedWindow("colorimg", cv::WINDOW_AUTOSIZE);
  cv::imshow("colorimg", colorimg);

  cv::waitKey(0);
    
  return 0;
}
