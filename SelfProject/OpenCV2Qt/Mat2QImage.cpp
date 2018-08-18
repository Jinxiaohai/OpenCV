QImage Mat2QImage(const cv::Mat &src)
{
  //! make the same cv::Mat
  cv::Mat temp;
  //! cvtColor Makes a copt, that what i need
  cvtColor(src, temp, cv::COLOR_BGR2RGB); 
  QImage dest((const uchar *) temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
  //! enforce deep copy, see documentation 
  dest.bits(); 

  return dest;
}

cv::Mat QImage2Mat(const QImage & src)
{
  cv::Mat tmp(src.height(),src.width(),CV_8UC3,(uchar*)src.bits(),src.bytesPerLine());
  //! deep copy just in case (my lack of knowledge with open cv)
  cv::Mat result; 
  cvtColor(tmp, result,cv::COLOR_RGB2BGR);
  return result;
}
