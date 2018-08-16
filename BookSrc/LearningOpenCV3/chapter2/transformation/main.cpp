#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  cv::Mat imag1, imag2;

  cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);

  imag1 = cv::imread(argv[1]);
  cv::imshow("Example1", imag1);

  cv::pyrDown(imag1, imag2);
  cv::imshow("Example2", imag2);

  cv::waitKey(0);
  return 0;
}
