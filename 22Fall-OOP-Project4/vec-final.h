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
	void push_back(const T& element);				//尾插
	void insert(int& index, const T& element);		//插入
	void pop_back();								//弹出尾元素
	void erase(int index);							//删除指定位置元素
	void reverse(int& begin, int& end);				//颠倒指定范围元素
	bool empty();
	void clear();
	T& front();										//派生类新增函数,返回首元素引用
	T& back();										//派生类新增函数，返回尾元素引用
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

#endif