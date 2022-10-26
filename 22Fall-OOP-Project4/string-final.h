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

	void Output(ostream& out) const;
	void Input(istream& in);
	void resize(int size);
	//friend istream& getline(istream& in, String& Str, int n, char delim = '\n');

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
	String mid(int pos, int n) const;
	String& insert(int p0, const char* s);			
	int find(const String& Str) const;				
	const char* c_str();							
	void swap(String& Str);
	//char & operator[](int index) throw(int);		
};

#endif //STRING_FINAL_H