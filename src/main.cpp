#include "submodule.hpp"
#include "main.hpp"
#include "arg.hpp"

using namespace std;
int main(int argc, char* argv[])
{
	int value = getValue();
	value += argValue();
	cout << helloworld << value << endl;
	return 0;
}