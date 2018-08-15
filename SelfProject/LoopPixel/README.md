# 使用OpenCV进行像素的遍历
___
很或时候我们需要对图像中的每个像素进行操作，
OpenCV中像素的操作主要有三种。

### at()函数
函数at()来实现读取矩阵中的某个像素，或者对像素惊醒赋值。
```C++
/*! 读取第i行第j列的像素值。 */
uchar value = grayimg.at<uchar>(i, j);
/*! 对读出的像素进行赋值为111. */
grayimg.at<uchar>(i, j) = 111;
```

完整的例子如下：
```C++
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
```
