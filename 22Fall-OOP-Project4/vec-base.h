#pragma once
#ifndef VEC_BASE_H
#define VEC_BASE_H
#include <iostream>
using namespace std;

template <typename T> class VectorBase			// 抽象向量类模板（描述）必须将成员函数的实现全写入头文件中！
{
public:
	VectorBase(int size = 0, const T* x = NULL);	// ① 构造函数（含默认的构造函数、转换构造函数）
	VectorBase(const VectorBase& v);				// ② 拷贝构造函数（实现深拷贝构造）
	virtual ~VectorBase();						// ③ 析构函数（虚函数）
	VectorBase& operator=(const VectorBase& v);	// ④ 赋值运算符函数（实现深赋值运算）
	T& operator[](int index) const throw(int);
	// 方括号运算符函数（引用返回，可作左值）;下表越界时抛掷异常
	int getsize() const;					// 获取向量的维数（常量成员函数）
	virtual void resize(int size) = 0;					// 调整向量的维数（尽量保留原有的数据）设置成纯虚函数以实现多态性

	virtual void Output(ostream& out) const = 0;// 纯虚函数（常量函数），以便重载的插入运算符享受多态性
	virtual void Input(istream& in) = 0;		// 纯虚函数，以便重载的插入运算符享受多态性
	virtual void push_back(const T& element) = 0; //纯虚函数，尾插
	virtual void insert(int& index, const T& element) = 0; //纯虚函数，插入
	virtual void pop_back() = 0; //纯虚函数，弹出
	virtual void erase(int& index) = 0;//纯虚函数，删除指定位置元素
	virtual void reverse(int& begin, int& end) = 0; //纯虚函数，颠倒指定范围元素
	virtual void clear() = 0;//纯虚函数，清空容器
	virtual bool empty() = 0; //纯虚函数，判断容器是否为空
protected:							// 受保护的（以便派生类的访问属性）
	int num;								// 向量的维数
	T* p;										// 指针（仅sizeof(void*)字节，即4字节），资源在堆空间
};

template <typename T>
VectorBase<T>::VectorBase(int size, const T* x)	// ① 构造函数（含默认的构造函数、转换构造函数）
{
	num = (size > 0) ? size : 0;
	p = NULL;
	if (num > 0)
	{
		p = new T[num];
		for (int i = 0; i < num; i++)
			p[i] = (x == NULL) ? 0 : x[i];
	}
}

template <typename T>
VectorBase<T>::VectorBase(const VectorBase<T>& v)	// ② 拷贝构造函数（实现深拷贝构造）
{
	num = 0;
	p = NULL;
	*this = v;
}

template <typename T>
VectorBase<T>::~VectorBase()						// ③ 析构函数（虚函数）
{
	num = 0;
	if (p != NULL) delete[] p;
}

template <typename T>
VectorBase<T>& VectorBase<T>::operator=(const VectorBase<T>& v)// ④ 赋值运算符函数（实现深赋值运算）
{
	if (num != v.num)
	{
		if (p != NULL) delete[] p;
		p = new T[num = v.num];
	}
	for (int i = 0; i < num; i++)
		p[i] = v.p[i];
	return *this;
}

template <typename T>
T& VectorBase<T>::operator[](int index) const throw(int)// 方括号运算符函数（引用返回，可作左值）
{
	if (p == NULL)
		throw 0;							// 新添加的异常
	if (index < 0 || index >= num)
		throw - 1;
	return p[index];
}

template <typename T>
int VectorBase<T>::getsize() const				// 获取向量的维数（常量成员函数）
{
	return num;
}

template <typename T>
ostream& operator<<(ostream& out, const VectorBase<T>& v)	// 不必是友元函数
{
	v.Output(out);
	return out;
}

template <typename T>
istream& operator>>(istream& in, VectorBase<T>& v)			// 不必是友元函数
{
	v.Input(in);
	return in;
}

#endif