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
	void push_back(const T& element);				//β��
	void insert(int& index, const T& element);		//����
	void pop_back();								//����βԪ��
	void erase(int index);							//ɾ��ָ��λ��Ԫ��
	void reverse(int& begin, int& end);				//�ߵ�ָ����ΧԪ��
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
};

#endif