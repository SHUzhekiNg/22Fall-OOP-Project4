#pragma once
#ifndef VEC_BASE_H
#define VEC_BASE_H
#include <iostream>
using namespace std;

template <typename T> class VectorBase			
{
public:
	VectorBase(int size = 0, const T* x = NULL);	// 构造函数（含默认的构造函数、转换构造函数）
	VectorBase(const VectorBase& v);				// 拷贝构造函数（实现深拷贝构造）
	virtual ~VectorBase()=0;							// 析构函数（虚函数）
	VectorBase& operator=(const VectorBase& v);		// 赋值运算符函数（实现深赋值运算）
	T& operator[](int index) const throw(int);		// 方括号运算符函数（引用返回，可作左值）;下表越界时抛掷异常
	
	int getsize() const;
	virtual void resize(int size) = 0;
	virtual void Output(ostream& out) const = 0;
	virtual void Input(istream& in) = 0;
	virtual void push_back(const T& element) = 0;
	virtual void insert(int& index, const T& element) = 0;
	virtual void pop_back() = 0;
	virtual void erase(int& index) = 0;
	virtual void reverse(int& begin, int& end) = 0;
	virtual void clear() = 0;
	virtual bool empty() = 0;
protected:
	int l;
	T* data;
};

template <typename T>
VectorBase<T>::VectorBase(int size, const T* x)		// 构造函数（含默认的构造函数、转换构造函数）
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
VectorBase<T>::VectorBase(const VectorBase<T>& v)	// 拷贝构造函数（实现深拷贝构造）
{
	this->l = 0;
	data = NULL;
	*this = v;
}

template <typename T>
VectorBase<T>::~VectorBase()						// 析构函数（虚函数）
{
	this->l = 0;
	if (data != NULL) delete[] data;
}

template <typename T>
VectorBase<T>& VectorBase<T>::operator=(const VectorBase<T>& v)// 赋值运算符函数（实现深赋值运算）
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
T& VectorBase<T>::operator[](int index) const throw(int)// 方括号运算符函数（引用返回，可作左值）
{
	if (data == NULL)
		throw 0;							
	if (index < 0 || index >= this->l)
		throw - 1;
	return data[index];
}

template <typename T>
int VectorBase<T>::getsize() const				// 获取向量的维数（常量成员函数）
{
	return this->l;
}

template <typename T>
ostream& operator<<(ostream& out, const VectorBase<T>& v)	
{
	v.Output(out);
	return out;
}

template <typename T>
istream& operator>>(istream& in, VectorBase<T>& v)			
{
	v.Input(in);
	return in;
}

#endif