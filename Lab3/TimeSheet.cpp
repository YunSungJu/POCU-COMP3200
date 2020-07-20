#include "Timesheet.h"

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		mLength = maxEntries;
		mHours = new int[mLength];
		mIndex = 0;
		mName = name;
	}

	TimeSheet::TimeSheet(const TimeSheet& other)
	{
		int i;
		mLength = other.mLength;
		mHours = new int[mLength];
		mIndex = other.mIndex;

		for (unsigned int i = 0; i < mLength; i++) 
		{
			mHours[i] = other.mHours[i];
		}

		char temp[SIZE];
		for (i = 0; other.mName[i] != '\0'; i++)
		{
			temp[i] = other.mName[i];
		}
		temp[i] = '\0';
		mName = temp;
	}


	TimeSheet::~TimeSheet()
	{
		delete[] mHours;
		mHours = nullptr;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours <= 10 && timeInHours >= 1 && mIndex < mLength)
		{
			mHours[mIndex] = timeInHours;
			mIndex++;
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index >= 0 && index < mLength)
		{
			if (index < mIndex)
			{
				return mHours[index];
			}
			return -1;
		}
		return -1;
	}

	int TimeSheet::GetTotalTime() const
	{
		int total = 0;

		for (unsigned int i = 0; i < mIndex; i++)
		{
			total += mHours[i];
		}

		return total;
	}

	float TimeSheet::GetAverageTime() const
	{
		int total = this->GetTotalTime();
		float average;
		if (mIndex != 0)
		{
			average = (float)total / mIndex;
			return average;
		}
		else
		{
			return 0.0f;
		}
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float stdDeviation = 1.0;
		float average = this->GetAverageTime();
		float totalDeviation = 0;

		for (unsigned int i = 0; i < mIndex; i++)
		{
			totalDeviation += (mHours[i] - average) * (mHours[i] - average);
		}

		if (mIndex != 0)
		{
			for (int i = 0; i < 15; i++)
			{
				stdDeviation = (stdDeviation + (totalDeviation / mIndex) / stdDeviation) / 2;
			}

			return stdDeviation;
		}
		else
		{
			return (float)0;
		}

	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}
}