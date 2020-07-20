//#include <cassert>
//
//#include "Storage.h"
//
//using namespace lab11;
//
//int main()
//{
//	const unsigned int SIZE = 10000;
//
//	Storage<int> storage1(SIZE);
//	const std::unique_ptr<int[]>& data1 = storage1.GetData();
//
//	for (int i = 0; i < SIZE; ++i)
//	{
//		assert(data1[i] == 0);
//	}
//
//
//	Storage<int> storage2(SIZE, 100);
//	const std::unique_ptr<int[]>& data2 = storage2.GetData();
//
//	for (int i = 0; i < SIZE; ++i)
//	{
//		assert(data2[i] == 100);
//	}
//
//	// using move constructor
//	Storage<int> storage3(SIZE, 50);
//	const std::unique_ptr<int[]>& data3 = storage3.GetData();
//
//	assert(storage3.GetSize() == SIZE);
//
//	for (int i = 0; i < SIZE; ++i)
//	{
//		assert(data3[i] == 50);
//	}
//
//	Storage<int> storage3Copy(std::move(storage3));
//	const std::unique_ptr<int[]>& data3Copy = storage3Copy.GetData();
//
//	assert(storage3Copy.GetSize() == SIZE);
//	for (int i = 0; i < SIZE; ++i)
//	{
//		assert(data3Copy[i] == 50);
//	}
//
//	assert(storage3.GetData() == nullptr);
//	assert(storage3.GetSize() == 0);
//
//	Storage<char> storage4(SIZE, 'f');
//	const std::unique_ptr<char[]>& data4 = storage4.GetData();
//
//	assert(storage4.GetSize() == SIZE);
//
//	for (int i = 0; i < SIZE; ++i)
//	{
//		assert(data4[i] == 'f');
//	}
//
//	Storage<char> storage4Copy = std::move(storage4);
//	const std::unique_ptr<char[]>& data4Copy = storage4Copy.GetData();
//
//	assert(storage4Copy.GetSize() == SIZE);
//
//	for (int i = 0; i < SIZE; ++i)
//	{
//		assert(data4Copy[i] == 'f');
//	}
//
//	assert(storage4.GetData() == nullptr);
//	assert(storage4.GetSize() == 0);
//
//	const unsigned int SIZE2 = 5000;
//
//	Storage<int> storage5(SIZE2);
//	const std::unique_ptr<int[]>& data5 = storage5.GetData();
//
//	for (int i = 0; i < SIZE2; ++i)
//	{
//		storage5.Update(i, SIZE2 - i - 1);
//		assert(data5[i] == SIZE2 - i - 1);
//	}
//
//	return 0;
//}

#include <cassert>

#include "Storage.h"

using namespace lab11;

const unsigned int SIZE = 10000;

void testConstructor();
void testUpdateMethod();
void testEqualityOperator();
void testMoveConstructor();
void testMoveEqualityOperator();

int main()
{
	testConstructor();
	testEqualityOperator();
	testMoveConstructor();
	testMoveEqualityOperator();

	testUpdateMethod();

	return 0;
}

void testUpdateMethod()
{
	const unsigned int SIZE2 = 5000;

	Storage<int> storage5(SIZE2);
	const std::unique_ptr<int[]>& data5 = storage5.GetData();

	for (int i = 0; i < SIZE2; ++i)
	{
		storage5.Update(i, SIZE2 - i - 1);
		assert(data5[i] == SIZE2 - i - 1);
	}
}

void testConstructor()
{
	Storage<int> storage1(SIZE);
	const std::unique_ptr<int[]>& data1 = storage1.GetData();
	for (int i = 0; i < SIZE; ++i)
	{
		assert(data1[i] == 0);
	}

	Storage<int> storage2(SIZE, 100);
	const std::unique_ptr<int[]>& data2 = storage2.GetData();

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data2[i] == 100);
	}

	// using move constructor
	Storage<int> storage3(SIZE, 50);
	const std::unique_ptr<int[]>& data3 = storage3.GetData();
	assert(storage3.GetSize() == SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		assert(data3[i] == 50);
	}

	Storage<int> storage4(storage3);
	const std::unique_ptr<int[]>& data4 = storage4.GetData();
	assert(storage4.GetSize() == storage3.GetSize());
	for (int i = 0; i < SIZE; ++i)
	{
		assert(data4[i] == data3[i]);
	}
}

void testEqualityOperator()
{
	Storage<int> storage1(SIZE, 100);
	Storage<int> storage2(SIZE, 50);

	storage2 = storage1;

	const std::unique_ptr<int[]>& data1 = storage1.GetData();
	const std::unique_ptr<int[]>& data2 = storage2.GetData();

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data1[i] == data2[i]);
	}

	storage2 = storage2;
}

void testMoveConstructor()
{
	Storage<int> storage3(SIZE, 50);
	const std::unique_ptr<int[]>& data3 = storage3.GetData();

	assert(storage3.GetSize() == SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data3[i] == 50);
	}

	Storage<int> storage3Copy(std::move(storage3));
	const std::unique_ptr<int[]>& data3Copy = storage3Copy.GetData();

	assert(storage3Copy.GetSize() == SIZE);
	for (int i = 0; i < SIZE; ++i)
	{
		assert(data3Copy[i] == 50);
	}

	assert(storage3.GetData() == nullptr);
	assert(storage3.GetSize() == 0);

	Storage<char> storage4(SIZE, 'f');
	const std::unique_ptr<char[]>& data4 = storage4.GetData();

	assert(storage4.GetSize() == SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data4[i] == 'f');
	}

	Storage<char> storage4Copy = std::move(storage4);
	const std::unique_ptr<char[]>& data4Copy = storage4Copy.GetData();

	assert(storage4Copy.GetSize() == SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		assert(data4Copy[i] == 'f');
	}

	assert(storage4.GetData() == nullptr);
	assert(storage4.GetSize() == 0);
}

void testMoveEqualityOperator()
{
	Storage<int> storage1(SIZE, 100);
	Storage<int> storage2(SIZE);

	storage2 = std::move(storage1);

	const std::unique_ptr<int[]>& data1 = storage1.GetData();
	const std::unique_ptr<int[]>& data2 = storage2.GetData();

	assert(data1 == nullptr);
	assert(storage1.GetSize() == 0);
	for (int i = 0; i < SIZE; ++i)
	{
		assert(data2[i] == 100);
	}

	storage2 = std::move(storage2);
	assert(data2 != nullptr);
}