#include <cmath>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
  cv::Mat grayimg(600, 800, CV_8UC1);
  cv::Mat colorimg(600, 800, CV_8UC3);

  for (int i = 0; i != grayimg.rows; ++i)
    {
      /*! 获取第i行的首地址 */
      uchar *p = grayimg.ptr<uchar>(i);
      for (int j = 0; j != grayimg.cols; ++j)
	{
	  p[j] = (i+j)%255;
	}
    }

  for(int i = 0; i != colorimg.rows; ++i)
    {
      /*! 获取第i行的首地址 */
      cv::Vec3b *p = colorimg.ptr<cv::Vec3b>(i);
      for (int j = 0; j != colorimg.cols; ++j)
	{
	  p[j][0] = i % 255; /*!< Blue */
	  p[j][1] = j % 255; /*!< Green */
	  p[j][2] = std::abs(i-j) % 255; /*!< Red */
	}
    }

  cv::imshow("grayimg", grayimg);
  cv::imshow("colorimg", colorimg);

  cv::waitKey(0);
  
  return 0;
}
