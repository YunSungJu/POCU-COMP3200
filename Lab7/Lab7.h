#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		unsigned int k_size = keys.size();
		unsigned int v_size = values.size();
		unsigned int m_size = k_size > v_size ? v_size : k_size;

		//std::map<K, V>::iterator iter;
		std::map<K, V> m;

		for (unsigned int i = 0; i < m_size; i++)
		{
			m.insert(std::pair<K, V>(keys[i], values[i]));
		}
		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		typename std::map<K, V>::const_iterator iter;

		for (iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;
		typename std::map<K, V>::const_iterator iter;

		for (iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;
		typename std::vector<T>::const_reverse_iterator iter;

		for (iter = v.rbegin(); iter != v.rend(); iter++)
		{
			rv.push_back(*iter);
		}
		return rv;
	}
}

template <typename T>
std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
{
	std::vector<T> combined;
	typename std::vector<T>::const_iterator iter1;
	typename std::vector<T>::const_iterator iter2;


	for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
	{
		combined.push_back(*iter1);
	}

	for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)
	{
		bool bIsSame = false;

		for (iter1 = v1.begin(); iter1 != v1.end(); iter1++)
		{
			if (*iter1 == *iter2)
			{
				bIsSame = true;
			}
		}

		if (bIsSame == false)
		{
			combined.push_back(*iter2);
		}
	}


	return combined;
}

template <typename K, class V>
std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
{
	std::map<K, V> combined;
	typename std::map<K, V>::const_iterator iter;

	for (iter = m1.begin(); iter != m1.end(); iter++)
	{
		combined.insert(*iter);
	}

	for (iter = m2.begin(); iter != m2.end(); iter++)
	{
		combined.insert(*iter);
	}

	return combined;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
	if (v.size() == 1)
	{
		os << v[0];
	}
	else
	{
		typename std::vector<T>::const_iterator iter;
		for (iter = v.begin(); iter + 1 != v.end(); iter++)
		{
			os << *iter << ", ";
		}
		os << *iter;
	}

	return os;
}

template <typename K, class V>
std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
{
	typename std::map<K, V>::const_iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
	}

	return os;
}