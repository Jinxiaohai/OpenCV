#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture cap;
  cap.open(string(argv[1]));

  cv::Mat frame;
  while (true)
    {
      cap >> frame;
      if(frame.empty()) break;
      cv::imshow("Example3", frame);
      if(cv::waitKey(33) >= 0) break;
    }
  return 0;
}
