#include "Vehicle.h"
#include <cstring>

namespace assignment2
{
	Vehicle::Vehicle()
	{

	}

	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mMaxCount(maxPassengersCount), mLength(0), mNumTravel(0), mNumTraveled(0)
	{
		for (unsigned int i = 0; i < 100; i++)
		{
			mPeople[i] = nullptr;
		}
	}

	Vehicle::Vehicle(Vehicle* vehicle)
		: mMaxCount(vehicle->GetMaxPassengersCount()), mLength(vehicle->GetPassengersCount()), mNumTravel(vehicle->GetNumTravel()), mNumTraveled(vehicle->GetNumTraveled())
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			mPeople[i] = new Person(vehicle->GetPassenger(i));
		}
		for (unsigned int i = mLength; i < mMaxCount; i++)
		{
			mPeople[i] = nullptr;
		}
	}

	Vehicle::~Vehicle()
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			delete mPeople[i];
			mPeople[i] = nullptr;
		}
	}

	void Vehicle::ResetPassenger()
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			mPeople[i] = nullptr;
		}
		mLength = 0;
	}

	void Vehicle::IncreaseNumTraveled()
	{
		mNumTraveled++;
	}

	void Vehicle::IncreaseNumTravel()
	{
		mNumTravel++;
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person == NULL)
		{
			return false;
		}

		if (mLength < mMaxCount)
		{
			mPeople[mLength] = person;
			mLength++;
			return true;
		}
		return false;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (mLength == 0)
		{
			return false;
		}

		if (i < mLength - 1)
		{
			delete mPeople[i];

			for (; i < mLength - 1; i++)
			{
				mPeople[i] = mPeople[i + 1];
			}
			mPeople[i] = nullptr;

			mLength--;

			return true;
		}
		else if (i == mLength - 1)
		{
			delete mPeople[i];

			mPeople[i] = nullptr;
			mLength--;

			return true;
		}
		return false;
	}

	unsigned int Vehicle::GetTotalWeight() const
	{
		unsigned int total = 0;

		for (unsigned int i = 0; i < mLength; i++)
		{
			total += mPeople[i]->GetWeight();
		}

		return total;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mLength;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mMaxCount;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		if (i < mLength)
		{
			return mPeople[i];
		}
		return NULL;
	}

	unsigned int Vehicle::GetNumTravel() const
	{
		return mNumTravel;
	}

	unsigned int Vehicle::GetNumTraveled() const
	{
		return mNumTraveled;
	}
}