#include "submodule.hpp"
#include "main.hpp"
#include "arg.hpp"
#include "grass_killer.hpp"
#include "webcam_interface.hpp"

using namespace std;


//! the main function for Navi
/*!
  \param argc number of arguments
  \param argv argument vector
 
   \return nothing
 */
int main(int argc, char* argv[])
{
	int value = getValue();
	value += argValue();
	cout << helloworld << value << endl;
	kill_some_grass();

    webcam();
	return 0;
}