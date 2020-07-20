#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		virtual ~Motorcycle();

		void Travel();
		unsigned int GetDriveSpeed();
		unsigned int GetMaxSpeed();

	};
}