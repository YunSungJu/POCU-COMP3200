#include "Lab2.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

namespace lab2
{

	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		int number;
		std::string trash;

		out << std::setw(12) << "oct" << " " << std::setw(10) << "dec" << " " << std::setw(8) << "hex" << std::endl;
		out << std::setw(12) << std::setfill('-') << "" << " " << std::setw(10) << "" << " " << std::setw(8) << "" << std::endl;

		while (!in.eof())
		{
			in >> number;

			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
			{
				out << std::setw(12) << std::setfill(' ') << std::oct << number << " " << std::setw(10) << std::dec << number << " " << std::setw(8) << std::uppercase << std::hex << number << std::endl;
			}
		}
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float number;
		float max = -std::numeric_limits<float>::max();
		std::string trash;

		while (!in.eof())
		{
			in >> number;

			if (in.fail())
			{
				in.clear();
				in >> trash;
			}
			else
			{
				out << "     " << std::setw(15) << std::fixed << std::setprecision(3) << std::showpos << std::showpoint << std::internal << number << std::endl;
			}
			if (max <= number)
			{
				max = number;
			}
		}
		out << "max: " << std::setw(15) << std::fixed << std::setprecision(3) << std::showpos << std::showpoint << std::internal << max << std::endl;
	}
}