#include <iostream>
#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
  cv::Mat grayimg(600, 800, CV_8UC1);
  cv::Mat colorimg(600, 800, CV_8UC3);

  /*! loop gray image */
  for (cv::MatIterator_<uchar> iter = grayimg.begin<uchar>();
       iter != grayimg.end<uchar>();
       ++iter)
  {
    *iter = rand() % 255;
  }

  /*! loop color image */
  for (cv::MatIterator_<cv::Vec3b> iter = colorimg.begin<cv::Vec3b>();
       iter != colorimg.end<cv::Vec3b>();
       ++iter)
    {
      (*iter)[0] = rand() % 123;
      (*iter)[1] = rand() % 255;
      (*iter)[2] = rand() % 255;
    }

  cv::imshow("grayimg", grayimg);
  cv::imshow("colorimg", colorimg);

  cv::waitKey(0);
  return 0;
}
