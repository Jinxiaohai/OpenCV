#include <fstream>
#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;

int g_slider_position = 0;
int g_run = 1;
int g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *) {
  g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
  if (!g_dontset) {
    g_run = 1;
  }
  g_dontset = 0;
}

int main(int argc, char **argv) {
  cv::namedWindow("xiaohai", cv::WINDOW_AUTOSIZE);
  g_cap.open(string(argv[1]));
  int frames = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_COUNT));
  int tmpw = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_WIDTH));
  int tmph = static_cast<int>(g_cap.get(cv::CAP_PROP_FRAME_HEIGHT));
  cout << "Video has " << frames << " frames of dimensions(" << tmpw << tmph
       << ")" << endl;
  cv::createTrackbar("Position", "xiaohai", &g_slider_position, frames,
                     onTrackbarSlide);

  cv::Mat frame;
  for (;;) {
    if (g_run != 0) {
      g_cap >> frame;
      if (frame.empty()) {
        break;
      }
      int current_pos = static_cast<int>(g_cap.get(cv::CAP_PROP_POS_FRAMES));
      g_dontset = 1;

      cv::setTrackbarPos("Position", "xiaohai", current_pos);
      cv::imshow("xiaohai", frame);

      g_run -= 1;
    }
    char c = static_cast<char>(cv::waitKey(10));
    if (c == 's') {
      g_run = 1;
      cout << "Single step, run = " << g_run << endl;
    }
    if (c == 'r') {
      g_run = 1;
      cout << "Run mode, run = " << g_run << endl;
    }
    if (c == 27) {
      break;
    }
  }
  return 0;
}
