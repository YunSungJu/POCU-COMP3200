#pragma once
#include <string>
#define SIZE 1000

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& other);
		~TimeSheet();
		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

	private:
		// �ʿ信 ���� private ������ �޼��带 �߰��ϼ���.
		unsigned int mLength, mIndex;
		std::string mName;
		int* mHours;
	};
}