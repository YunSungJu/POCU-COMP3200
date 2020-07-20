#include "Boat.h"
#include "Airplane.h"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	void Boat::Travel()
	{
		IncreaseNumTravel();
		if (GetNumTravel() % 3 == 1 || GetNumTravel() % 3 == 2)
		{
			IncreaseNumTraveled();
		}
	}

	unsigned int Boat::GetSailSpeed()
	{
		if (GetTotalWeight() < 80)
		{
			if (800 - 10 * GetTotalWeight() <= 20)
			{
				return 20;
			}
			return 800 - 10 * GetTotalWeight();
		}
		return 20;
	}

	unsigned int Boat::GetMaxSpeed()
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		Boatplane* bp = new Boatplane(GetMaxPassengersCount() + plane.GetMaxPassengersCount());

		unsigned int pLength = plane.GetPassengersCount();
		unsigned int bLength = GetPassengersCount();

		for (unsigned int i = 0; i < pLength; i++)
		{
			bp->AddPassenger(plane.GetPassenger(i));
		}
		for (unsigned int i = 0; i < bLength; i++)
		{
			bp->AddPassenger(GetPassenger(i));
		}

		ResetPassenger();
		plane.ResetPassenger();

		Boatplane result(bp);

		delete bp;

		return Boatplane(&result);
	}
}