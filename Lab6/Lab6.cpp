#include <limits>

#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		if (v.size() != 0)
		{
			int sum = 0;

			for (unsigned int i = 0; i < v.size(); i++)
			{
				sum += v[i];
			}

			return sum;
		}
		return 0;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() != 0)
		{
			int min = v[0];

			for (unsigned int i = 1; i < v.size(); i++)
			{
				if (v[i] < min)
				{
					min = v[i];
				}
			}

			return min;
		}
		return std::numeric_limits<int>::max();
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() != 0)
		{
			int max = v[0];

			for (unsigned int i = 1; i < v.size(); i++)
			{
				if (max < v[i])
				{
					max = v[i];
				}
			}

			return max;
		}
		return std::numeric_limits<int>::min();
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() != 0)
		{
			float sum = static_cast<float>(Sum(v));

			float average = sum / v.size();

			return average;
		}

		return 0.0f;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		std::vector v1(v);

		SortDescending(v1);

		if (v1.size() == 0)
		{
			return 0;
		}

		int now = v1[0];
		int tempNow = v1[0];
		int max = 0;
		int tempMax = 0;

		for (unsigned int i = 0; i < v1.size(); i++)
		{
			if (tempNow == v1[i])
			{
				tempMax++;
			}
			else
			{
				if (max < tempMax)
				{
					max = tempMax;
					now = v1[i - 1];
				}
				tempMax = 1;
				tempNow = v1[i];
			}
		}

		if (max < tempMax)
		{
			max = tempMax;
			now = tempNow;
		}

		return now;
	}

	void SortDescending(std::vector<int>& v)
	{
		for (unsigned int i = 0; i < v.size(); i++)
		{
			for (unsigned int j = 0; j < v.size() - 1 - i; j++)
			{
				if (v[j] < v[j + 1])
				{
					int temp = v[j + 1];
					v[j + 1] = v[j];
					v[j] = temp;
				}
			}
		}
	}

}