#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace lab10;

void DoublyLinkedListTest()
{
	DoublyLinkedList<int> list;

	//�� ����Ʈ�� ���� �׽�Ʈ
	assert(list.GetLength() == 0);
	assert(list.Delete(1) == false);
	assert(list.Search(1) == false);
	assert(list[0] == nullptr);

	////////////////////////////////////
	list.Insert(std::make_unique<int>(1));
	list.Insert(std::make_unique<int>(2));
	list.Insert(std::make_unique<int>(3));
	list.Insert(std::make_unique<int>(4));
	list.Insert(std::make_unique<int>(5));
	list.Insert(std::make_unique<int>(6));
	list.Insert(std::make_unique<int>(7));

	assert(list.GetLength() == 7);
	assert(list.Delete(8) == false);
	assert(list.Search(9) == false);
	assert(list.Search(4) == true);

	//�߰���ġ�� ��忡 ���� ���� �׽�Ʈ
	assert(list.Delete(6) == true);
	assert(list.Search(6) == false);

	//ù ��忡 ���� ���� �׽�Ʈ
	assert(list.Delete(1) == true);
	assert(list.Search(1) == false);

	//������ ��忡 ���� ���� �׽�Ʈ
	assert(list.Delete(7) == true);
	assert(list.Search(7) == false);

	//��� ���� �� ������ ����� ��ġ�� �ִ����� ���� �׽�Ʈ
	assert(list.GetLength() == 4);
	assert(*list[0]->Data == 2);
	assert(*list[1]->Data == 3);
	assert(*list[2]->Data == 4);
	assert(*list[3]->Data == 5);
	assert(list[4] == nullptr);

	//insert(data,index)�� index���� ������ ���� ���� �� �ùٸ� ��ġ�� ������ �Ǵ��� �� ���� �׽�Ʈ
	list.Insert(std::make_unique<int>(7), 10);
	assert(*list[4]->Data == 7);

	//insert(data,index == 0)�� �� ù ��尡 ����� ���� �Ǵ����� ���� �׽�Ʈ
	list.Insert(std::make_unique<int>(1), 0);
	assert(*list[0]->Data == 1);

	//insert(data,index) �� �߰��� ���� �Ϸ��� �� �� ����� ������ �Ǵ����� ���� �׽�Ʈ
	list.Insert(std::make_unique<int>(6), 5);
	assert(*list[5]->Data == 6);


	//insert(data,index)�޼ҵ� ���� �� �� ������ �ùٸ� ��ġ�� �ִ����� ���� �׽�Ʈ
	assert(list.GetLength() == 7);
	assert(*list[0]->Data == 1);
	assert(*list[1]->Data == 2);
	assert(*list[2]->Data == 3);
	assert(*list[3]->Data == 4);
	assert(*list[4]->Data == 5);
	assert(*list[5]->Data == 6);
	assert(*list[6]->Data == 7);
	assert(list[7] == nullptr);
}

int main()
{
	DoublyLinkedListTest();

	return 0;
}

