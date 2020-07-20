#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable
	{
	public:
		Sedan();
		virtual ~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();

		void Travel();
		unsigned int GetDriveSpeed();
		unsigned int GetMaxSpeed();

	public:
		bool bIsTrailer;
		const Trailer* MTrailer;
	};
}