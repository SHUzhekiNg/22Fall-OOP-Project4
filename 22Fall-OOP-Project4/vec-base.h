#pragma once
#ifndef VEC_BASE_H
#define VEC_BASE_H
#include <iostream>
using namespace std;

template <typename T> class VectorBase			// ����������ģ�壨���������뽫��Ա������ʵ��ȫд��ͷ�ļ��У�
{
public:
	VectorBase(int size = 0, const T* x = NULL);	// �� ���캯������Ĭ�ϵĹ��캯����ת�����캯����
	VectorBase(const VectorBase& v);				// �� �������캯����ʵ��������죩
	virtual ~VectorBase();						// �� �����������麯����
	VectorBase& operator=(const VectorBase& v);	// �� ��ֵ�����������ʵ���ֵ���㣩
	T& operator[](int index) const throw(int);
	// ��������������������÷��أ�������ֵ��;�±�Խ��ʱ�����쳣
	int getsize() const;					// ��ȡ������ά����������Ա������
	virtual void resize(int size) = 0;					// ����������ά������������ԭ�е����ݣ����óɴ��麯����ʵ�ֶ�̬��

	virtual void Output(ostream& out) const = 0;// ���麯�����������������Ա����صĲ�����������ܶ�̬��
	virtual void Input(istream& in) = 0;		// ���麯�����Ա����صĲ�����������ܶ�̬��
	virtual void push_back(const T& element) = 0; //���麯����β��
	virtual void insert(int& index, const T& element) = 0; //���麯��������
	virtual void pop_back() = 0; //���麯��������
	virtual void erase(int& index) = 0;//���麯����ɾ��ָ��λ��Ԫ��
	virtual void reverse(int& begin, int& end) = 0; //���麯�����ߵ�ָ����ΧԪ��
	virtual void clear() = 0;//���麯�����������
	virtual bool empty() = 0; //���麯�����ж������Ƿ�Ϊ��
protected:							// �ܱ����ģ��Ա�������ķ������ԣ�
	int num;								// ������ά��
	T* p;										// ָ�루��sizeof(void*)�ֽڣ���4�ֽڣ�����Դ�ڶѿռ�
};

template <typename T>
VectorBase<T>::VectorBase(int size, const T* x)	// �� ���캯������Ĭ�ϵĹ��캯����ת�����캯����
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
VectorBase<T>::VectorBase(const VectorBase<T>& v)	// �� �������캯����ʵ��������죩
{
	num = 0;
	p = NULL;
	*this = v;
}

template <typename T>
VectorBase<T>::~VectorBase()						// �� �����������麯����
{
	num = 0;
	if (p != NULL) delete[] p;
}

template <typename T>
VectorBase<T>& VectorBase<T>::operator=(const VectorBase<T>& v)// �� ��ֵ�����������ʵ���ֵ���㣩
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
T& VectorBase<T>::operator[](int index) const throw(int)// ��������������������÷��أ�������ֵ��
{
	if (p == NULL)
		throw 0;							// ����ӵ��쳣
	if (index < 0 || index >= num)
		throw - 1;
	return p[index];
}

template <typename T>
int VectorBase<T>::getsize() const				// ��ȡ������ά����������Ա������
{
	return num;
}

template <typename T>
ostream& operator<<(ostream& out, const VectorBase<T>& v)	// ��������Ԫ����
{
	v.Output(out);
	return out;
}

template <typename T>
istream& operator>>(istream& in, VectorBase<T>& v)			// ��������Ԫ����
{
	v.Input(in);
	return in;
}

#endif