#pragma once

#include "Person.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle();
		Vehicle(unsigned int maxPassengersCount);
		Vehicle(Vehicle* vehicle);
		virtual ~Vehicle();

		virtual unsigned int GetMaxSpeed() = 0;
		virtual void Travel() = 0;

		void ResetPassenger();
		void IncreaseNumTraveled();
		void IncreaseNumTravel();

		bool AddPassenger(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetTotalWeight() const;
		unsigned int GetNumTravel() const;
		unsigned int GetNumTraveled() const;
		

	private:
		unsigned int mMaxCount;
		unsigned int mLength;
		unsigned int mNumTravel;
		unsigned int mNumTraveled;
		const Person* mPeople[100];
	};
}