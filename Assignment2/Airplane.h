#pragma once

#include "Boatplane.h"
#include "IFlyable.h"
#include "IDrivable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IFlyable, public IDrivable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		virtual ~Airplane();

		void Travel();
		unsigned int GetFlySpeed();
		unsigned int GetDriveSpeed();
		unsigned int GetMaxSpeed();

		Boatplane operator+(Boat& boat);
	};
}