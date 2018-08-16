#include "opencv2/opencv.hpp"
#include "example2_5.h"

void example2_5(const cv::Mat &image){
  /*! 创建输入和输出图像展示的Window */
  cv::namedWindow("Example2_5-in", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Example2_5-out", cv::WINDOW_AUTOSIZE);

  /*! 展示输入图像 */
  cv::imshow("Example2_5-in", image);

  /*! 创建输出图像 */
  cv::Mat out;

  /*! 平滑处理 */
  cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
  cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

  /*! 展示结果 */
  cv::imshow("Example2_5-out", out);

  /*! 等待按键 */
  cv::waitKey(0);
}
