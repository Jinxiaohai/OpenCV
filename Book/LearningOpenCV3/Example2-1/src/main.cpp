#include "opencv2/opencv.hpp"

/*! 
  \brief 展示一张图片

  该程序是我学习OpenCV的第一个程序，
  该程序的功能是展示一张图片。
  \param[in] argc 参数的个数
  \param[in] argv 其中argv[1]是图片的名字
  
  \return 0
*/
int main(int argc, char *argv[]) {
  cv::Mat img = cv::imread(argv[1], -1);
  if(img.empty()){
    return -1;
  }

  cv::namedWindow("Example2-1", cv::WINDOW_AUTOSIZE);
  cv::imshow("Example2-1", img);
  cv::waitKey(0);
  //cv::destroyWindow("Example2-1");
  
  return 0;
}
