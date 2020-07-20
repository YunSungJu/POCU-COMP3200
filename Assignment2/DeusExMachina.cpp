#include "DeusExMachina.h"

namespace assignment2
{
	bool DeusExMachina::mbIsDEM = false;
	DeusExMachina* DeusExMachina::mDEM = nullptr;

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mbIsDEM == false)
		{
			mDEM = new DeusExMachina();
			mbIsDEM = true;
			return mDEM;
		}
		return mDEM;
	}

	void DeusExMachina::Travel() const
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			mVehicles[i]->Travel();
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (vehicle == nullptr)
		{
			return false;
		}

		if (mLength < 10)
		{
			mVehicles[mLength] = vehicle;
			mLength++;
			return true;
		}

		return false;
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (mLength == 0)
		{
			return false;
		}

		if (i < mLength - 1)
		{
			delete mVehicles[i];

			for (; i < mLength; i++)
			{
				mVehicles[i] = mVehicles[i + 1];
			}
			mVehicles[i] = nullptr;

			mLength--;

			return true;
		}
		else if (i == mLength - 1)
		{
			delete mVehicles[i];

			mVehicles[i] = nullptr;
			mLength--;

			return true;
		}
		return false;
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		if (mLength == 0)
		{
			return NULL;
		}
		
		if (mVehicles[0]->GetNumTravel() == 0)
		{
			return mVehicles[0];
		}
		
		unsigned int max = 0;
		Vehicle* result = nullptr;

		for (unsigned int i = 0; i < mLength; i++)
		{
			if (max < mVehicles[i]->GetNumTraveled() * mVehicles[i]->GetMaxSpeed())
			{
				max = mVehicles[i]->GetNumTraveled() * mVehicles[i]->GetMaxSpeed();
				result = mVehicles[i];
			}
		}

		return result;
	}
}