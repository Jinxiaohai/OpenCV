#include <opencv2/highgui.hpp>
#include <opencv2/cvconfig.h>

int main(int argc, char *argv[]) {
  cv::Mat src1 = cv::imread(argv[1]);
  cv::Mat src2 = cv::imread(argv[2]);

  if (argc == 9 && !src1.empty() && !src2.empty()) {
    int x = atoi(argv[3]);
    int y = atoi(argv[4]);
    int w = atoi(argv[5]);
    int h = atoi(argv[6]);
    double alpha = static_cast<double>(atof(argv[7]));
    double beta = static_cast<double>(atof(argv[8]));

    cv::Mat roi1(src1, cv::Rect(x, y, w, h));
    cv::Mat roi2(src2, cv::Rect(0, 0, w, h));

    cv::addWeighted(roi1, alpha, roi2, beta, 0.0, roi1);

    cv::namedWindow("Alpha Blend", cv::WINDOW_AUTOSIZE);
    cv::imshow("Alpha Blend", src2);

    cv::waitKey(0);
  }

  return 0;
}
