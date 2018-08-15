#include <iostream>

#include "opencv2/core.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, char *argv[])
{
  cv::Mat src;

  /*! 使用缺省的设像头作为视频来源 */
  cv::VideoCapture cap(0);
  if(!cap.isOpened()){
    std::cerr << "ERROR! 不能打开摄像头。" << std::endl;
    return -1;
  }

  cap >> src;
  if(src.empty()){
    std::cerr << "ERROR! 帧的内容为空。" << std::endl;
    return -1;
  }
  bool isColor = (src.type() == CV_8UC3);

  cv::VideoWriter writer;
  writer.open("../data/video.avi", cv::VideoWriter::fourcc('M', 'J', 'P', 'G'),
	      25.0, src.size(), isColor);
  if(!writer.isOpened()){
    std::cerr << "ERROR! 打开失败。" << std::endl;
    return -1;
  }

  while (true)
    {
      if(!cap.read(src)){
	std::cerr << "ERROR! blank frame grabbed" << std::endl;
	break;
      }

      writer.write(src);
      cv::imshow("Live", src);

      if(cv::waitKey(20) == 27){
	break;
      }
    }
    
  return 0;
}
