#include <opencv2/opencv.hpp> 
#include <iostream>
using namespace std;
using namespace cv;

Mat isGreen(const Mat& image) {
    Mat hsvImage;
    Mat mask;
    Scalar lower(35, 60, 60);
    Scalar upper(80, 255, 255);
    cvtColor(image, hsvImage, COLOR_RGB2HSV);
    inRange(hsvImage, lower, upper, mask);
    return mask;
}

int test_isGreen() {
   Mat myImage; 
   VideoCapture cap(0); 
   if (!cap.isOpened())
      return 5; // IO Error Code on Linux, Access Denied Error Code on Windows

   while (true) { 
      cap >> myImage;
      if (myImage.empty())
         break;
      Mat greenMask = isGreen(myImage);
      imshow("Video Player", greenMask); 
      char c = (char)waitKey(25); 
      if (c == 27) 
         break;
   }
   cap.release(); 
   return 0;
}
