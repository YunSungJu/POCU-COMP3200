#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int radius)
		: mRadius(radius)
	{
	}

	CircleLawn::~CircleLawn()
	{
	}

	unsigned int CircleLawn::GetArea() const
	{
		return (unsigned int)floor(mRadius * mRadius * 3.14 + 0.5);
	}

	unsigned int CircleLawn::GetPerimeter() const
	{
		return 0;
	}

}