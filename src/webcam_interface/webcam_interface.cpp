#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

/*!
 * @brief Opens and displays the webcam video feed until termination.
 * @return Returns 0 upon successful completion, else returns -1.
 */
int webcam() {
   Mat myImage;
   namedWindow("Webcam Video Feed");
   VideoCapture cap(0);

   if (!cap.isOpened()) {
      cout << "No webcam feed detected" << endl;
      system("pause");
      return -1;
   }

   while (true) { 
      cap >> myImage;
      if (myImage.empty()) {
         break;
      }

      imshow("Webcam Video Feed", myImage);
      char c = (char)waitKey(25);
      if (c == 27) {
         break;
      }
   }
   cap.release();
   return 0;
}
