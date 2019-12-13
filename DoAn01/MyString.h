#pragma once
#include<iostream>
using namespace std;
#include<string.h>

class MyString
{
	int len;		// so luong ki tu cua chuoi
	char *a;
public:
	MyString();
	MyString(char* str);
	MyString(const MyString& str);
	~MyString();
public:
	void Nhap();
	void Xuat();
	int length();
	int size();
	void resize(int);
	void clear();
	bool empty();
	MyString erase(int pos, int len);
	void XoaKiTu(int vt);		// xoa ki tu o chi so i
	char getChar(int i);	// lay o chi so thu i
	void GanKiTu(char x, int i); // gan ki tu o chi so i = x
	friend istream& operator>>(istream& is, MyString &str);
	friend ostream& operator<<(ostream& os, MyString &str);
	MyString operator+(const MyString& str);
	MyString operator+=(const MyString& str);
	void push_back(char);
	MyString ChuanHoa();
	MyString DaoChuoi();
	char operator[](int i);
	char at(int i);
	char back();
	char front();
	bool operator>(const MyString& str);
	bool operator>=(const MyString& str);
	bool operator<(const MyString& str);
	bool operator<=(const MyString& str);
	bool operator==(const MyString& str);
	bool operator!=(const MyString& str);
	char compare(const MyString& str);
	void pop_back();
	MyString append(MyString str);
	void swap(MyString str);
	int copy(char* s, int len, int pos = 0);
	MyString substr(int pos, int len);
	MyString replace(int pos, int len, const MyString& str);
	MyString insert(int pos, char c);
	MyString insert(int pos, const MyString& str);
};


