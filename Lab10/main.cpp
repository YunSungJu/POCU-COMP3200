#include <cassert>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace lab10;

void DoublyLinkedListTest()
{
	DoublyLinkedList<int> list;

	//빈 리스트에 대한 테스트
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

	//중간위치의 노드에 대한 삭제 테스트
	assert(list.Delete(6) == true);
	assert(list.Search(6) == false);

	//첫 노드에 대한 삭제 테스트
	assert(list.Delete(1) == true);
	assert(list.Search(1) == false);

	//마지막 노드에 대한 삭제 테스트
	assert(list.Delete(7) == true);
	assert(list.Search(7) == false);

	//노드 삭제 후 노드들이 제대로 위치해 있는지에 대한 테스트
	assert(list.GetLength() == 4);
	assert(*list[0]->Data == 2);
	assert(*list[1]->Data == 3);
	assert(*list[2]->Data == 4);
	assert(*list[3]->Data == 5);
	assert(list[4] == nullptr);

	//insert(data,index)의 index값이 범위를 벗어 났을 때 올바른 위치에 삽입이 되는지 에 대한 테스트
	list.Insert(std::make_unique<int>(7), 10);
	assert(*list[4]->Data == 7);

	//insert(data,index == 0)일 때 첫 노드가 제대로 설정 되는지에 대한 테스트
	list.Insert(std::make_unique<int>(1), 0);
	assert(*list[0]->Data == 1);

	//insert(data,index) 가 중간에 삽입 하려고 할 때 제대로 삽입이 되는지에 대한 테스트
	list.Insert(std::make_unique<int>(6), 5);
	assert(*list[5]->Data == 6);


	//insert(data,index)메소드 실행 이 후 노드들이 올바른 위치에 있는지에 대한 테스트
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

