#include <iostream>
#include <opencv2/opencv.hpp>
#include "../../include/interfaces.hpp"

namespace interfaces {
  int start_webcam(cv::VideoCapture &c) {
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
      std::cerr << "WEBCAMINT: Couldn't open the webcam." << std::endl;
      return -1;
    }
    c = cap;
    std::cout << "WEBCAMINT: Successfully opened the webcam." << std::endl;
    return 0;
  }
}
