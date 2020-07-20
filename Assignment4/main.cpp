#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"

using namespace assignment4;
void Test_Insert_GetRoot();
void Test_Search();
void Test_Delete();
void Test_Traverse();
void BinarySearchTreeTest();

int main()
{
	Test_Insert_GetRoot();
	Test_Search();
	Test_Delete();
	Test_Traverse();
	BinarySearchTreeTest();

	return 0;
}

void Test_Insert_GetRoot()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	tree.Insert(std::make_unique<int>(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));

	std::shared_ptr<TreeNode<int>> test0 = tree.GetRootNode().lock();
	assert(*test0->Data.get() == 10);
	assert(test0->Parent.lock().get() == nullptr);
	std::shared_ptr<TreeNode<int>> test1 = test0->Left;
	assert(*test1->Data.get() == 5);
	assert(*test1->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test2 = test1->Left;
	assert(*test2->Data.get() == 4);
	assert(*test2->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test3 = test1->Right;
	assert(*test3->Data.get() == 7);
	assert(*test3->Parent.lock()->Data.get() == 5);
	std::shared_ptr<TreeNode<int>> test4 = test0->Right;
	assert(*test4->Data.get() == 15);
	assert(*test4->Parent.lock()->Data.get() == 10);
	std::shared_ptr<TreeNode<int>> test5 = test4->Left;
	assert(*test5->Data.get() == 12);
	assert(*test5->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test6 = test4->Right;
	assert(*test6->Data.get() == 19);
	assert(*test6->Parent.lock()->Data.get() == 15);
	std::shared_ptr<TreeNode<int>> test7 = test6->Left;
	assert(*test7->Data.get() == 17);
	assert(*test7->Parent.lock()->Data.get() == 19);
	std::shared_ptr<TreeNode<int>> test8 = test6->Right;
	assert(*test8->Data.get() == 20);
	assert(*test8->Parent.lock()->Data.get() == 19);

	return;
}

void Test_Search()
{
	BinarySearchTree<int> tree;

	int arr[10] = { 10, 15, 5, 4, 19, 20, 17, 12, 7, 0 };

	assert(!tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[0]));
	assert(tree.Search(arr[0]));
	tree.Insert(std::make_unique<int>(arr[1]));
	assert(tree.Search(arr[1]));
	tree.Insert(std::make_unique<int>(arr[2]));
	assert(tree.Search(arr[2]));
	tree.Insert(std::make_unique<int>(arr[3]));
	assert(tree.Search(arr[3]));
	tree.Insert(std::make_unique<int>(arr[4]));
	assert(tree.Search(arr[4]));
	tree.Insert(std::make_unique<int>(arr[5]));
	assert(tree.Search(arr[5]));
	tree.Insert(std::make_unique<int>(arr[6]));
	assert(tree.Search(arr[6]));
	tree.Insert(std::make_unique<int>(arr[7]));
	assert(tree.Search(arr[7]));
	tree.Insert(std::make_unique<int>(arr[8]));
	assert(tree.Search(arr[8]));
	assert(!tree.Search(arr[9]));

	return;
}

void Test_Delete()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };

	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	//	End
	assert(!tree.Delete(9)); 	// �������� �ʴ� ��� ����
	assert(tree.Delete(20));	// Right ��� ����
	assert(!tree.Search(20));	// ���� Ȯ��
	assert(tree.Delete(12));	// Left ��� ����
	assert(!tree.Search(12));	// ���� Ȯ��
	assert(!tree.Delete(11));	// �������� �ʴ� ��� ����

	//	Middle
	assert(tree.Delete(19));	// Left�� �ִ� ��� ����
	assert(!tree.Search(19));	// ���� Ȯ��
	assert(tree.Search(17));
	assert(tree.Delete(15));	// Right�� �ִ� ��� ����
	assert(!tree.Search(15));	// ���� Ȯ��
	assert(tree.Delete(5)); 	// Left, Right ��� �ִ� ��� ����
	assert(!tree.Search(5));
	assert(!tree.Delete(5));	// �������� �ʴ� ��� ����

	//	Head
	assert(tree.Delete(10)); 	// Left, Right ��� �ִ� ��� ����
	assert(!tree.Search(10));	// ���� Ȯ��
	assert(tree.Delete(4));
	assert(tree.Delete(7));
	assert(tree.Delete(17));	// Left, Right ��� ���� ��� ����
	assert(!tree.Search(17));	// ���� Ȯ��
	assert(!tree.Delete(17));	// ����ִ� ���¿��� ����


	for (size_t i = 0; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	tree.Delete(arr[0]);
	tree.Delete(arr[1]);
	tree.Delete(arr[2]);
	tree.Delete(arr[3]);
	tree.Delete(arr[4]);
	tree.Delete(arr[5]);
	tree.Delete(arr[6]);
	tree.Delete(arr[7]);
	tree.Delete(arr[8]);

	return;
}

