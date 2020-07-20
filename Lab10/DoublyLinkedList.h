#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;
		
	private:
		unsigned int mLength;
		std::shared_ptr<Node<T>> mHead;
	};

	template<typename T> DoublyLinkedList<T>::DoublyLinkedList()
		: mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mLength == 0)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			mLength++;
		}
		else
		{
			std::shared_ptr<Node<T>> last = mHead;

			for (unsigned int i = 0; i < mLength - 1; i++)
			{
				last = last->Next;
			}
			last->Next = std::make_shared<Node<T>>(std::move(data), last);
			last.reset();
			mLength++;
		}
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		if (mLength == 0)
		{
			mHead = std::make_shared<Node<T>>(std::move(data));
			mLength++;
		}
		else if (mLength <= index)
		{
			std::shared_ptr<Node<T>> last = mHead;

			for (unsigned int i = 0; i < mLength - 1; i++)
			{
				last = last->Next;
			}
			last->Next = std::make_shared<Node<T>>(std::move(data), last);
			last.reset();
			mLength++;
		}
		else if (index == 0)
		{
			std::shared_ptr<Node<T>> last = mHead;

			mHead = std::make_shared<Node<T>>(std::move(data));
			mHead->Next = last;
			last->Previous = mHead;
			last.reset();
			mLength++;
		}
		else
		{
			std::shared_ptr<Node<T>> last = mHead;

			for (unsigned int i = 0; i < index - 1; i++)
			{
				last = last->Next;
			}

			std::shared_ptr<Node<T>> middle = std::make_shared<Node<T>>(std::move(data), last);     
			middle->Next = last->Next;
			last->Next = middle;
			middle->Next->Previous = middle;
			middle.reset();
			last.reset();
			mLength++;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		if (mLength == 0)
		{
			return false;
		}

		if (*(mHead->Data) == data)
		{
			mHead = mHead->Next;
			mLength--;
			return true;
		}
		else
		{
			std::shared_ptr<Node<T>> last = mHead;

			for (unsigned int i = 1; i < mLength - 1; i++)
			{
				last = last->Next;
				if (*(last->Data) == data)
				{
					last->Next->Previous = last->Previous;
					std::shared_ptr<Node<T>> pre = last->Previous.lock();
					pre->Next = last->Next;
					mLength--;
					pre.reset();
					last.reset();
					return true;
				}
			}

			last = last->Next;
			if (*(last->Data) == data)
			{
				std::shared_ptr<Node<T>> pre = last->Previous.lock();
				pre->Next = nullptr;
				mLength--;
				pre.reset();
				last.reset();
				return true;
			}

			last.reset();
		}
		return false;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> last = mHead;
		
		for (unsigned int i = 0; i < mLength; i++)
		{
			if (*(last->Data) == data)
			{
				last.reset();
				return true;
			}
			last = last->Next;
		}

		last.reset();
		return false;
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (mLength <= index)
		{
			return nullptr;
		}
		else
		{
			std::shared_ptr<Node<T>> result = mHead;

			for (unsigned int i = 0; i < index; i++)
			{
				result = result->Next;
			}
			return result;
		}
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}