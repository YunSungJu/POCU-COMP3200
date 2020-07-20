#pragma once
#include <queue>

namespace lab9
{
	template <typename T>
	class ObjectPool
	{
	public:
		ObjectPool() = delete;
		ObjectPool(const ObjectPool& pool) = delete;
		ObjectPool& operator=(const ObjectPool&) = delete;

		ObjectPool(size_t maxPoolSize);
		~ObjectPool();
		

		T* Get();
		void Return(T* object);
		size_t GetFreeObjectCount();
		size_t GetMaxFreeObjectCount();

	private:
		size_t mMaxPoolSize;
		std::queue<T*> mObjectPool;
	};

	template <typename T> ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
	{
	}

	template <typename T> ObjectPool<T>::~ObjectPool()
	{
		if (mObjectPool.size() != 0)
		{
			unsigned int size = mObjectPool.size();
			for (unsigned int i = 0; i < size; i++)
			{
				T* object = mObjectPool.front();
				mObjectPool.pop();
				delete object;
			}
		}
	}

	template <typename T>
	T* ObjectPool<T>::Get()
	{
		if (mObjectPool.size() == 0)
		{
			return new T;
		}
		else
		{
			T* object = mObjectPool.front();
			mObjectPool.pop();
			return object;
		}
	}

	template <typename T>
	void ObjectPool<T>::Return(T* object)
	{
		if (mObjectPool.size() < mMaxPoolSize)
		{
			mObjectPool.push(object);
		}
		else
		{
			delete object;
		}
	}

	template <typename T>
	size_t ObjectPool<T>::GetFreeObjectCount()
	{
		return mObjectPool.size();
	}

	template <typename T>
	size_t ObjectPool<T>::GetMaxFreeObjectCount()
	{
		return mMaxPoolSize;
	}
	
}