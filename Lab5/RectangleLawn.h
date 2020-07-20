#pragma once

#include "Lawn.h"
#include "eFenceType.h"
#include "IFenceable.h"

namespace lab5
{
	class RectangleLawn : public Lawn, public IFenceable
	{
	public:
		RectangleLawn(unsigned int width, unsigned int height);
		virtual ~RectangleLawn();
		unsigned int GetArea() const;
		unsigned int GetPerimeter() const;
		unsigned int GetFencePrice(eFenceType fenceType) const;
		unsigned int GetMinimumFencesCount() const;

	protected:
		unsigned int mWidth;
		unsigned int mHeight;
	};

}