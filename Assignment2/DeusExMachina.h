#pragma once

#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		virtual ~DeusExMachina() 
		{
			mbIsDEM = false;
			for (unsigned int i = 0; i < mLength; i++)
			{
				delete mVehicles[i];
				mVehicles[i] = nullptr;
			}
		};

		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;

	private:
		DeusExMachina()
		{
			mLength = 0;
			for (unsigned int i = 0; i < 10; i++)
			{
				mVehicles[i] = nullptr;
			}
		};

		static bool mbIsDEM;
		static DeusExMachina* mDEM;
		unsigned int mLength;
		
		Vehicle* mVehicles[10];
	};
}

