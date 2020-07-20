#include "Airplane.h"
#include "Boat.h"

#include <cmath>

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	void Airplane::Travel()
	{
		IncreaseNumTravel();
		if (GetNumTravel() % 4 == 1)
		{
			IncreaseNumTraveled();
		}
	}

	unsigned int Airplane::GetFlySpeed()
	{
		return (unsigned int)round(200 * pow(std::exp(1.0), static_cast<double>(-1 * GetTotalWeight() + 800) / 500));
	}

	unsigned int Airplane::GetDriveSpeed()
	{
		return (unsigned int)round(4 * pow(std::exp(1.0), static_cast<double>(-1 * GetTotalWeight() + 400) / 70));
	}

	unsigned int Airplane::GetMaxSpeed()
	{
		if (GetDriveSpeed() <= GetFlySpeed())
		{
			return GetFlySpeed();
		}
		return GetDriveSpeed();
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		Boatplane* bp = new Boatplane(GetMaxPassengersCount() + boat.GetMaxPassengersCount());

		unsigned int pLength = GetPassengersCount();
		unsigned int bLength = boat.GetPassengersCount();

		for (unsigned int i = 0; i < pLength; i++)
		{
			bp->AddPassenger(GetPassenger(i));
		}
		for (unsigned int i = 0; i < bLength; i++)
		{
			bp->AddPassenger(boat.GetPassenger(i));
		}

		ResetPassenger();
		boat.ResetPassenger();

		Boatplane result(bp);

		delete bp;

		return Boatplane(&result);
	}
}