#pragma once

#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(const Storage<T>& other);
		Storage<T>& operator=(const Storage<T>& other);
		Storage(Storage<T>&& other);
		Storage<T>& operator=(Storage<T>&& other);
		~Storage();

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;

		std::unique_ptr<T[]> mArray;
		unsigned int mSize;
	};

	template<typename T> Storage<T>::Storage(unsigned int length)
		: mSize(length)
	{
		mArray.reset(new T[length]);
		for (unsigned int i = 0; i < length; i++)
		{
			mArray[i] = T();
		}
	}

	template<typename T> Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mSize(length)
	{
		mArray.reset(new T[length]);

		for (unsigned int i = 0; i < length; i++)
		{
			mArray[i] = T(initialValue);
		}
	}

	template<typename T> Storage<T>::Storage(const Storage<T>& other)
		: mSize(other.mSize)
	{
		if (other.mArray != mArray)
		{
			mArray.reset(new T[mSize]);

			for (unsigned int i = 0; i < mSize; i++)
			{
				mArray[i] = other.mArray[i];
			}
		}
	}

	template<typename T> Storage<T>& Storage<T>::operator=(const Storage<T>& other)
	{
		if (mArray == other.mArray)
		{
			return *this;
		}
		mSize = other.mSize;
		mArray.reset(new T[mSize]);

		for (unsigned int i = 0; i < mSize; i++)
		{
			mArray[i] = other.mArray[i];
		}
		return *this;
	}

	template<typename T> Storage<T>::Storage(Storage<T>&& other)
	{
		if (other.mArray != mArray)
		{
			mSize = other.mSize;
			mArray = std::move(other.mArray);
			other.mArray.reset();
		}
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage<T>&& other)
	{
		if (other.mArray != mArray)
		{
			mSize = other.mSize;
			mArray = std::move(other.mArray);
			other.mArray = nullptr;

			return *this;
		}
		return other;
	}

	template<typename T> Storage<T>::~Storage()
	{
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index < mSize)
		{
			mArray[index] = data;
			return true;
		}
		return false;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		if (mArray == nullptr)
		{
			return 0;
		}
		return mSize;
	}
}