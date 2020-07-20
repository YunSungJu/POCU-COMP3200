#include "Sedan.h"

namespace assignment2
{
	Sedan::Sedan()
		: Vehicle(4)
	{
		bIsTrailer = false;
		MTrailer = nullptr;
	}

	Sedan::~Sedan()
	{
		if (bIsTrailer == true)
		{
			delete MTrailer;
			MTrailer = nullptr;
			bIsTrailer = false;
		}
	}

	bool Sedan::AddTrailer(const Trailer* trailer)
	{
		if (trailer == nullptr)
		{
			return false;
		}

		if (bIsTrailer == false)
		{
			bIsTrailer = true;

			MTrailer = trailer;
			return true;
		}
		return false;
	}

	bool Sedan::RemoveTrailer()
	{
		if (bIsTrailer == true)
		{
			bIsTrailer = false;

			delete MTrailer;
			MTrailer = nullptr;
			return true;
		}
		return false;
	}

	void Sedan::Travel()
	{
		IncreaseNumTravel();
		if (bIsTrailer == true)
		{
			if (GetNumTravel() % 7 != 0 && GetNumTravel() % 7 != 6)
			{
				IncreaseNumTraveled();
			}
		}
		else
		{
			if (GetNumTravel() % 6 != 0)
			{
				IncreaseNumTraveled();
			}
		}
	}

	unsigned int Sedan::GetDriveSpeed()
	{
		if (bIsTrailer == true)
		{
			unsigned int total = GetTotalWeight() + MTrailer->GetWeight();
			if (total <= 80)
			{
				return 480;
			}
			else if (total <= 160)
			{
				return 458;
			}
			else if (total <= 260)
			{
				return 400;
			}
			else if (total <= 350)
			{
				return 380;
			}
			else
			{
				return 300;
			}

		}
		else
		{
			unsigned int total = GetTotalWeight();
			if (total <= 80)
			{
				return 480;
			}
			else if (total <= 160)
			{
				return 458;
			}
			else if (total <= 260)
			{
				return 400;
			}
			else if (total <= 350)
			{
				return 380;
			}
			else
			{
				return 300;
			}
		}
	}

	unsigned int Sedan::GetMaxSpeed()
	{
		return GetDriveSpeed();
	}
}