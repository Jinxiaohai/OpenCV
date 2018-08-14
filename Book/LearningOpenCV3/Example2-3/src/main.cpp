#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char *argv[])
{
  cv::namedWindow("Example2-3", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture cap;
  cap.open(argv[1]);

  cv::Mat frame;
  while(true){
    cap >> frame;
    if(frame.empty()){
      break;
    }

    cv::imshow("Example2-3", frame);
    if(cv::waitKey(1000) >= 0){
      break;
    }
  }

  cv::destroyWindow("Example2-3");
  return 0;
}
