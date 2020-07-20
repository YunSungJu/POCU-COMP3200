#pragma once

#include "Boatplane.h"
#include "ISailable.h"

namespace assignment2
{
	class Airplane;

	class Boat : public Vehicle, public ISailable
	{
	public:
		Boat(unsigned int maxPassengersCount);
		virtual ~Boat();
		
		void Travel();
		unsigned int GetSailSpeed();
		unsigned int GetMaxSpeed();

		Boatplane operator+(Airplane& plane);
	};
}