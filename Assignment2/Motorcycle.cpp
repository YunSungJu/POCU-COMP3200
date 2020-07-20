#include "Motorcycle.h"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::~Motorcycle()
	{
	}

	void Motorcycle::Travel()
	{
		IncreaseNumTravel();
		if (GetNumTravel() % 6 != 0)
		{
			IncreaseNumTraveled();
		}
	}

	unsigned int Motorcycle::GetDriveSpeed()
	{
		if (- 1 * pow(static_cast<double>(GetTotalWeight()) / 15, 3) + 2 * GetTotalWeight() + 400 <= 0)
		{
			return 0;
		}
		return (unsigned int) round(- 1 * pow(static_cast<double>(GetTotalWeight()) / 15, 3) + 2 * GetTotalWeight() + 400);
	}

	unsigned int Motorcycle::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}
}