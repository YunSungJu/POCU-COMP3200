#pragma once

#include <memory>
#include <vector>

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;

		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static void InorderRecursive(const std::shared_ptr<TreeNode<T>> startNode, std::vector<T>& result);

	private:
		std::shared_ptr<TreeNode<T>> mHead;
	};

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<TreeNode<T>> pointer = mHead;

		if (pointer == nullptr)
		{
			mHead = std::make_shared<TreeNode<T>>(std::move(data));
		}
		else
		{
			bool right = 0;

			while (true)
			{
				if (* (pointer->Data) < *data)
				{
					if (pointer->Right != nullptr)
					{
						pointer = pointer->Right;
						right = 1;
					}
					else
					{
						right = 1;
						break;
					}

				}
				else
				{
					if (pointer->Left != nullptr)
					{
						pointer = pointer->Left;
						right = 0;
					}
					else
					{
						right = 0;
						break;
					}
				}
			}

			if (right)
			{
				pointer->Right = std::make_shared<TreeNode<T>>(pointer, std::move(data));
			}
			else
			{
				pointer->Left = std::make_shared<TreeNode<T>>(pointer, std::move(data));
			}
		}
		pointer.reset();
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mHead;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		std::shared_ptr<TreeNode<T>> pointer = mHead;

		if (pointer == nullptr)
		{
			pointer.reset();
			return false;
		}
		else
		{
			while (pointer != nullptr)
			{
				if (*(pointer->Data) == data)
				{
					pointer.reset();
					return true;
				}
				else
				{
					*(pointer->Data) < data ? pointer = pointer->Right : pointer = pointer->Left;
				}
			}
		}
		pointer.reset();
		return false;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		std::shared_ptr<TreeNode<T>> pointer = mHead;

		if (Search(data) == false)
		{
			pointer.reset();
			return false;
		}
		else
		{
			if (*(pointer->Data) == data)
			{
				if (mHead->Left == nullptr && mHead->Right == nullptr)
				{
					mHead.reset();
					pointer.reset();
					return true;
				}
				else if (mHead->Left == nullptr)
				{
					mHead->Right->Parent.reset();
					mHead = mHead->Right;
					pointer.reset();
					return true;
				}
				else if (mHead->Right == nullptr)
				{
					mHead->Left->Parent.reset();
					mHead = mHead->Left;
					pointer.reset();
					return true;
				}
				else
				{
					std::shared_ptr<TreeNode<T>> copy = pointer;
					copy = copy->Left;

					while (copy->Right != nullptr)
					{
						copy = copy->Right;
					}

					std::shared_ptr<TreeNode<T>> pre_copy = copy->Parent.lock();

					if (pre_copy == pointer)
					{
						copy->Right = pointer->Right;
						pointer->Right->Parent = copy;
						mHead = copy;
						copy->Parent.reset();
					}
					else if (copy->Left == nullptr)
					{
						pre_copy->Right = nullptr;
						copy->Left = pointer->Left;
						pointer->Left->Parent = copy;
						copy->Right = pointer->Right;
						pointer->Right->Parent = copy;
						mHead = copy;
						copy->Parent.reset();
					}
					else
					{
						pre_copy->Right = copy->Left;
						copy->Left->Parent = pre_copy;
						copy->Left = pointer->Left;
						pointer->Left->Parent = copy;
						copy->Right = pointer->Right;
						pointer->Right->Parent = copy;
						mHead = copy;
						copy->Parent.reset();
					}
					copy.reset();
					pre_copy.reset();
					pointer.reset();
					return true;
				}
			}


			while (*(pointer->Data) != data)
			{
				*(pointer->Data) < data ? pointer = pointer->Right : pointer = pointer->Left;
			}

			std::shared_ptr<TreeNode<T>> pre = pointer->Parent.lock();

			if (pointer->Right == nullptr && pointer->Left == nullptr)
			{
				if (*(pre->Right->Data) == data)
				{
					pre->Right.reset();
				}
				else
				{
					pre->Left.reset();
				}
			}
			else if (pointer->Left == nullptr)
			{
				if (*(pre->Right->Data) == data)
				{
					pointer->Right->Parent = pre;
					pre->Right = pointer->Right;
				}
				else
				{
					pointer->Right->Parent = pre;
					pre->Left = pointer->Right;
				}
			}
			else if (pointer->Right == nullptr)
			{
				if (*(pre->Right->Data) == data)
				{
					pointer->Left->Parent = pre;
					pre->Right = pointer->Left;
				}
				else
				{
					pointer->Left->Parent = pre;
					pre->Left = pointer->Left;
				}
			}
			else
			{
				std::shared_ptr<TreeNode<T>> copy = pointer;
				copy = copy->Left;

				while (copy->Right != nullptr)
				{
					copy = copy->Right;
				}

				std::shared_ptr<TreeNode<T>> pre_copy = copy->Parent.lock();

				if (pre_copy == pointer)
				{
					copy->Right = pointer->Right;
					pointer->Right->Parent = copy;
					*(pre->Data) < *(pointer->Data) ? pre->Right = copy : pre->Left = copy;
					copy->Parent = pre;
				}
				else if (copy->Left == nullptr)
				{
					pre_copy->Right = nullptr;
					copy->Left = pointer->Left;
					pointer->Left->Parent = copy;
					copy->Right = pointer->Right;
					pointer->Right->Parent = copy;
					*(pre->Data) < *(pointer->Data) ? pre->Right = copy : pre->Left = copy;
					copy->Parent = pre;
				}
				else
				{
					pre_copy->Right = copy->Left;
					copy->Left->Parent = pre_copy;
					copy->Left = pointer->Left;
					pointer->Left->Parent = copy;
					copy->Right = pointer->Right;
					pointer->Right->Parent = copy;
					*(pre->Data) < *(pointer->Data) ? pre->Right = copy : pre->Left = copy;
					copy->Parent = pre;
				}
				copy.reset();
				pre_copy.reset();
			}
			pre.reset();
			pointer.reset();
			return true;
		}
	}

	template<typename T>
	void BinarySearchTree<T>::InorderRecursive(const std::shared_ptr<TreeNode<T>> startNode, std::vector<T>& result)
	{
		if (startNode != nullptr)
		{
			InorderRecursive(startNode->Left, result);
			result.push_back(*(startNode->Data));
			InorderRecursive(startNode->Right, result);
		}
	}

	template<typename T>
	std::vector<T> BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> v;
		InorderRecursive(startNode, v);

		return v;
	}
}