#pragma once

#ifndef VEC_FINAL_H
#define VEC_FINAL_H

#include "vec-base.h"

template <typename T> class Vector : public VectorBase<T>
{
public:
	Vector(int size = 0, const T* x = NULL);

	void Input(istream& in);
	void Output(ostream& out) const;
	void resize(int size);
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
Vector<T>::Vector(int size, const T* x) : VectorBase<T>(size, x)		// 构造函数
{
}

template <typename T>
void Vector<T>::Output(ostream& out) const
{
	if (this->num == 0)
		out << "()";
	else
	{
		out << "(" << this->p[0];
		for (int i = 1; i < this->num; i++)
			out << ", " << this->p[i];
		out << ")";
	}
}

template <typename T>
void Vector<T>::Input(istream& in)	// 具有自动扩展容器容量的功能
{
	const int M = 1024, N = 1;//1024;	// N取最小值1是为了调试，实际使用时取1024
	Vector<T> temp;
	char str[M], ch;				// ch初始化为一个非')'字符即可
	T buffer[N];
	int i, j, k;

	in.getline(str, M, '(');		// 过滤掉'('及之前的所有字符
	while (true)						// 过滤掉左圆括号之后的空白字符
	{
		ch = in.peek();				// 偷看下一个字符，看是否为空白字符
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r')
			in.get(ch);				// 若是空白字符，则过滤掉（即读取后不用）
		else
			break;					// 直到遇到非空白字符，结束本while循环
	}

	if (in.peek() == ')')				// 偷看下一个字符，若是')'
	{
		this->resize(0);			// 将本对象的维数设置成 0 维
		return;						// 退出本函数，输入为 0 维向量
	}

	for (k = 0; ch != ')'; k++)
	{
		for (i = 0; i < N && ch != ')'; i++)
			in >> buffer[i] >> ch;
		temp.resize(k * N + i);			// 利用了resize函数的"尽量保留了原有数据"的功能
		for (j = 0; j < i; j++)
			temp[k * N + j] = buffer[j];// 利用了方括号运算符
	}
	*this = temp;					// 利用了赋值运算符（深赋值运算）
}

template <typename T>
Vector<T> operator+(const Vector<T>& v1, const Vector<T>& v2) throw(double)
{
	if (v1.getsize() != v2.getsize())
		throw - 1.0;					// 遇到问题时"一抛了之"。将"矛盾上交"由"上级部门"酌情处理
	Vector<T> result(v1);
	for (int i = v1.getsize() - 1; i >= 0; i--)// 避免多次调用v1.getsize()函数
		result[i] += v2[i];			// 利用了方括号运算符
	return result;
}

template <typename T>
Vector<T> operator-(const Vector<T>& v1, const Vector<T>& v2) throw(double)
{
	if (v1.getsize() != v2.getsize())
		throw - 1.0;					// 遇到问题时"一抛了之"。将"矛盾上交"由"上级部门"酌情处理
	Vector<T> result(v1);
	for (int i = v1.getsize() - 1; i >= 0; i--)// 避免多次调用v1.getsize()函数
		result[i] -= v2[i];			// 利用了方括号运算符
	return result;
}

template <typename T>
Vector<T> operator*(const T& x, const Vector<T>& v)
{
	Vector<T> result(v);
	for (int i = v.getsize() - 1; i >= 0; i--)
		result[i] = x * v[i];
	return result;
}

template <typename T>
Vector<T> operator*(const Vector<T>& v, const T& x)
{
	return x * v;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& v) throw(double)
{
	return *this = *this + v;
}

template <typename T>
Vector<T>& Vector<T>::operator-=(const Vector<T>& v) throw(double)
{
	return *this = *this - v;
}

template <typename T>
Vector<T>& Vector<T>::operator*=(const T& x)
{
	return *this = x * (*this);
}

//Done
template <typename T>
bool operator==(const Vector<T>& v1, const Vector<T>& v2)
{
	int i, n1 = v1.getsize(), n2 = v2.getsize();
	for (i = 0; i < n1 && i < n2 && v1[i] == v2[i]; i++)
		;
	if (i < n1 || i < n2)
		return false;
	else
		return true;
}

template <typename T>
bool operator!=(const Vector<T>& v1, const Vector<T>& v2)
{
	return !(v1 == v2);
}

template <typename T>
void Vector<T>::resize(int size)			// 指定向量的维数（尽量保留原有的数据）
{
	if (size < 0 || size == this->num)
		return;
	else if (size == 0)
	{
		if (this->p != NULL) delete[] this->p;
		this->p = NULL;
		this->num = 0;
	}
	else
	{
		T* temp = this->p;
		this->p = new T[size];
		for (int i = 0; i < size; i++)
			this->p[i] = (i < this->num) ? temp[i] : 0;	// 尽量保留原有数据
		this->num = size;
		delete[] temp;
	}
}

#endif // !VEC_FINAL_H