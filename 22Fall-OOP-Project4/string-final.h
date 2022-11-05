#pragma once
#ifndef STRING_FINAL_H
#define STRING_FINAL_H
#define _CRT_SECURE_NO_WARNINGS
#include "vec-base.h"
#include <cstring>
using namespace std;

class String : public VectorBase<char>
{
public:
	String(const char* str = "");
	int length() const;

	friend String operator+(const String& s1, const String& s2);
	String& operator+=(const String& s);
	friend bool operator< (const String& s1, const String& s2);
	friend bool operator<=(const String& s1, const String& s2);
	friend bool operator> (const String& s1, const String& s2);
	friend bool operator>=(const String& s1, const String& s2);
	friend bool operator==(const String& s1, const String& s2);
	friend bool operator!=(const String& s1, const String& s2);

	int stoi() throw(int);                     
	int stoi(int pos, int n);
	friend String itos(int n);
	String mid(int pos, int n) const;				//��ȡ�Ӵ�,��posλ�ÿ�ʼ��ȡn����
	String& insert(int p0, const char* s);			//ƴ���ַ���
	int find(const String& str) const;				//�����Ӵ�
	const char* c_str();							
	void swap(String& str);
	void Input(istream& in);
	void Output(ostream& out) const;
	void resize(int size);
	void push_back(const char& element);			//β��
	void insert(int& index, const char& element);	//����
	void pop_back();								//����βԪ��
	void erase(int& index);							//ɾ��ָ��λ��Ԫ��
	void reverse(int& begin, int& end);				//�ߵ�ָ����ΧԪ��
	bool empty();
	void clear();
};

#endif //STRING_FINAL_H