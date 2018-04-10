#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
  cv::namedWindow("Example", cv::WINDOW_AUTOSIZE);

  cv::VideoCapture cap;
  if (argc == 1) {
    cap.open(0);
  } else {
    cap.open(argv[1]);
  }

  if (!cap.isOpened()) {
    std::cerr << "Couldn't open capture." << std::endl;
    return -1;
  }

  cv::Mat frame;
  cap >> frame;

  cv::imshow("Example", frame);

  cv::waitKey(0);
  return 0;
}
