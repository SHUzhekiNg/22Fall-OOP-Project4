#pragma once
#ifndef VEC_BASE_H
#define VEC_BASE_H
#include <iostream>
using namespace std;

template <typename T> class VectorBase			
{
public:
	virtual void resize(int size) = 0;
	virtual void Output(ostream& out) const = 0;
	virtual void Input(istream& in) = 0;
	virtual void push_back(const T element) = 0;
	virtual void insert(int index, const T element) = 0;
	virtual void pop_back() = 0;
	virtual void erase(int index) = 0;
	virtual void reverse(int begin, int end) = 0;
	virtual void clear() = 0;
	virtual bool empty() = 0;

};





#endif