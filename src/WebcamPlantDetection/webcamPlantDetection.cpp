#include<opencv2/opencv.hpp> 
#include<iostream>
using namespace std;
using namespace cv;

Mat isGreen(const Mat& image) {
    Mat hsvImage;
    cvtColor(image, hsvImage, COLOR_RGB2HSV);

    Scalar lower(35, 60, 60);
    Scalar upper(80, 255, 255);

    Mat mask;
    inRange(hsvImage, lower, upper, mask);
    return mask;
}

int main() {
   Mat myImage; 
   namedWindow("Video Player"); 
   VideoCapture cap(0); 

   if (!cap.isOpened()) { 
      cout << "No video stream detected" << endl;
      system("pause");
      return-1;
   }

   while (true) { 
      cap >> myImage;
      if (myImage.empty()) {
         break;
      }
      
      Mat greenMask = isGreen(myImage);

      imshow("Video Player", greenMask); 
      char c = (char)waitKey(25); 
      if (c == 27) { 
         break;
      }
   }
   cap.release(); 
   return 0;
}
