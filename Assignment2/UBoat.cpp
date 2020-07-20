#include "UBoat.h"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::~UBoat()
	{
	}

	void UBoat::Travel()
	{
		IncreaseNumTravel();
		if (GetNumTravel() % 6 == 1 || GetNumTravel() % 6 == 2)
		{
			IncreaseNumTraveled();
		}
	}

	unsigned int UBoat::GetSailSpeed()
	{
		if (550 - static_cast<double>(GetTotalWeight()) / 10 <= 200)
		{
			return 200;
		}
		return (unsigned int) round(550 - static_cast<double>(GetTotalWeight()) / 10);
	}

	unsigned int UBoat::GetDiveSpeed()
	{
		//500 * log((x + 150)/150) + 30
		return (unsigned int) round(500 * log(static_cast<double>(GetTotalWeight() + 150) / 150) + 30);
	}

	unsigned int UBoat::GetMaxSpeed()
	{
		if (GetSailSpeed() <= GetDiveSpeed())
		{
			return GetDiveSpeed();
		}
		return GetSailSpeed();
	}
}