void Test_Traverse()
{
	BinarySearchTree<int> tree;

	int arr[9] = { 10, 15, 5, 4, 19, 20, 17, 12, 7 };
	int arr_chk[9] = { 4, 5, 7, 10, 12, 15, 17, 19, 20 };

	// �� Ʈ��
	std::vector<int> v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 0);
	assert(v1.empty());

	tree.Insert(std::make_unique<int>(arr[0]));
	// ��常 �ִ� Ʈ��
	std::vector<int> v2 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v2.size() == 1);
	assert(v2[0] == arr[0]);

	// empty ������
	std::vector<int> v3 = tree.TraverseInOrder(tree.GetRootNode().lock()->Left);
	assert(v3.size() == 0);
	assert(v3.empty());

	// Ʈ�� �Է�
	for (size_t i = 1; i < 9; i++)
	{
		tree.Insert(std::make_unique<int>(arr[i]));
	}

	// ��� ��� �Է�
	std::vector<int> v4 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v4.size() == 9);
	assert(v4[0] == arr_chk[0]);
	assert(v4[1] == arr_chk[1]);
	assert(v4[2] == arr_chk[2]);
	assert(v4[3] == arr_chk[3]);
	assert(v4[4] == arr_chk[4]);
	assert(v4[5] == arr_chk[5]);
	assert(v4[6] == arr_chk[6]);
	assert(v4[7] == arr_chk[7]);
	assert(v4[8] == arr_chk[8]);

	// �߰� ��� �Է�
	std::vector<int> v5 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Right);
	assert(v5.size() == 3);
	assert(v5[0] == arr_chk[6]);
	assert(v5[1] == arr_chk[7]);
	assert(v5[2] == arr_chk[8]);

	// ���� ��� �Է�
	std::vector<int> v6 = tree.TraverseInOrder(tree.GetRootNode().lock()->Right->Left);
	assert(v6.size() == 1);
	assert(v6[0] == arr_chk[4]);

	// ��� ����
	for (size_t i = 0; i < 8; i++)
	{
		tree.Delete(arr[i]);
	}

	// 7�� ����� ��� ������ Ʈ��
	std::vector<int> v7 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v7.size() == 1);
	assert(v7[0] == arr[8]);

	// ��尡 ��� ������ Ʈ��
	tree.Delete(arr[8]);
	std::vector<int> v8 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v8.size() == 0);
	assert(v8.empty());

	return;
}

void BinarySearchTreeTest()
{
	assignment4::BinarySearchTree<float> tree;
	std::vector<float> v1;
	//��Ʈ���� ���� �׽�Ʈ
	assert(tree.GetRootNode().lock() == nullptr);
	assert(tree.Delete(1.f) == false);
	assert(tree.Search(1.f) == false);

	//��Ʈ ��� �ϳ��� ���� �� �׽�Ʈ
	tree.Insert(std::make_unique<float>(1.2f));
	assert(*tree.GetRootNode().lock()->Data == 1.2f);
	assert(tree.Search(1.2f) == true);

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 1);
	assert(v1[0] = 1.2f);
	assert(tree.Delete(1.3f) == false);
	assert(tree.Delete(1.2f) == true);
	assert(tree.GetRootNode().lock() == nullptr);

	//�׳� ���� �׽�Ʈ...
	tree.Insert(std::make_unique<float>(50.f));
	tree.Insert(std::make_unique<float>(25.f));
	tree.Insert(std::make_unique<float>(75.f));
	tree.Insert(std::make_unique<float>(12.5f));
	tree.Insert(std::make_unique<float>(37.5f));
	tree.Insert(std::make_unique<float>(38.f));
	tree.Insert(std::make_unique<float>(62.5f));
	tree.Insert(std::make_unique<float>(87.5f));
	tree.Insert(std::make_unique<float>(6.f));
	tree.Insert(std::make_unique<float>(3.f));
	tree.Insert(std::make_unique<float>(30.f));
	tree.Insert(std::make_unique<float>(31.f));
	tree.Insert(std::make_unique<float>(32.f));
	tree.Insert(std::make_unique<float>(88.f));
	tree.Insert(std::make_unique<float>(89.f));

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 15);
	assert(v1[0] == 3.f);
	assert(v1[1] == 6.f);
	assert(v1[2] == 12.5f);
	assert(v1[3] == 25.f);
	assert(v1[4] == 30.f);
	assert(v1[5] == 31.f);
	assert(v1[6] == 32.f);
	assert(v1[7] == 37.5f);
	assert(v1[8] == 38.f);
	assert(v1[9] == 50.f);
	assert(v1[10] == 62.5f);
	assert(v1[11] == 75.f);
	assert(v1[12] == 87.5f);
	assert(v1[13] == 88.f);
	assert(v1[14] == 89.f);

	assert(tree.Search(34.f) == false);
	assert(tree.Search(62.5f) == true);

	assert(tree.Delete(34.f) == false);
	assert(tree.Delete(12.5f) == true);
	assert(tree.Delete(37.5f) == true);
	assert(tree.Delete(25.f) == true);
	assert(tree.Delete(25.f) == false);
	assert(tree.Delete(87.5f) == true);

	assert(tree.Delete(50.f) == true); //��Ʈ��� ���� �׽�Ʈ
	assert(tree.GetRootNode().lock() != nullptr);
	assert(*tree.GetRootNode().lock()->Data == 38.0f);

	assert(tree.Search(37.5f) == false);

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 10);
	assert(v1[0] == 3.f);
	assert(v1[1] == 6.f);
	assert(v1[2] == 30.f);
	assert(v1[3] == 31.f);
	assert(v1[4] == 32.f);
	assert(v1[5] == 38.f);
	assert(v1[6] == 62.5f);
	assert(v1[7] == 75.f);
	assert(v1[8] == 88.f);
	assert(v1[9] == 89.f);

	//���ġ�� ��� ���� �׽�Ʈ
	assert(tree.Delete(32.f) == true);
	assert(tree.Delete(6.f) == true);
	assert(tree.Delete(88.f) == true);

	v1 = tree.TraverseInOrder(tree.GetRootNode().lock());
	assert(v1.size() == 7);
	assert(v1[0] == 3.f);
	assert(v1[1] == 30.f);
	assert(v1[2] == 31.f);
	assert(v1[3] == 38.f);
	assert(v1[4] == 62.5f);
	assert(v1[5] == 75.f);
	assert(v1[6] == 89.f);
}