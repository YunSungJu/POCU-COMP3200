#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		switch (grassType)
		{
		case lab5::BERMUDA:
			return (unsigned int)ceil(this->GetArea() * 8);
			break;
		case lab5::BAHIA:
			return (unsigned int)ceil(this->GetArea() * 5);
			break;
		case lab5::BENTGRASS:
			return (unsigned int)ceil(this->GetArea() * 3);
			break;
		case lab5::PERENNIAL_RYEGRASS:
			return (unsigned int)ceil(this->GetArea() * 2.5);
			break;
		case lab5::ST_AUGUSTINE:
			return (unsigned int)ceil(this->GetArea() * 4.5);
			break;
		default:
			return 0;
			break;
		}
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		return (unsigned int)ceil(this->GetArea() * 3.333333333333333);
	}
}