#include <iostream>

#include "opencv2/opencv.hpp"

int main(int argc, char *argv[])
{
  cv::namedWindow("Example2_11", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

  cv::VideoCapture capture;
  if(argc > 1){
    capture.open(argv[1]);
  }
  else{
    capture.open(0);
  }

  double fps = capture.get(cv::CAP_PROP_FPS);
  cv::Size size(static_cast<int>(capture.get(cv::CAP_PROP_FRAME_WIDTH)),
		static_cast<int>(capture.get(cv::CAP_PROP_FRAME_HEIGHT)));

  cv::VideoWriter writer;
  writer.open("/home/xiaohai/Github/OpenCV/Book/LearningOpenCV3/Example2-11/data/video.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

  cv::Mat logpolar_frame, bgr_frame;
  while (true)
    {
      capture >> bgr_frame;
      if(bgr_frame.empty()){
	break;
      }
      cv::imshow("Example2_11", bgr_frame);
      
      cv::Canny(bgr_frame, logpolar_frame, 2, 100, 3, true);
      // cv::logPolar(bgr_frame, logpolar_frame,
      // 		   cv::Point2f(bgr_frame.cols/2, bgr_frame.rows/2),
      // 		   40, cv::WARP_FILL_OUTLIERS);

      cv::imshow("Log_Polar", logpolar_frame);
      writer << logpolar_frame;

      if(cv::waitKey(10) == 27){
	break;
      }
    }
  capture.release();
  writer.release();
  return 0;
}
