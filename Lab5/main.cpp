#include <cassert>
#include <iostream>
#include "Lawn.h"
#include "IFenceable.h"
#include "RectangleLawn.h"
#include "CircleLawn.h"
#include "SquareLawn.h"
#include "EquilateralTriangleLawn.h"

using namespace lab5;

int main()
{
	Lawn* lawn = new RectangleLawn(20, 20);
	unsigned int area = lawn->GetArea();
	unsigned int grassPrice = lawn->GetGrassPrice(BERMUDA);
	unsigned int sodRollsCount = lawn->GetMinimumSodRollsCount();

	std::cout << area << " " << grassPrice << " " << sodRollsCount << std::endl;

	RectangleLawn* rectangleLawn = (RectangleLawn*)lawn;
	unsigned int fencePrice = rectangleLawn->GetFencePrice(RED_CEDAR);
	unsigned int fencesCount = rectangleLawn->GetMinimumFencesCount();

	std::cout << fencePrice << " " << fencesCount << std::endl;

	Lawn* lawn1 = new SquareLawn(20);
	unsigned int area1 = lawn1->GetArea();
	unsigned int grassPrice1 = lawn1->GetGrassPrice(BERMUDA);
	unsigned int sodRollsCount1 = lawn1->GetMinimumSodRollsCount();

	std::cout << area1 << " " << grassPrice1 << " " << sodRollsCount1 << std::endl;

	SquareLawn* squareLawn = (SquareLawn*)lawn1;
	unsigned int fencePrice1 = squareLawn->GetFencePrice(RED_CEDAR);
	unsigned int fencesCount1 = squareLawn->GetMinimumFencesCount();

	std::cout << fencePrice1 << " " << fencesCount1 << std::endl;

	// 위와 같은 방식으로 다른 구체 클래스들도 테스트할 수 있음
	return 0;
}