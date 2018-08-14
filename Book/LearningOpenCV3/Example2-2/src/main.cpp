#include <iostream>

#include "opencv2/highgui/highgui.hpp"

int main(int argc, char *argv[])
{
  cv::Mat img = cv::imread(argv[1], -1);
  if(img.empty()){
    std::cout << "图片不存在" << std::endl;
    return -1;
  }

  cv::namedWindow("Example2", cv::WINDOW_AUTOSIZE);
  cv::imshow("Example2", img);
  cv::waitKey(0);

  cv::destroyWindow("Example2");
  return 0;
}
