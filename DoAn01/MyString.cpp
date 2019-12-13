#include "MyString.h"
#include<stdio.h>

MyString::MyString()
{
	len = 1;
	a = new char[1];
	a[0] = 'a';
}

MyString::MyString(char * str)
{
	if (str == NULL)
	{
		this->len = 0;
		this->a = NULL;
	}
	int idx = 0;
	while (str[idx] != NULL)
	{
		this->a = (char*)realloc(a, (idx + 1) * sizeof(char));
		this->a[idx] = str[idx];
		idx++;
	}
}

MyString::MyString(const MyString & str)
{
	this->len = str.len;
	this->a = (char*)realloc(a, this->len * sizeof(char));
	for (int i = 0; i < this->len; ++i)
		a[i] = str.a[i];
	a[len] = '\0';
}


MyString::~MyString()
{
}

void MyString::Nhap()
{
	cout << "Nhap do dai chuoi: ";
	cin >> len;
	cin.ignore();
	a = new char[len + 1];
	cin.getline(a, len + 1);
}

void MyString::Xuat()
{
	for (int i = 0; i < len; ++i)
		cout << a[i];
	cout << endl;
}

int MyString::length()
{
	int count = 0;
	while (a[count] != NULL)
		count++;
	return count;
}

int MyString::size()
{
	int count = 0;
	while (a[count] != NULL)
		count++;
	return count;
}

void MyString::resize(int len)
{
	if (len < this->length())
	{
		a = (char*)realloc(a, len * sizeof(char));
		a[len] = '\0';
	}
	else if (len > this->length())
	{
		a = (char*)realloc(a, len * sizeof(char));
		for (int i = length(); i < len; ++i)
			a[i] = 0;
		a[len] = '\0';
	}
}

void MyString::clear()
{
	if (a == NULL)
		delete a;
}

bool MyString::empty()
{
	return (a == NULL);
}

MyString MyString::erase(int pos, int len)
{
	if (pos >= 0 && pos < this->length())
	{
		int time = 0;
		while (time < len && a[this->length()] != NULL)
		{
			XoaKiTu(pos);
			time++;
		}
	}
}

void MyString::XoaKiTu(int vt)
{
	if (vt < 0 || vt >= len) return;
	for (int i = vt; i < len - 1; ++i)
		a[i] = a[i + 1];
	--len;
}

char MyString::getChar(int i)
{
	if (i >= 0 && i < len)
		return a[i];
}

void MyString::GanKiTu(char x, int i)
{
	if (i < 0 || i >= this->len)
		return;
	a[i] = x;
}

istream & operator>>(istream & is, MyString & str)
{
	cout << "Nhap do dai cua chuoi: ";
	is >> str.len;
	str.a = new char[str.len];
	fflush(stdin);
	is.getline(str.a, str.len);
	return is;
}

ostream & operator<<(ostream & os, MyString & str)
{
	for (int i = 0; i < str.len; ++i)
		os << str.a[i];
	return os;
}

MyString MyString::operator+(const MyString & str)
{
	MyString kq;
	kq.len = len + str.len;
	kq.a = new char[kq.len];
	for (int i = 0; i < len; ++i)
		kq.a[i] = a[i];
	for (int i = len, idx = 0; i < kq.len; ++i, ++idx)
		kq.a[i] = str.a[idx];
	kq.a[kq.len] = '\0';
	return kq;
}

MyString MyString::operator+=(const MyString & str)
{
	this->a = (char*)realloc(this->a, (this->len + str.len) * sizeof(char));
	for (int i = len, idx = 0; i < len; ++i, ++idx)
		a[i] = str.a[idx];
	this->len += str.len;
	this->a[len] = '\0';
	return *this;
}

void MyString::push_back(char x)
{
	a = (char*)realloc(a, ++len * sizeof(char));
	a[this->len - 1] = x;
	a[this->len] = '\0';
}

MyString MyString::ChuanHoa()
{
	while (a[0] == ' ') this->XoaKiTu(0);
	while (a[len - 1] == ' ' && len >= 0) this->XoaKiTu(len - 1);
	for (int i = 0; i < len - 1; ++i)
	{
		while (a[i] == ' ' && a[i + 1] == ' ')
			this->XoaKiTu(i);
	}
	return *this;
}

MyString MyString::DaoChuoi()
{
	for (int i = 0; i < len / 2; ++i)
		swap(a[i], a[len - i - 1]);
	return *this;
}

