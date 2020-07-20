#pragma once
#include "FixedVector.h"

namespace lab8
{
	template <size_t N>
	class FixedVector <bool, N>
	{
	public:
		FixedVector();
		bool Add(bool data);
		bool Remove(bool data);
		bool Get(unsigned int index);
		bool operator[](unsigned int index);
		int GetIndex(bool data);
		size_t GetSize();
		size_t GetCapacity();

	private:
		size_t mArray[N / 32 + 1] = { 0, };
		size_t mLength;
	};

	template <size_t N> FixedVector<bool, N>::FixedVector()
		: mLength(0)
	{
	}

	template <size_t N>
	bool FixedVector<bool, N>::Add(bool data)
	{
		if (mLength >= N)
		{
			return false;
		}

		if (data)
		{
			mArray[mLength / 32] = mArray[mLength / 32] | (1 << (mLength - 32 * (mLength / 32)));
			mLength++;
		}
		else
		{
			mArray[mLength / 32] = mArray[mLength / 32] & ~(1 << (mLength - 32 * (mLength / 32)));
			mLength++;
		}

		return true;
	}

	template <size_t N>
	bool FixedVector<bool, N>::Remove(bool data)
	{
		/*unsigned int idx = 0;

		for (; idx < mLength; idx++)
		{
			if ((mArray[idx / 32] & (1 << (idx - 32 * (idx / 32)))) == data)
			{
				for (unsigned int i = 0; i < mLength - idx; i++)
				{
					unsigned int idxf = idx + i + 1;
					unsigned int idxb = idx + i;

					size_t next = mArray[idxf / 32] & (1 << (idxf - 32 * (idxf / 32)));

					if (next != 0)
					{
						mArray[idxb / 32] = mArray[idxb / 32] | (1 << (idxb - 32 * (idxb / 32)));
					}
					else
					{
						mArray[idxb / 32] = mArray[idxb / 32] & ~(1 << (idxb - 32 * (idxb / 32)));
					}
				}
				size_t term = mLength - 1;
				mArray[mLength / 32] = mArray[mLength / 32] & ~(1 << (term - 32 * (term / 32)));
				mLength--;
				return true;
			}
		}
		return false;*/
		if (GetIndex(data) != -1)
		{
			int idx = GetIndex(data);
			for (unsigned int i = 0; i < mLength - idx; i++)
			{
				unsigned int idxf = idx + i + 1;
				unsigned int idxb = idx + i;

				size_t next = mArray[idxf / 32] & (1 << (idxf - 32 * (idxf / 32)));

				if (next != 0)
				{
					mArray[idxb / 32] = mArray[idxb / 32] | (1 << (idxb - 32 * (idxb / 32)));
				}
				else
				{
					mArray[idxb / 32] = mArray[idxb / 32] & ~(1 << (idxb - 32 * (idxb / 32)));
				}
			}
			size_t term = mLength - 1;
			mArray[mLength / 32] = mArray[mLength / 32] & ~(1 << (term - 32 * (term / 32)));
			mLength--;
			return true;
		}
		else
		{
			return false;
		}
	}

	template <size_t N>
	bool FixedVector<bool, N>::Get(unsigned int index)
	{
		return mArray[index / 32] & (1 << (index - 32 * (index / 32)));
	}

	template <size_t N>
	bool FixedVector<bool, N>::operator[](unsigned int index)
	{
		return mArray[index / 32] & (1 << (index - 32 * (index / 32)));
	}

	template <size_t N>
	int FixedVector<bool, N>::GetIndex(bool data)
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			bool result = mArray[i / 32] & (1 << (i - 32 * (i / 32)));
			if (result == data)
			{
				return static_cast<int>(i);
			}
		}
		return -1;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetSize()
	{
		return mLength;
	}

	template <size_t N>
	size_t FixedVector<bool, N>::GetCapacity()
	{
		return N;
	}
}