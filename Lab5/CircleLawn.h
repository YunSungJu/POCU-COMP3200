#pragma once

#include "Lawn.h"

namespace lab5
{
	class CircleLawn : public Lawn
	{
	public:
		CircleLawn(unsigned int radius);
		virtual ~CircleLawn();
		unsigned int GetArea() const;
		unsigned int GetPerimeter() const;

	private:
		unsigned int mRadius;
	};
}

