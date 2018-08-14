#include "opencv2/opencv.hpp"

#include "example2_5.h"

int main(int argc, char *argv[])
{
  cv::Mat mat = cv::imread(argv[1], -1);

  example2_5(mat);
  
  return 0;
}

