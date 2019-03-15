#pragma once

#include <iostream>
#include "Pair.h"

template <typename T>
class Settings
{
public:
	Settings();
	Settings <T>& operator=(const Settings& s);
	Settings(const Settings& s);
	~Settings();
	int Count()const;
	void Set(const char* key, T value);
	bool Get(const char* key, T& value)const;
	void Print()const;

private:
	void Resize();

	enum { MAX_SIZE = 100 };
	Pair<T> * pair;
	int numberOfPairs;
	int size;
};

template<typename T>
inline Settings<T>::Settings()
{
	this->size = MAX_SIZE;
	this->numberOfPairs = 0;
	this->pair = new Pair<T>[this->size];
}

template<typename T>
inline Settings<T> & Settings<T>::operator=(const Settings & s)
{
	if (this != &s)
	{
		delete[]this->pair;
		this->numberOfPairs = s.numberOfPairs;
		this->size = s.size;
		this->pair = new Pair<T>[this->size];
		for (int i = 0; i < this->numberOfPairs; i++)
		{
			this->pair[i].SetValue(s.pair[i].GetValue());
			this->pair[i].SetKey(s.pair[i].GetKey());
		}
	}
	return *this;
}

template<typename T>
inline Settings<T>::Settings(const Settings & s)
{
	this->numberOfPairs = s.numberOfPairs;
	this->size = s.size;
	this->pair = new Pair<T>[this->size];
	for (int i = 0; i < this->numberOfPairs; i++)
	{
		this->pair[i].SetValue(s.pair[i].GetValue());
		this->pair[i].SetKey(s.pair[i].GetKey());
	}
}

template<typename T>
inline Settings<T>::~Settings()
{
	delete[]this->pair;
}

template<typename T>
inline int Settings<T>::Count() const
{
	return this->numberOfPairs;
}

template<typename T>
inline void Settings<T>::Set(const char * key, T value)
{
	bool havePair = false;
	if (this->numberOfPairs + 1 >= this->size)
	{
		Resize();
	}
	for (int i = 0; i < this->numberOfPairs; i++)
	{
		if (strcmp(this->pair[i].GetKey(), key) == 0)
		{
			this->pair[i].SetValue(value);
			havePair = true;
		}
	}
	if (havePair == false)
	{
		this->pair[this->numberOfPairs].SetKey(key);
		this->pair[this->numberOfPairs].SetValue(value);
		this->numberOfPairs++;
	}
}

template<typename T>
inline bool Settings<T>::Get(const char * key, T & value) const
{
	for (int i = 0; i < this->numberOfPairs; i++)
	{
		if (strcmp(this->pair[i].GetKey(), key) == 0)
		{
			value = this->pair[i].GetValue();
			return true;
		}
	}
	return false;
}

template<typename T>
inline void Settings<T>::Print() const
{
	for (int i = 0; i < this->numberOfPairs; i++)
	{
		std::cout << "Key: " << this->pair[i].GetKey() << std::endl;
		std::cout << "Value: " << this->pair[i].GetValue() << std::endl;
		std::cout << "**************************************************" << std::endl;
	}
}

template<typename T>
void Settings<T>::Resize()
{
	Pair<T>* newArr = new Pair<T>[this->size * 2];
	for (int i = 0; i < this->numberOfPairs; i++)
	{
		newArr[i].SetValue(this->pair[i].GetValue());
		newArr[i].SetKey(this->pair[i].GetKey());
	}
	this->size = size * 2;
	delete[]this->pair;
	pair = newArr;
}
