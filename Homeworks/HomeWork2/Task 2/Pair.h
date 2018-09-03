#pragma once

#include <iostream>

template <typename T>
class Pair
{
public:
	Pair();
	Pair(const char* key, T val);
	Pair(const Pair& p);
	Pair<T> &operator=(const Pair& p);
	~Pair();
	const char* GetKey()const;
	void SetKey(const char * key);
	T GetValue()const;
	void SetValue(T val);
private:
	char* key;
	T val;
};

template<typename T>
inline Pair<T>::Pair()
{
	this->SetKey("no key");
}

template<typename T>
inline Pair<T>::Pair(const char * key, T val)
{
	this->SetKey(key);
	this->SetValue(val);
}
template<typename T>
inline Pair<T>::Pair(const Pair& p)
{
	this->SetKey(p.GetKey());
	this->SetValue(p.GetValue());
}
template<typename T>
inline Pair<T> & Pair<T>::operator=(const Pair& p)
{
	if (this != &p)
	{
		delete[]this->key;
		this->SetKey(p.GetKey());
		this->SetValue(p.GetValue());
	}
	return *this;
}

template<typename T>
inline Pair<T>::~Pair()
{
	delete[]this->key;
}

template<typename T>
inline const char * Pair<T>::GetKey() const
{
	return this->key;
}

template<typename T>
inline void Pair<T>::SetKey(const char* key)
{
	int i = 0;
	int l = strlen(key);
	this->key = new char[l + 1];
	for (i = 0; i < l; i++)
	{
		this->key[i] = key[i];
	}
	this->key[i] = 0;
}

template<typename T>
inline T Pair<T>::GetValue() const
{
	return this->val;
}

template<typename T>
inline void Pair<T>::SetValue(T val)
{
	this->val = val;
}