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
	String mid(int pos, int n) const;				//截取子串,从pos位置开始截取n长度
	String& insert(int p0, const char* s);			//拼接字符串
	int find(const String& str) const;				//查找子串
	const char* c_str();							
	void swap(String& str);
	void Input(istream& in);
	void Output(ostream& out) const;
	void resize(int size);
	void push_back(const char& element);			//尾插
	void insert(int& index, const char& element);	//插入
	void pop_back();								//弹出尾元素
	void erase(int& index);							//删除指定位置元素
	void reverse(int& begin, int& end);				//颠倒指定范围元素
	bool empty();
	void clear();
};

#endif //STRING_FINAL_H