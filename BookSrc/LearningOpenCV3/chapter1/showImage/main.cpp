#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  ///
  /// \brief first example
  ///
  //  cv::Mat srcImage =
  //      cv::imread("/home/xiaohai/Github/learnOpenCV/Picture/test.jpg");
  //  cv::imshow("title name", srcImage);
  //  cv::waitKey(0);

  ///
  /// \brief second example
  ///
  //  cv::Mat srcImage =
  //      cv::imread("/home/xiaohai/Github/learnOpenCV/Picture/test.jpg");
  //  cv::imshow("src", srcImage);

  //  cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15,
  // 15));
  //  cv::Mat dstImage;
  //  cv::erode(srcImage, dstImage, element);
  //  cv::imshow("erode", dstImage);
  //  cv::waitKey(0);

  ///
  /// \brief third example
  ///
  cv::Mat srcImage =
      cv::imread("/home/xiaohai/Github/learnOpenCV/Picture/avtar.jpg");

  cv::Mat edge, grayImage;
  cv::cvtColor(srcImage, grayImage, CV_BGR2GRAY);
  cv::blur(grayImage, edge, cv::Size(3, 3));

  cv::Canny(edge, edge, 3, 9, 3);
  cv::imshow("canny", edge);
  cv::imwrite("picture.jpg", edge);
  cv::waitKey(0);

  return 0;
}
