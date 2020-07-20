#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		virtual ~UBoat();

		void Travel();
		unsigned int GetSailSpeed();
		unsigned int GetDiveSpeed();
		unsigned int GetMaxSpeed();
	};
}