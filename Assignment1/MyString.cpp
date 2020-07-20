#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
	{
		if (s == nullptr)
		{
			mStr = nullptr;
		}
		else
		{
			unsigned int i = 0;
			for (i = 0; s[i] != 0; i++)
			{
				mStr[i] = s[i];
			}
			mStr[i] = '\0';
		}
	}

	MyString::MyString(const MyString& other)
	{
		const char* s = other.GetCString();

		if (s == nullptr)
		{
			mStr = nullptr;
		}
		else
		{
			unsigned int i = 0;
			for (i = 0; s[i] != 0; i++)
			{
				mStr[i] = s[i];
			}
			mStr[i] = '\0';
		}

	}

	MyString::~MyString()
	{
		delete[] mStr;
		mStr = nullptr;
	}

	unsigned int MyString::GetLength() const
	{
		unsigned int length = 0;

		if (mStr == nullptr)
		{
			return length;
		}
		else
		{
			for (int i = 0; mStr[i] != '\0'; i++)
			{
				length++;
			}
			return length;
		}

	}

	const char* MyString::GetCString() const
	{
		const char* s;
		s = mStr;

		return s;
	}

	void MyString::Append(const char* s)
	{
		unsigned int length1 = this->GetLength(), length2 = 0;

		for (int i = 0; s[i] != 0; i++)
		{
			mStr[length1 + i] = s[i];
			length2++;
		}
		mStr[length1 + length2] = '\0';
	}

	MyString MyString::operator+(const MyString& other) const
	{
		int i = 0, j = 0;
		unsigned int length1 = this->GetLength(), length2 = other.GetLength();

		char temp[SIZE] = { 0, };

		while (mStr[i] != '\0')
		{
			temp[i] = mStr[i];
			i++;
		}
		while (other.GetCString()[j] != '\0')
		{
			temp[i] = other.GetCString()[j];
			i++;
			j++;
		}
		temp[length1 + length2] = '\0';

		return MyString(temp);
	}

	int MyString::IndexOf(const char* s)
	{
		unsigned int index = 0;
		unsigned length = 0;

		if (s == nullptr)
		{
			return -1;
		}
		for (int j = 0; s[j] != 0; j++)
		{
			length++;
		}

		if (length == 0)
		{
			return 0;
		}
		else if (this->GetLength() < length)
		{
			return -1;
		}

		for (unsigned int i = 0; i < this->GetLength(); i++)
		{
			if (mStr[i] == s[0])
			{
				for (unsigned int j = 0; j < length; j++)
				{
					if (mStr[i + j] == s[j])
					{
						index = i;
					}
					else
					{
						index = -1;
					}
				}
				if (index == i)
				{
					break;
				}
			}
			index = -1;
		}

		return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int index = 0;
		unsigned int length = 0;

		if (s == nullptr)
		{
			return -1;
		}
		for (int j = 0; s[j] != 0; j++)
		{
			length++;
		}

		if (length == 0)
		{
			return this->GetLength();
		}
		else if (this->GetLength() < length)
		{
			return -1;
		}

		for (unsigned int i = 0; i < this->GetLength(); i++)
		{
			if (mStr[this->GetLength() - 1 - i] == s[0] && i >= length - 1)
			{
				for (unsigned int j = 0; j < length; j++)
				{
					if (mStr[this->GetLength() - 1 - i + j] == s[j])
					{
						index = this->GetLength() - 1 - i;
					}
					else
					{
						index = -1;
					}
				}
				if (index == this->GetLength() - 1 - i)
				{
					break;
				}
			}
			index = -1;
		}

		return index;
	}

	void MyString::Interleave(const char* s)
	{
		unsigned int length = 0, length1 = this->GetLength(), length2 = 0;

		for (int i = 0; s[i] != 0; i++)
		{
			length2++;
		}

		char temp[SIZE] = { 0, };

		for (int i = 0; mStr[i] != 0; i++)
		{
			temp[i] = mStr[i];
		}
		temp[length1] = '\0';

		if (length1 >= length2)
		{
			length = length2;
		}
		else
		{
			length = length1;
		}

		for (unsigned int i = 0; i <= length; i++)
		{
			if (temp[i] != '\0' && s[i] != '\0')
			{
				mStr[2 * i] = temp[i];
				mStr[2 * i + 1] = s[i];
			}
			else if (temp[i] == '\0')
			{
				for (int j = 0; s[i + j] != '\0'; j++)
				{
					mStr[2 * i + j] = s[i + j];
				}
			}
			else if (s[i] == '\0')
			{
				for (int j = 0; temp[i + j] != '\0'; j++)
				{
					mStr[2 * i + j] = temp[i + j];
				}
			}
		}
		mStr[length1 + length2] = '\0';
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		unsigned int idx = index;
		unsigned int length = this->GetLength();

		if (idx < length)
		{
			for (unsigned int i = idx; i < length; i++)
			{
				mStr[i] = mStr[i + 1];
			}
			mStr[length - 1] = '\0';
			return true;
		}
		else
		{
			return false;
		}
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		unsigned int length = this->GetLength();

		if (length < totalLength)
		{
			int index = totalLength - length;

			for (unsigned int i = 0; i < length; i++)
			{
				mStr[length - 1 - i + index] = mStr[length - 1 - i];
			}
			for (int i = 0; i < index; i++)
			{
				mStr[i] = ' ';
			}
			mStr[totalLength] = '\0';
		}
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		unsigned int length = this->GetLength();


		if (length < totalLength)
		{
			int index = totalLength - length;

			for (unsigned int i = 0; i < length; i++)
			{
				mStr[length - 1 - i + index] = mStr[length - 1 - i];
			}
			for (int i = 0; i < index; i++)
			{
				mStr[i] = c;
			}
			mStr[totalLength] = '\0';
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		unsigned int length = this->GetLength();
		int index = totalLength - length;

		if (length < totalLength)
		{
			for (int i = 0; i < index; i++)
			{
				mStr[i + length] = ' ';
			}
			mStr[totalLength] = '\0';
		}
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		unsigned int length = this->GetLength();
		int index = totalLength - length;

		if (length < totalLength)
		{
			for (int i = 0; i < index; i++)
			{
				mStr[i + length] = c;
			}
			mStr[totalLength] = '\0';
		}
	}

	void MyString::Reverse()
	{
		char c = ' ';
		int i = 0, head = 0, end = this->GetLength();

		while (head <= end - 1)
		{
			c = mStr[head];
			mStr[head] = mStr[end - 1];
			mStr[end - 1] = c;
			head++, end--;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		int result = 0;
		int length1 = this->GetLength(), length2 = rhs.GetLength();

		if (length1 != length2)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < length1; i++)
			{
				if (mStr[i] == rhs.GetCString()[i])
				{
					result++;
				}
			}
			if (result == length1)
			{
				return true;
			}
			return false;
		}
	}

	void MyString::ToLower()
	{
		int length = this->GetLength();

		for (int i = 0; i < length; i++)
		{
			if (65 <= mStr[i] && mStr[i] <= 90)
			{
				mStr[i] = mStr[i] + 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		int length = this->GetLength();

		for (int i = 0; i < length; i++)
		{
			if (97 <= mStr[i] && mStr[i] <= 122)
			{
				mStr[i] = mStr[i] - 32;
			}
		}
	}
}