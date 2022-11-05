#pragma once

#ifndef VEC_FINAL_H
#define VEC_FINAL_H

#include<ctype.h>
#include "vec-base.h"

template <typename T> class Vector:public VectorBase<T>
{
public:
	Vector(int size = 0, const T* x = NULL);	// 构造函数（含默认的构造函数、转换构造函数）
	Vector(const Vector& v);				// 拷贝构造函数（实现深拷贝构造）
	~Vector();							// 析构函数（虚函数）
	Vector<T>& operator=(const Vector& v);		// 赋值运算符函数（实现深赋值运算）
	T& operator[](int index) const throw(int);		// 方括号运算符函数（引用返回，可作左值）;下表越界时抛掷异常
	int getsize() const;
	void Input(istream& in);
	void Output(ostream& out) const;
	void resize(int size);
	void push_back(const T element);				//尾插
	void insert(int index, const T element);		//插入
	void pop_back();								//弹出尾元素
	void erase(int index);							//删除指定位置元素
	void reverse(int begin, int end);				//颠倒指定范围元素
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
protected:
	int l;
	T* data;
};

template <typename T>
Vector<T>::Vector(int size, const T* x)		// 构造函数（含默认的构造函数、转换构造函数）
{
	this->l = (size > 0) ? size : 0;
	data = NULL;
	if (this->l > 0)
	{
		data = new T[this->l];
		for (int i = 0; i < this->l; i++)
			data[i] = (x == NULL) ? 0 : x[i];
	}
}

template <typename T>
Vector<T>::Vector(const Vector<T>& v)	// 拷贝构造函数（实现深拷贝构造）
{
	this->l = 0;
	data = NULL;
	*this = v;
}
template <typename T>
Vector<T>::~Vector()						// 析构函数（虚函数）
{
	this->l = 0;
	if (data != NULL) delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)// 赋值运算符函数（实现深赋值运算）
{
	if (this->l != v.l)
	{
		if (data != NULL) delete[] data;
		data = new T[this->l = v.l];
	}
	for (int i = 0; i < this->l; i++)
		data[i] = v.data[i];
	return *this;
}

template <typename T>
T& Vector<T>::operator[](int index) const throw(int)// 方括号运算符函数（引用返回，可作左值）
{
	if (data == NULL)
		throw 0;
	if (index < 0 || index >= this->l)
		throw - 1;
	return data[index];
}

template <typename T>
int Vector<T>::getsize() const				// 获取向量的维数（常量成员函数）
{
	return this->l;
}

template <typename T>
ostream& operator<<(ostream& out, const Vector<T>& v)
{
	v.Output(out);
	return out;
}

template <typename T>
istream& operator>>(istream& in, Vector<T>& v)
{
	v.Input(in);
	return in;
}

template <typename T>
void Vector<T>::Output(ostream& out) const
{
	out << "(";
	for (int i = 0; i < this->l; i++)
	{
		out << this->data[i];
		if (i != this->l - 1)
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
	if (size < 0 || size == this->l);
	else if (size == 0)
	{
		if (this->data != nullptr) delete[] this->data;
		this->data = nullptr;
		this->l = 0;
	}
	else
	{
		T* temp = this->data;
		this->data = new T[size];
		if (size > this->l)
		{
			for (int i = 0; i < this->l; i++)
				this->data[i] = temp[i];
			for (int i = this->l; i < size; i++)
				this->data[i] = 0;
		}
		else
		{
			for (int i = 0; i < size; i++)
				this->data[i] = temp[i];
		}
		this->l = size;
		delete[] temp;
	}
}
//new func
template <typename T>
void Vector<T>::insert(int index, const T element)
{
	int size = this->l;
	this->resize(size+1);
	for (int i = (this->l) - 1; i > index + 1; --i)
		data[i] = data[i - 1];
	data[index + 1] = element;
}

template <typename T>
void Vector<T>::push_back(const T element)
{
	int temp = this->l - 1;
	this->resize(++this->l);
	this->insert(temp, element);
}

template <typename T>
void Vector<T>::erase(int index)
{
	for (int i = index; i < this->l - 1; ++i)
		data[i] = data[i + 1];
	int size = this->l;
	this->resize(size-1);
}

template <typename T>
void Vector<T>::pop_back()
{
	this->erase(this->l - 1);
}

template <typename T>
void Vector<T>::reverse(int begin, int end)
{
	int mid = (begin + end) / 2;
	for (int i = begin; i <= mid; ++i)
	{
		cout << *this << endl;
		swap(data[i], data[end - i]);
	}
}
template <typename T>
void Vector<T>::clear()
{
	this->resize(0);
}

template <typename T>
bool Vector<T>::empty()
{
	return this->l == 0;
}

template <typename T>
T& Vector<T>::front()
{
	return data[0];
}

template <typename T>
T& Vector<T>::back()
{
	return data[this->l - 1];
}

#endif