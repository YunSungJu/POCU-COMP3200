#pragma once

namespace lab8
{
	template <typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();
		bool Add(const T& t);
		bool Remove(const T& t);
		const T& Get(unsigned int index);
		T& operator[](unsigned int index);
		int GetIndex(const T& t);
		size_t GetSize();
		size_t GetCapacity();

	private:
		T mArray[N];
		size_t mLength;
	};
	
	template <typename T, size_t N> FixedVector<T, N>::FixedVector()
		: mLength(0)
	{
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Add(const T& t)
	{
		if (mLength != N)
		{
			mArray[mLength] = t;
			mLength++;
			return true;
		}
		else
		{
			return false;
		}
	}

	template <typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T& t)
	{
		bool isT = false;
		unsigned int idx = 0;

		for (; idx < mLength; idx++)
		{
			if (mArray[idx] == t && isT == false)
			{
				isT = true;
				for (unsigned int i = 0; i < mLength - idx - 1; i++)
				{
					mArray[idx + i] = mArray[idx + i + 1];
				}
				mLength--;

				return isT;
			}
		}
		return isT;
	}

	template <typename T, size_t N>
	const T& FixedVector<T, N>::Get(unsigned int index)
	{	
		const T& result = mArray[index];

		return result;
	}

	template <typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int index)
	{
		T& result = mArray[index];
		return result;
	}

	template <typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T& t)
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (mArray[i] == t)
			{
				return i;
			}
		}
		return -1;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetSize()
	{
		return mLength;
	}

	template <typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity()
	{
		return N;
	}


}