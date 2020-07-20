#pragma once

#include "eGrassType.h"
#include <cmath>

namespace lab5
{
	class Lawn
	{
	public:
		Lawn();
		virtual ~Lawn();

		virtual unsigned int GetArea() const = 0;
		virtual unsigned int GetPerimeter() const = 0;

		unsigned int GetGrassPrice(eGrassType grassType) const;
		unsigned int GetMinimumSodRollsCount() const;
	};
}