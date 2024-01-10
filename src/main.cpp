#include "../include/interfaces.hpp"
#include <opencv2/opencv.hpp>

using namespace std;


//! the main function for Navi
/*!
  \param argc number of arguments
  \param argv argument vector
 
   \return exit status
 */
int main(int argc, char* argv[])
{
	cv::VideoCapture webcam_cap;
	cv::Mat web_frame;
	interfaces::start_webcam(webcam_cap);
	interfaces::start_websocket(&web_frame);

	while (1) {
		webcam_cap >> web_frame;
	}
	return 0;
}
