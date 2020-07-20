#pragma once
#include <stack>
#include <limits>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		void Push(T number);
		T Pop();
		T Peek();
		T Max();
		T Min();
		double Average();
		T Sum();
		double Variance();
		double StandardDeviation();
		unsigned int Count();

	private:
		std::stack<T> mSmtStack;
		T mMax;
		T mMin;
		T mSum;
		double mExpOfSqures;
		double mSqureOfExp;
	};



	template <typename T> SmartStack<T>::SmartStack()
		: mExpOfSqures(0), mSqureOfExp(0), mSum(0)
	{
	}

	template <typename T>
	void SmartStack<T>::Push(T number)
	{
		if (mSmtStack.size() == 0)
		{
			mMin = number;
			mMax = number;
		}
		else
		{
			if (mMax < number)
			{
				mMax = number;
			}

			if (number < mMin)
			{
				mMin = number;
			}
		}
		mSum += number;
		mExpOfSqures += static_cast<double>(pow(number, 2));
		mSqureOfExp += static_cast<double>(number);
		mSmtStack.push(number);
	}

	template <typename T>
	T SmartStack<T>::Pop()
	{
		T result = mSmtStack.top();
		mSmtStack.pop();

		if (mSmtStack.size() == 0)
		{
			mSum -= result;
			mExpOfSqures -= static_cast<double>(pow(result, 2));
			mSqureOfExp -= static_cast<double>(result);
			return result;
		}

		if (result == mMax)
		{
			std::stack<T> copy = mSmtStack;
			unsigned int size = copy.size();
			T max = copy.top();
			copy.pop();

			for (unsigned int i = 1; i < size; i++)
			{
				if (max < copy.top())
				{
					max = copy.top();
				}
				copy.pop();
			}
			mMax = max;
			
		}

		if (result == mMin)
		{
			std::stack<T> copy = mSmtStack;
			unsigned int size = copy.size();
			T min = copy.top();
			copy.pop();

			for (unsigned int i = 1; i < size; i++)
			{
				if (copy.top() < min)
				{
					min = copy.top();
				}
				copy.pop();
			}
			mMin = min;
		}
		
		mSum -= result;
		mExpOfSqures -= static_cast<double>(pow(result, 2));
		mSqureOfExp -= static_cast<double>(result);

		return result;
	}

	template <typename T>
	T SmartStack<T>::Peek()
	{
		return mSmtStack.top();
	}

	template <typename T>
	T SmartStack<T>::Max()
	{
		if (mSmtStack.size() != 0)
		{
			return mMax;
		}
		else
		{
			return std::numeric_limits<T>::lowest();
		}
	}

	template <typename T>
	T SmartStack<T>::Min()
	{
		if (mSmtStack.size() != 0)
		{
			return mMin;
		}
		else
		{
			return std::numeric_limits<T>::max();
		}
	}

	template <typename T>
	double SmartStack<T>::Average()
	{
		/*if (mSmtStack.size() == 0)
		{
			return 0;
		}

		double sum = 0;
		std::stack<T> copy = mSmtStack;

		for (unsigned int i = 0; i < mSmtStack.size(); i++)
		{
			sum += static_cast<double>(copy.top());
			copy.pop();
		}

		double average = sum;

		average = average / mSmtStack.size();
		average = round(average * 1000) / 1000;

		return average;*/

		double average = static_cast<double>(mSum) / mSmtStack.size();
		average = round(average * 1000) / 1000;

		return average;
	}

	template <typename T>
	T SmartStack<T>::Sum()
	{
		/*if (mSmtStack.size() == 0)
		{
			return 0;
		}

		T sum = 0;
		std::stack<T> copy = mSmtStack;

		for (unsigned int i = 0; i < mSmtStack.size(); i++)
		{
			sum += copy.top();
			copy.pop();
		}

		return sum;*/

		return mSum;
	}

	template <typename T>
	double SmartStack<T>::Variance()
	{
		double variance = 0;
		double newExpOfSqures = mExpOfSqures;
		double newSqureOfExp = mSqureOfExp;

		newExpOfSqures = newExpOfSqures / mSmtStack.size();
		newSqureOfExp = pow(newSqureOfExp / mSmtStack.size(), 2);

		variance = newExpOfSqures - newSqureOfExp;
		variance = round(variance * 1000) / 1000;

		return variance;
	}

	template <typename T>
	double SmartStack<T>::StandardDeviation()
	{
		double variance = 0;
		double newExpOfSqures = mExpOfSqures;
		double newSqureOfExp = mSqureOfExp;
		double standardDeviation = 0;

		newExpOfSqures = newExpOfSqures / mSmtStack.size();
		newSqureOfExp = pow(newSqureOfExp / mSmtStack.size(), 2);

		variance = newExpOfSqures - newSqureOfExp;

		standardDeviation = sqrt(variance);
		standardDeviation = round(standardDeviation * 1000) / 1000;

		return standardDeviation;
	}

	template <typename T>
	unsigned int SmartStack<T>::Count()
	{
		return mSmtStack.size();
	}
}