char MyString::operator[](int i)
{
	if (i >= 0 && i < this->length())
		return a[i];
}

char MyString::at(int i)
{
	if (i >= 0 && i < this->length())
		return a[i];
}

char MyString::back()
{
	if (a != NULL)
		return a[this->length() - 1];
}

char MyString::front()
{
	if (a != NULL)
		return a[0];
}

bool MyString::operator>(const MyString & str)
{
	int len;
	if (len > str.len) len = str.len;
	else len = len;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] > str.a[i]) return true;
		if (a[i] < str.a[i]) return false;
	}
	if (len > str.len) return true;
	return false;
}

bool MyString::operator>=(const MyString & str)
{
	int len;
	if (len > str.len) len = str.len;
	else len = len;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] > str.a[i]) return true;
		if (a[i] < str.a[i]) return false;
	}
	if (len >= str.len) return true;
	return false;
}

bool MyString::operator<(const MyString & str)
{
	int len;
	if (len > str.len) len = str.len;
	else len = len;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] < str.a[i]) return true;
		if (a[i] > str.a[i]) return false;
	}
	if (len <= str.len) return true;
	return false;
}

bool MyString::operator<=(const MyString & str)
{
	int len;
	if (len > str.len) len = str.len;
	else len = len;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] < str.a[i]) return true;
		if (a[i] > str.a[i]) return false;
	}
	if (len < str.len) return true;
	return false;
}

bool MyString::operator==(const MyString & str)
{
	if (len != str.len)
		return false;
	for (int i = 0; i < len; ++i)
		if (a[i] != str.a[i]) return false;
	return true;
}

bool MyString::operator!=(const MyString & str)
{
	if (len != str.len)
		return false;
	for (int i = 0; i < len; ++i)
		if (a[i] == str.a[i]) return false;
	return true;
}

char MyString::compare(const MyString & str)
{
	int len;
	if (len > str.len) len = str.len;
	else len = len;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] > str.a[i]) return 1;
		if (a[i] < str.a[i]) return -1;
	}
	if (len > str.len) return 1;
	else if (len < str.len) return -1;
	else return 0;
}

void MyString::pop_back()
{
	a = (char*)realloc(a, --len * sizeof(char));
	a[this->length()] = '\0';
}

MyString MyString::append(MyString str)
{
	this->a = (char*)malloc((this->len + str.len) * sizeof(char));
	for (int i = len, j = 0; j < str.len; ++i, ++j)
		this->a[i] = str.a[j];
	this->a[this->len] = '\0';
	return *this;
}

void MyString::swap(MyString str)
{
	int len;
	if (len > str.len)
		len = len;
	else
		len = str.len;
	this->a = (char*)realloc(a, len * sizeof(char));
	str.a = (char*)realloc(str.a, len * sizeof(char));
	for (int i = 0; i < len; ++i)
	{
		char temp = a[i];
		a[i] = str.a[i];
		str.a[i] = temp;
	}
}

int MyString::copy(char* s, int len, int pos = 0)
{
	if (pos + len > this->length())
		len = this->length() - pos;
	s = new char[len];
	for (int i = pos; i < pos + len; ++i)
		s[i] = this->a[i];
	return len;
}

MyString MyString::substr(int pos, int len)
{
	MyString str;
	if (pos + len > this->len)
		len = this->length() - pos;
	str.a = new char[len];
	str.len = len;
	for (int i = pos; i < pos + len; ++i)
		str.a[i] = this->a[i];
	str.a[str.len] = '\0';
	return str;
}

MyString MyString::replace(int pos, int len, const MyString & str)
{
	if (pos >= 0 && pos < this->len)
	{
		 
	}
}

MyString MyString::insert(int pos, char c)
{
	if (pos >= 0 && pos < this->len)
	{
		this->a = (char*)realloc(this->a, ++this->len * sizeof(char));
		for (int i = len - 1; i >= pos; ++i)
			a[i] = a[i - 1];
		a[pos] = c;
		a[len] = '\0';
	}
	return *this;
}

MyString MyString::insert(int pos, const MyString & str)
{
	this->a = (char*)realloc(this->a, (this->len + str.len) * sizeof(char));
	this->len += str.len;
	for (int i = 0; i < str.len; ++i)
	{
		this->insert(pos, str.a[i]);
		pos++;
	}
	return *this;
}
