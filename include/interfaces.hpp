#ifndef WEBCAM_INTERFACE_HPP
#define WEBCAM_INTERFACE_HPP

#include <opencv2/opencv.hpp>
namespace interfaces {
  int start_webcam(cv::VideoCapture &c);
  int start_websocket(cv::Mat *frame);
}
#endif
