#include <string>
#include <fstream>
#include <iostream>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int gSliderPosition = 0;
int gRun = 1, gDontSet = 0;
cv::VideoCapture gCap;

void onTracbarSlide(int pos, void *) {
  gCap.set(cv::CAP_PROP_POS_FRAMES, pos);

  /*! if()调用进入单步模式 */
  if (!gDontSet) {
    gRun = 1;
  }
  gDontSet = 0;
}

int main(int argc, char *argv[]) {
  cv::namedWindow("Example2_4", cv::WINDOW_AUTOSIZE);
  gCap.open(std::string(argv[1]));
  int frames = static_cast<int>(gCap.get(cv::CAP_PROP_FRAME_COUNT));
  int frameWidth = static_cast<int>(gCap.get(cv::CAP_PROP_FRAME_WIDTH));
  int frameHeight = static_cast<int>(gCap.get(cv::CAP_PROP_FRAME_HEIGHT));

  std::cout << "Video has " << frames << " frames of dimensions(" << frameWidth
            << ", " << frameHeight << ")." << std::endl;

  cv::createTrackbar("Position", "Example2_4", &gSliderPosition, frames,
                     onTracbarSlide);

  cv::Mat frame;
  while (true) {
    if (gRun != 0) {
      gCap >> frame;
      if (frame.empty()) {
        break;
      }
      int currentPosition = static_cast<int>(gCap.get(cv::CAP_PROP_POS_FRAMES));
      gDontSet = 1;

      cv::setTrackbarPos("Position", "Example2_4", currentPosition);
      cv::imshow("Example2_4", frame);

      gRun -= 1;
    }

    char c = static_cast<char>(cv::waitKey(10));
    switch (c) {
      case 's':
        gRun = 1;
        std::cout << "Single step, run = " << gRun << std::endl;
        break;
      case 'r':
        gRun = -1;
        std::cout << "Run mode, run = " << gRun << std::endl;
        break;
    case char(27):
        break;
      default:
        break;
    }
  }
  return 0;
}
