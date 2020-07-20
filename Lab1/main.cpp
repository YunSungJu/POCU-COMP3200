#include <iostream>

int main()
{
	int a = 1;
	float* b = reinterpret_cast<float*>(&a);

	std::cout << b << std::endl;

	return 0;
}
