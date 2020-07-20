#include <cassert>

#include "Lab7.h"

int main()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	std::vector<char> v2;
	v2.push_back('a');
	v2.push_back('b');
	v2.push_back('c');

	std::vector<int> v3;
	v3.push_back(4);
	v3.push_back(5);
	v3.push_back(6);

	std::map<char, int> m1;
	m1['a'] = 1;
	m1['b'] = 2;
	m1['c'] = 3;

	std::map<char, int> m2;
	m1['d'] = 4;
	m1['e'] = 5;
	m1['f'] = 6;

	std::map<int, char> m = lab7::ConvertVectorsToMap(v1, v2);
	{
		std::map<int, char>::const_iterator it = m.begin();

		assert(it->first == 1);
		assert(it->second == 'a');
		it++;
		assert(it->first == 2);
		assert(it->second == 'b');
		it++;
		assert(it->first == 3);
		assert(it->second == 'c');
	}


	return 0;
}