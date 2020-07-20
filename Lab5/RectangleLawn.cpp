#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width), mHeight(height)
	{
	}

	RectangleLawn::~RectangleLawn()
	{
	}

	unsigned int RectangleLawn::GetArea() const
	{
		return mWidth * mHeight;
	}

	unsigned int RectangleLawn::GetPerimeter() const
	{
		return mWidth + mWidth + mHeight + mHeight;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
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

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		return (unsigned int)ceil(GetPerimeter() * 4);
	}
}