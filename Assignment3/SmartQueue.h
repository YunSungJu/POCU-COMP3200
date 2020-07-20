#pragma once
#include <queue>
#include <limits>
#include <cmath>

namespace assignment3
{
	template <typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T Max();
		T Min();
		double Average();
		T Sum();
		double Variance();
		double StandardDeviation();
		unsigned int Count();

	private:
		std::queue<T> mSmtQueue;
		double mSumOfExpSqure;
		T mSum;
	};

	template <typename T> SmartQueue<T>::SmartQueue()
		: mSumOfExpSqure(0), mSum(0)
	{
	}

	template <typename T>
	void SmartQueue<T>::Enqueue(T number)
	{
		mSmtQueue.push(number);

		mSumOfExpSqure += pow(static_cast<double>(number), 2);
		mSum += number;
	}

	template <typename T>
	T SmartQueue<T>::Peek()
	{
		return mSmtQueue.front();
	}

	template <typename T>
	T SmartQueue<T>::Dequeue()
	{
		T result = mSmtQueue.front();
		mSmtQueue.pop();

		mSumOfExpSqure -= pow(static_cast<double>(result), 2);
		mSum -= result;

		return result;
	}

	template <typename T>
	T SmartQueue<T>::Max()
	{
		if (mSmtQueue.size() != 0)
		{
			std::queue<T> copy = mSmtQueue;

			T max = copy.front();
			copy.pop();

			for (unsigned int i = 1; i < mSmtQueue.size(); i++)
			{
				if (max < copy.front())
				{
					max = copy.front();
				}
				copy.pop();
			}

			return max;
		}
		else
		{
			return std::numeric_limits<T>::lowest();
		}

	}

	template <typename T>
	T SmartQueue<T>::Min()
	{
		if (mSmtQueue.size() != 0)
		{
			std::queue<T> copy = mSmtQueue;

			T min = copy.front();
			copy.pop();

			for (unsigned int i = 1; i < mSmtQueue.size(); i++)
			{
				if (copy.front() < min)
				{
					min = copy.front();
				}
				copy.pop();
			}

			return min;
		}
		else
		{
			return std::numeric_limits<T>::max();
		}
	}

	template <typename T>
	double SmartQueue<T>::Average()
	{
		double average = static_cast<double>(mSum) / mSmtQueue.size();

		average = round(average * 1000) / 1000;

		return average;
	}

	template <typename T>
	T SmartQueue<T>::Sum()
	{
		return mSum;
	}

	template <typename T>
	double SmartQueue<T>::Variance()
	{
		return round(((mSumOfExpSqure / mSmtQueue.size()) - pow(static_cast<double>(mSum) / mSmtQueue.size(), 2)) * 1000) / 1000;
	}

	template <typename T>
	double SmartQueue<T>::StandardDeviation()
	{
		double variance = 0;
		double newAverageOfExpSqure = 0;
		double average = static_cast<double>(mSum) / mSmtQueue.size();
		double standardDeviation = 0;

		newAverageOfExpSqure = mSumOfExpSqure / mSmtQueue.size();
		variance = newAverageOfExpSqure - pow(average, 2);

		standardDeviation = sqrt(variance);
		standardDeviation = round(standardDeviation * 1000) / 1000;

		return standardDeviation;
	}

	template <typename T>
	unsigned int SmartQueue<T>::Count()
	{
		return mSmtQueue.size();
	}
}