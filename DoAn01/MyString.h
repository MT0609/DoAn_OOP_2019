#pragma once
#include<iostream>
using namespace std;
#include<string.h>
#include<conio.h>

class MyString
{
	int len;		// so luong ki tu cua chuoi
	char *a;
	static const int npos = -1;
public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	~MyString();
	MyString& operator=(const MyString& str);
public:	
		//ITERATORS
	class iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef forward_iterator_tag iterator_category;
		typedef int difference_type;
		iterator(char* ptr) : pointer(ptr) { }
		iterator operator++(int) { iterator i = *this; pointer++; return i; }
		iterator operator++() { pointer++; return *this;}
		reference operator*() { return *pointer; }
		char* operator->() { return pointer; }
		bool operator==(const iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};
	class const_iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef int difference_type;
		typedef forward_iterator_tag iterator_category;
		const_iterator(char* ptr) : pointer(ptr) { }
		const_iterator operator++(int) { const_iterator i = *this; pointer++; return i; }
		const_iterator operator++() { pointer++; return *this; }
		const reference operator*() { return *pointer; }
		const char* operator->() { return pointer; }
		bool operator==(const const_iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const const_iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};
	class reverse_iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef random_access_iterator_tag iterator_category;
		typedef int difference_type;
		reverse_iterator(char* ptr) : pointer(ptr) { }
		reverse_iterator operator--(int) { reverse_iterator i = *this; pointer--; return i; }
		reverse_iterator operator--() { pointer--; return *this; }
		reference operator*() { return *pointer; }
		char* operator->() { return pointer; }
		bool operator==(const reverse_iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const reverse_iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};
	class const_reverse_iterator
	{
	public:
		typedef char value_type;
		typedef char& reference;
		typedef random_access_iterator_tag iterator_category;
		typedef int difference_type;
		const_reverse_iterator(char* ptr) : pointer(ptr) { }
		const_reverse_iterator operator--(int) { const_reverse_iterator i = *this; pointer--; return i; }
		const_reverse_iterator operator--() { pointer--; return *this; }
		reference operator*() { return *pointer; }
		char* operator->() { return pointer; }
		bool operator==(const const_reverse_iterator& rhs) { return pointer == rhs.pointer; }
		bool operator!=(const const_reverse_iterator& rhs) { return pointer != rhs.pointer; }
	private:
		char* pointer;
	};
	iterator begin() { return iterator(a); }
	iterator end() { return iterator(a + len); }
	reverse_iterator rbegin() { return reverse_iterator(a + len - 1); };
	reverse_iterator rend() { return reverse_iterator(a - 1); }
	const_iterator cbegin() const { return const_iterator(a); }
	const_iterator cend() const { return const_iterator(a + len); }
	const_iterator crbegin() const { return const_iterator(a + len - 1); }
	const_iterator crend() const { return const_iterator(a - 1); }

		//CAPACITY
	void clear();
	bool empty();
	int length();
	int size();
	MyString resize(int);
	void Input();
	void Output();

		//ELEMENT ACCESS
	char operator[](int i);
	char at(int i);
	char back();
	char front();

		//MODIFIERS
	MyString operator+=(const MyString& str);
	MyString& operator+= (const char* s);
	MyString& operator+= (char c);

	void push_back(char c);
	MyString append(MyString str);
	MyString& replace(size_t pos, size_t len, char c);
	MyString replace(int pos, int len, const MyString& str);
	MyString replace(int pos, int len, const char* s);
	MyString insert(int pos, char c);
	MyString insert(int pos, const MyString& str);
	void pop_back();
	void swap(MyString & str);
	void assign(char x, int i); // gan ki tu o chi so i = x
	MyString erase(int pos, int len);
	MyString erase(int pos);		// xoa ki tu o chi so pos
	
		// STRING OPERATIONS
	const char* c_str() const;
	const char* data() const;
	int copy(char*& s, int len, int pos = 0);
	int find(char c, int pos = 0);
	int find(const MyString& str, int pos = 0) const;
	int find(const char* s, size_t pos = 0) const;
	size_t rfind(const MyString& str, size_t pos = npos) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;
	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	char compare(const MyString& str);
	MyString substr(size_t pos = 0, size_t len = npos) const;

	
		// NON-MEMBER FUNCTION OVERLOADS
	MyString operator+(const MyString& str);
	bool operator>(const MyString& str);
	bool operator>=(const MyString& str);
	bool operator<(const MyString& str);
	bool operator<=(const MyString& str);
	bool operator==(const MyString& str);
	bool operator!=(const MyString& str);
	friend void swap(MyString& x, MyString& y);
	friend istream& operator>>(istream& is, MyString &str);
	friend ostream& operator<<(ostream& os, MyString & str);
	friend istream& getline(istream& is, MyString &str);
	friend istream& getline(istream& is, MyString& str, char delim);
};