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
	void push_back(const T& element); //β��
	void insert(int& index, const T& element); //����
	void pop_back(); //����
	void erase(int& index);//ɾ��ָ��λ��Ԫ��
	void reverse(int& begin, int& end); //�ߵ�ָ����ΧԪ��
	bool empty();
	void clear();
	T& front(); //��������������
	T& back(); //��������������
	template <typename TYPE> friend Vector<TYPE> operator+(const Vector<TYPE>& v1, const Vector<TYPE>& v2) throw(double);
	template <typename TYPE> friend Vector<TYPE> operator-(const Vector<TYPE>& v1, const Vector<TYPE>& v2) throw(double);
	template <typename TYPE> friend Vector<TYPE> operator*(const T& x, const Vector<TYPE>& v);
	template <typename TYPE> friend Vector<TYPE> operator*(const Vector<TYPE>& v, const T& x);
	Vector<T>& operator+=(const Vector<T>& v) throw(double);
	Vector<T>& operator-=(const Vector<T>& v) throw(double);
	Vector<T>& operator*=(const T& x);
	template <typename TYPE> friend bool operator==(const Vector<TYPE>& v1, const Vector<TYPE>& v2);
	template <typename TYPE> friend bool operator!=(const Vector<TYPE>& v1, const Vector<TYPE>& v2);
};

template <typename T>
Vector<T>::Vector(int size, const T* x) : VectorBase<T>(size, x)		// ���캯��
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
	const int MAX_SIZE = 1024;			//�ܶ�ȡ���ά��
	Vector<T> temp;
	char ch = '0';
	T buffer[MAX_SIZE];
	int i, j, k;

	while (true)						// ������Բ����֮ǰ�Ŀհ��ַ�
	{
		ch = in.peek();				
		if (ch == '(') 
		{
			in.get(ch);
			break;
		}
		else
			in.get(ch);
	}
	while (true)						// ������Բ����֮��Ŀհ��ַ�
	{
		ch = in.peek();
		if (isspace(ch))
			in.get(ch);
		else
			break;
	}

	if (in.peek() == ')')				// ����')'������Ϊ��
	{
		this->resize(0);
		return;
	}

	for (k = 0; ch != ')'; k++)
	{
		for (i = 0; i < MAX_SIZE && ch != ')'; i++)
			in >> buffer[i] >> ch;
		temp.resize(k * MAX_SIZE + i);
		for (j = 0; j < i; j++)
			temp[k * MAX_SIZE + j] = buffer[j];
	}
	*this = temp;
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
	this->resize(++num); //����+1
	for (int i = num - 1; i > index + 1; --i) //indexλ�ú�Ԫ������1λ
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