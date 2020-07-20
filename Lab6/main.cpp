#include <iostream>
#include <cassert>

#include "Lab6.h"

int main()
{
	std::vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(4);
	v.push_back(12);
	v.push_back(7);
	v.push_back(11);

	
	int numWithMaxOccurence = lab6::NumberWithMaxOccurrence(v);
	std::cout << numWithMaxOccurence << std::endl;
	return 0;

}