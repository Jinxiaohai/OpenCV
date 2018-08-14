#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  //  cv::Mat m = cv::Mat::eye(10, 10, CV_32FC1);
  //  std::cout << "Element (3, 3) is " << m.at<float>(3, 3) << std::endl;
  //  std::cout << "Element (3, 2) is " << m.at<float>(3, 2) << std::endl;

  int sz[3] = {4, 4, 4};
  /// three dimension (4 * 4 * 4), three channel
  cv::Mat m = cv::Mat::ones(600, 600, CV_32FC3);
  cv::Mat log;

  cv::namedWindow("xiaohai", cv::WINDOW_AUTOSIZE);
  cv::log(m, log);
  cv::imshow("xiaohai", log);
  cv::waitKey(0);
  return 0;
}
