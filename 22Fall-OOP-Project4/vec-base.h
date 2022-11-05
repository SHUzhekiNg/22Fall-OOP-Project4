#pragma once
#ifndef VEC_BASE_H
#define VEC_BASE_H
#include <iostream>
using namespace std;

template <typename T> class VectorBase			
{
public:
	VectorBase(int size = 0, const T* x = NULL);	// ���캯������Ĭ�ϵĹ��캯����ת�����캯����
	VectorBase(const VectorBase& v);				// �������캯����ʵ��������죩
	virtual ~VectorBase()=0;							// �����������麯����
	VectorBase& operator=(const VectorBase& v);		// ��ֵ�����������ʵ���ֵ���㣩
	T& operator[](int index) const throw(int);		// ��������������������÷��أ�������ֵ��;�±�Խ��ʱ�����쳣
	
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
VectorBase<T>::VectorBase(int size, const T* x)		// ���캯������Ĭ�ϵĹ��캯����ת�����캯����
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
VectorBase<T>::VectorBase(const VectorBase<T>& v)	// �������캯����ʵ��������죩
{
	this->l = 0;
	data = NULL;
	*this = v;
}

template <typename T>
VectorBase<T>::~VectorBase()						// �����������麯����
{
	this->l = 0;
	if (data != NULL) delete[] data;
}

template <typename T>
VectorBase<T>& VectorBase<T>::operator=(const VectorBase<T>& v)// ��ֵ�����������ʵ���ֵ���㣩
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
T& VectorBase<T>::operator[](int index) const throw(int)// ��������������������÷��أ�������ֵ��
{
	if (data == NULL)
		throw 0;							
	if (index < 0 || index >= this->l)
		throw - 1;
	return data[index];
}

template <typename T>
int VectorBase<T>::getsize() const				// ��ȡ������ά����������Ա������
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