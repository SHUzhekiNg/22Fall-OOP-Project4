#pragma once

#ifndef VEC_FINAL_H
#define VEC_FINAL_H

#include<ctype.h>
#include "vec-base.h"

template <typename T> class Vector : public VectorBase<T>
{
public:
	Vector(int size = 0, const T* x = NULL);

	void Input(istream& in);
	void Output(ostream& out) const;
	void resize(int size);
	void push_back(const T& element); //尾插
	void insert(int& index, const T& element); //插入
	void pop_back(); //弹出尾元素
	void erase(int& index);//删除指定位置元素
	void reverse(int& begin, int& end); //颠倒指定范围元素
	bool empty();
	void clear();
	T& front(); //派生类新增函数,返回首元素引用
	T& back(); //派生类新增函数，返回尾元素引用
	template <typename T> friend Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) throw(double);
	template <typename T> friend Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2) throw(double);
	template <typename T> friend Vector<T> operator*(const T& x, const Vector<T>& v);
	template <typename T> friend Vector<T> operator*(const Vector<T>& v, const T& x);
	Vector<T>& operator+=(const Vector<T>& v) throw(double);
	Vector<T>& operator-=(const Vector<T>& v) throw(double);
	Vector<T>& operator*=(const T& x);
	template <typename T> friend bool operator==(const Vector<T>& v1, const Vector<T>& v2);
	template <typename T> friend bool operator!=(const Vector<T>& v1, const Vector<T>& v2);
};

template <typename T>
Vector<T>::Vector(int size, const T* x) : VectorBase<T>(size, x)		// 构造函数
{
}

template <typename T>
void Vector<T>::Output(ostream& out) const
{
	out << "(";
	for (int i = 0; i < this->num; i++)
	{
		out << this->p[i];
		if (i != this->num - 1)
			out << ", ";
	}
	out << ")";
}

template <typename T>
void Vector<T>::Input(istream& in)
{
	T element;
	while (in >> element)
		this->push_back(element);
}

template <typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) throw(double)
{
	Vector<T> ret(v1);
	if (v1.getsize() != v2.getsize())
		throw - 1.0;					
	for (int i = v1.getsize() - 1; i >= 0; i--)
		ret[i] += v2[i];			
	return ret;
}

template <typename T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2) throw(double)
{
	Vector<T> ret(v1);
	if (v1.getsize() != v2.getsize())
		throw - 1.0;					
	for (int i = v1.getsize() - 1; i >= 0; i--)
		ret[i] -= v2[i];			
	return ret;
}

template <typename T>
Vector<T> operator*(const T& x, const Vector<T>& v)
{
	Vector<T> ret(v);
	for (int i = v.getsize() - 1; i >= 0; i--)
		ret[i] = x * v[i];
	return ret;
}

template <typename T>
Vector<T> operator*(const Vector<T>& v, const T& x)
{
	return x * v;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& v) throw(double)
{
	*this = *this + v;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& v) throw(double)
{
	*this = *this - v;
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator*=(const T& x)
{
	*this = x * (*this);
	return *this;
}

template <typename T>
bool operator==(const Vector<T>& v1, const Vector<T>& v2)
{
	bool ret = 1;
	int i, num1 = v1.getsize(), num2 = v2.getsize();
	if (num1 != num2)return 0;
	for (i = 0; i < num1; i++)
		if (v1[i] != v2[i])
		{
			ret = 0;
			break;
		}
	return ret;
}

template <typename T>
bool operator!=(const Vector<T>& v1, const Vector<T>& v2)
{
	return !(v1 == v2);
}

template <typename T>
void Vector<T>::resize(int size)			
{
	if (size < 0 || size == this->num);
	else if (size == 0)
	{
		if (this->p != nullptr) delete[] this->p;
		this->p = nullptr;
		this->num = 0;
	}
	else
	{
		T* temp = this->p;
		this->p = new T[size];
		if (size > this->num)
		{
			for (int i = 0; i < num; i++)
				this->p[i] = temp[i];
			for (int i = num; i < size; i++)
				this->p[i] = 0;
		}
		else
		{
			for (int i = 0; i < size; i++)
				this->p[i] = temp[i];
		}
		this->num = size;
		delete[] temp;
	}
}
//new func
template <typename T>
void Vector<T>::insert(int& index, const T& element)
{
	this->resize(++num); //容量+1
	for (int i = num - 1; i > index + 1; --i) //index位置后元素右移1位
		p[i] = p[i - 1];
	p[index + 1] = element;
}

template <typename T>
void Vector<T>::push_back(const T& element)
{
	int temp = num - 1;
	this->resize(++num);
	this->insert(temp, element);
}

template <typename T>
void Vector<T>::erase(int& index)
{
	for (int i = index; i < num - 1; ++i)
		p[i] = p[i + 1];
	this->resize(--num);
}

template <typename T>
void Vector<T>::pop_back()
{
	this->erase(num - 1);
	this->resize(--num);
}

template <typename T>
void Vector<T>::reverse(int& begin, int& end)
{
	int mid = (begin + end) / 2;
	for (int i = begin; i <= mid; ++i)
		swap(p[i], p[end - i + 1]);
}
template <typename T>
void Vector<T>::clear()
{
	this->resize(0);
}

template <typename T>
bool Vector<T>::empty()
{
	return num == 0;
}

template <typename T>
T& Vector<T>::front()
{
	return p[0];
}

template <typename T>
T& Vector<T>::back()
{
	return p[num - 1];
}
#endif