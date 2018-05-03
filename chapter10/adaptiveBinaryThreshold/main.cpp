#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc != 7) {
    cout << "Usage: " << argv[0] << " fixed_threshold invert(0=off|1=on) "
         << "adaptive_type(0=mean|1=gaussian) block_size offset image\n"
         << "Example: " << argv[0] << " 100 1 0 15 10 fruits.jpg\n";
    return -1;
  }

  double fixed_threshold = static_cast<double>(atof(argv[1]));
  int threshhold_type =
      atoi(argv[2]) ? cv::THRESH_BINARY : cv::THRESH_BINARY_INV;
  int adaptive_method = atoi(argv[3]) ? cv::ADAPTIVE_THRESH_MEAN_C
                                      : cv::ADAPTIVE_THRESH_GAUSSIAN_C;

  int block_size = atoi(argv[4]);
  double offset = static_cast<double>(atof(argv[5]));
  cv::Mat Igray = cv::imread(argv[6], cv::IMREAD_GRAYSCALE);

  if (Igray.empty()) {
    cout << "open error." << endl;
  }

  cv::Mat It, Iat;
  cv::threshold(Igray, It, fixed_threshold, 255, threshhold_type);
  cv::adaptiveThreshold(Igray, Iat, 255, adaptive_method, threshhold_type,
                        block_size, offset);

  cv::imshow("Raw", Igray);
  cv::imshow("Threshold", It);
  cv::imshow("Adaptive Threshold", Iat);
  cv::waitKey(0);

  return 0;
}
