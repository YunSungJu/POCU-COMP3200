#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(Boatplane* boatplane)
		: Vehicle(boatplane)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	void Boatplane::Travel()
	{
		IncreaseNumTravel();
		if (GetNumTravel() % 4 == 1)
		{
			IncreaseNumTraveled();
		}
	}

	unsigned int Boatplane::GetFlySpeed()
	{
		return (unsigned int)round(150 * pow(std::exp(1.0), (-1 * static_cast<double>(GetTotalWeight()) + 500) / 300));
	}

	unsigned int Boatplane::GetSailSpeed()
	{
		if (800 - 1.7 * static_cast<double>(GetTotalWeight()) <= 20)
		{
			return 20;
		}
		return (unsigned int)round(800 - 1.7 * static_cast<double>(GetTotalWeight()));
	}

	unsigned int Boatplane::GetMaxSpeed()
	{
		if (GetFlySpeed() <= GetSailSpeed())
		{
			return GetSailSpeed();
		}
		return GetFlySpeed();
	}
}