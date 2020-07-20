#include <cstring>
#include <cmath>
#include "PolyLine.h"

namespace lab4
{
	PolyLine::PolyLine()
	{
	}

	PolyLine::PolyLine(const PolyLine& other)
	{
		for (unsigned int i = 0; i < 10; i++)
		{
			if (i + 1 <= other.mLength)
			{
				mPoints[i] = new Point(other[i]->GetX(), other[i]->GetY());
			}
			else 
			{
				mPoints[i] = nullptr;
			}
		}
		mLength = other.mLength;
	}

	PolyLine::~PolyLine()
	{
		for (unsigned int i = 0; i < mLength; i++)
		{
			delete mPoints[i];
			mPoints[i] = nullptr;
		}
	}

	bool PolyLine::AddPoint(float x, float y)
	{
		if (mLength < 10)
		{
			mPoints[mLength] = new Point(x, y);
			mLength++;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::AddPoint(const Point* point)
	{
		if (mLength < 10)
		{
			mPoints[mLength] = point;
			mLength++;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::RemovePoint(unsigned int i)
	{
		if (mLength == 0)
		{
			return false;
		}

		if (i < mLength - 1)
		{
			delete mPoints[i];
			for (unsigned int j = i; j < mLength - 1; j++)
			{
				mPoints[i] = mPoints[i + 1];
				i++;
			}
			mPoints[i] = nullptr;

			mLength--;

			return true;
		}
		else if (i == mLength - 1)
		{
			delete mPoints[i];
			mPoints[i] = nullptr;
			mLength--;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool PolyLine::TryGetMinBoundingRectangle(Point* outMin, Point* outMax) const
	{
		float minX, minY, maxX, maxY;

		if (0 < mLength && mLength <= 10)
		{
			minX = mPoints[0]->GetX();
			minY = mPoints[0]->GetY();
			maxX = mPoints[0]->GetX();
			maxY = mPoints[0]->GetY();
		}
		else
		{
			return false;
		}

		for (unsigned int i = 1; i < mLength; i++)
		{
			if (mPoints[i]->GetX() <= minX) 
			{ 
				minX = mPoints[i]->GetX(); 
			}
			if (mPoints[i]->GetY() <= minY) 
			{ 
				minY = mPoints[i]->GetY(); 
			}
			if (maxX <= mPoints[i]->GetX()) 
			{ 
				maxX = mPoints[i]->GetX(); 
			}
			if (maxY <= mPoints[i]->GetY()) 
			{ 
				maxY = mPoints[i]->GetY(); 
			}
		}

		if (minX != maxX && minY != maxY)
		{
			outMin->SetX(minX);
			outMin->SetY(minY);
			outMax->SetX(maxX);
			outMax->SetY(maxY);

			return true;
		}
		else
		{
			outMin->SetX(minX);
			outMin->SetY(minY);
			outMax->SetX(maxX);
			outMax->SetY(maxY);

			return true;
		}
	}

	const Point* PolyLine::operator[](unsigned int i) const
	{
		if (i < mLength)
		{
			return mPoints[i];
		}
		return nullptr;
	}
}