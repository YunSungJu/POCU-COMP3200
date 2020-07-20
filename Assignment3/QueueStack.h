#pragma once
#include <stack>
#include <queue>
#include <limits>
#include <cmath>

namespace assignment3
{
	template <typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int maxStackSize);
		void Enqueue(T number);
		T Peek();
		T Dequeue();
		T Max();
		T Min();
		double Average();
		T Sum();
		unsigned int Count();
		unsigned int StackCount();

	private:
		unsigned int mMaxStackSize;
		std::queue<std::stack<T>> mQueueStack;
		T mSum;
	};

	template <typename T> QueueStack<T>::QueueStack(unsigned int maxStackSize)
		: mMaxStackSize(maxStackSize), mSum(0)
	{
	}

	template <typename T>
	void QueueStack<T>::Enqueue(T number)
	{
		if (mQueueStack.size() != 0)
		{
			std::stack<T>& stack = mQueueStack.back();

			if (stack.size() == mMaxStackSize)
			{
				std::stack<T> newStack;
				newStack.push(number);
				mQueueStack.push(newStack);
				mSum += number;
			}
			else
			{
				stack.push(number);
				mSum += number;
			}
		}
		else
		{
			std::stack<T> stack;
			stack.push(number);
			mQueueStack.push(stack);
			mSum += number;
		}

	}

	template <typename T>
	T QueueStack<T>::Peek()												//not empty
	{
		std::stack<T> frontStack = mQueueStack.front();

		return frontStack.top();
	}

	template <typename T>
	T QueueStack<T>::Dequeue()											//not empty
	{
		std::stack<T>& stack = mQueueStack.front();
		T result = stack.top();

		if (stack.size() != 1)
		{
			stack.pop();

			mSum -= result;
			return result;
		}
		else
		{
			stack.pop();
			mQueueStack.pop();

			mSum -= result;
			return result;
		}
	}

	template <typename T>
	T QueueStack<T>::Max()
	{
		if (mQueueStack.size() != 0)
		{
			std::stack<T> stack = mQueueStack.front();
			std::queue<std::stack<T>> copy = mQueueStack;
			T max = stack.top();

			for (unsigned int i = 0; i < mQueueStack.size(); i++)
			{
				stack = copy.front();
				unsigned int stackSize = stack.size();

				for (unsigned int i = 0; i < stackSize; i++)
				{
					if (max < stack.top())
					{
						max = stack.top();
					}
					stack.pop();
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
	T QueueStack<T>::Min()
	{
		if (mQueueStack.size() != 0)
		{
			std::stack<T> stack = mQueueStack.front();
			std::queue<std::stack<T>> copy = mQueueStack;
			T min = stack.top();

			for (unsigned int i = 0; i < mQueueStack.size(); i++)
			{
				stack = copy.front();
				unsigned int stackSize = stack.size();

				for (unsigned int i = 0; i < stackSize; i++)
				{
					if (stack.top() < min)
					{
						min = stack.top();
					}
					stack.pop();
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
	double QueueStack<T>::Average()										//not empty
	{
		/*if (mQueueStack.size() == 0)
		{
			return 0;
		}

		std::stack<T> stack = mQueueStack.front();
		std::queue<std::stack<T>> copy = mQueueStack;
		double average = 0;
		unsigned int totalSize = 0;

		for (unsigned int i = 0; i < mQueueStack.size(); i++)
		{
			stack = copy.front();
			unsigned int stackSize = stack.size();

			for (unsigned int i = 0; i < stackSize; i++)
			{
				average += stack.top();
				stack.pop();
				totalSize++;
			}
			copy.pop();
		}

		average = static_cast<double>(average) / totalSize;
		average = round(average * 1000) / 1000;

		return average;*/

		double average = static_cast<double>(mSum) / Count();
		average = round(average * 1000) / 1000;

		return average;

	}

	template <typename T>
	T QueueStack<T>::Sum()
	{
		/*if (mQueueStack.size() == 0)
		{
			return 0;
		}

		std::stack<T> stack = mQueueStack.front();
		std::queue<std::stack<T>> copy = mQueueStack;
		T sum = 0;

		for (unsigned int i = 0; i < mQueueStack.size(); i++)
		{
			stack = copy.front();
			unsigned int stackSize = stack.size();

			for (unsigned int i = 0; i < stackSize; i++)
			{
				sum += stack.top();
				stack.pop();
			}
			copy.pop();
		}

		return sum;*/

		if (mQueueStack.size() == 0)
		{
			return 0;
		}
		return mSum;
	}

	template <typename T>
	unsigned int QueueStack<T>::Count()
	{
		unsigned int totalSize = 0;

		if (mQueueStack.size() != 0)
		{
			std::stack<T> stack;
			std::queue<std::stack<T>> copy = mQueueStack;

			for (unsigned int i = 0; i < mQueueStack.size(); i++)
			{
				stack = copy.front();
				totalSize += stack.size();
				copy.pop();
			}
			return totalSize;
		}
		else
		{
			return totalSize;
		}

	}

	template <typename T>
	unsigned int QueueStack<T>::StackCount()
	{
		return mQueueStack.size();
	}


}