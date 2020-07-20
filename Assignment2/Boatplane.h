#pragma once

#include "Vehicle.h"
#include "IFlyable.h"
#include "IDrivable.h"
#include "ISailable.h"

namespace assignment2
{
	class Boatplane : public Vehicle, public IFlyable, public ISailable
	{
	public:
		Boatplane(unsigned int maxPassengersCount);
		Boatplane(Boatplane* boatplane);
		virtual ~Boatplane();

		void Travel();
		unsigned int GetFlySpeed();
		unsigned int GetSailSpeed();
		unsigned int GetMaxSpeed();

	};
}