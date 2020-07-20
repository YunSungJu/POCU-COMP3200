#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int width)
		: mWidth(width)
	{
	}

	EquilateralTriangleLawn::~EquilateralTriangleLawn()
	{
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		double result = mWidth * mWidth * sqrt(3) * 0.25 + 0.5;

		return (unsigned int)floor(result);
	}

	unsigned int EquilateralTriangleLawn::GetPerimeter() const
	{
		return 3 * mWidth;
	}


	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		switch (fenceType)
		{
		case lab5::RED_CEDAR:
			return (unsigned int)ceil(GetPerimeter() * 6);
			break;
		case lab5::SPRUCE:
			return (unsigned int)ceil(GetPerimeter() * 7);
			break;
		default:
			return 0;
			break;
		}
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		return (unsigned int)ceil(GetPerimeter() * 4);
	}
}