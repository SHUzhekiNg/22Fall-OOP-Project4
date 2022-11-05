#pragma once

#ifndef VEC_FINAL_H
#define VEC_FINAL_H

#include<ctype.h>
#include "vec-base.h"

template <typename T> class Vector:public VectorBase<T>
{
public:
	Vector(int size = 0, const T* x = NULL);	// ���캯������Ĭ�ϵĹ��캯����ת�����캯����
	Vector(const Vector& v);				// �������캯����ʵ��������죩
	~Vector();							// �����������麯����
	Vector<T>& operator=(const Vector& v);		// ��ֵ�����������ʵ���ֵ���㣩
	T& operator[](int index) const throw(int);		// ��������������������÷��أ�������ֵ��;�±�Խ��ʱ�����쳣
	int getsize() const;
	void Input(istream& in);
	void Output(ostream& out) const;
	void resize(int size);
	void push_back(const T element);				//β��
	void insert(int index, const T element);		//����
	void pop_back();								//����βԪ��
	void erase(int index);							//ɾ��ָ��λ��Ԫ��
	void reverse(int begin, int end);				//�ߵ�ָ����ΧԪ��
	bool empty();
	void clear();
	T& front();										//��������������,������Ԫ������
	T& back();										//��������������������βԪ������
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
Vector<T>::Vector(int size, const T* x)		// ���캯������Ĭ�ϵĹ��캯����ת�����캯����
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
Vector<T>::Vector(const Vector<T>& v)	// �������캯����ʵ��������죩
{
	this->l = 0;
	data = NULL;
	*this = v;
}
template <typename T>
Vector<T>::~Vector()						// �����������麯����
{
	this->l = 0;
	if (data != NULL) delete[] data;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& v)// ��ֵ�����������ʵ���ֵ���㣩
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
T& Vector<T>::operator[](int index) const throw(int)// ��������������������÷��أ�������ֵ��
{
	if (data == NULL)
		throw 0;
	if (index < 0 || index >= this->l)
		throw - 1;
	return data[index];
}

template <typename T>
int Vector<T>::getsize() const				// ��ȡ������ά����������Ա������
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