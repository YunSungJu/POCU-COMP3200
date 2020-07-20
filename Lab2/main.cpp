#include "Lab2.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream in("testinput.txt");
	lab2::PrintIntegers(in, cout);
	in.close();

	return 0;
}