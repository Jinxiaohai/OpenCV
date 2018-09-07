#include <iostream>

#include "opencv2/opencv.hpp"

int main(int argc, char *argv[]) {
  cv::Mat mat;
  const int rows = 400;
  const int colums = 600;
  mat.create(rows, colums, CV_8UC3);

  for (int i = 0; i != rows; ++i) {
    for (int j = 0; j != colums; ++j) {
      cv::Vec3b pix;
      pix[0] = 0;
      pix[1] = 0;
      pix[2] = 255;
      mat.at<cv::Vec3b>(i, j) = pix;
    }
  }

  cv::imwrite("red.png", mat);
  cv::imshow("test", mat);
  cv::waitKey(0);
  return 0;
}
