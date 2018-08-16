#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
  cv::Mat img1, img2;

  cv::namedWindow("Example2_6_1", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Example2_6_2", cv::WINDOW_AUTOSIZE);

  img1 = cv::imread(argv[1], -1);
  cv::imshow("Example2_6_1", img1);

  cv::pyrDown(img1, img2);
  cv::imshow("Example2_6_2", img2);

  cv::waitKey(0);
  return 0;
}
