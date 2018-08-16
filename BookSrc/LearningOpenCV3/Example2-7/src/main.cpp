#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
  cv::Mat img_bgr, img_gry, img_cny;

  cv::namedWindow("Example Gray", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Example Canny", cv::WINDOW_AUTOSIZE);

  img_bgr = cv::imread(argv[1], -1);

  cv::cvtColor(img_bgr, img_gry, cv::COLOR_BGR2GRAY);
  cv::imshow("Example Gray", img_gry);

  cv::Canny(img_gry, img_cny, 10, 100, 3, true);
  cv::imshow("Example Canny", img_cny);

  cv::waitKey(0);
  return 0;
}
