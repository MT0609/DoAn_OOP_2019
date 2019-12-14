#include "MyString.h"
#include<stdio.h>

MyString::MyString()
{
	len = 0;
	a = NULL;
}

MyString::MyString(const char * str)
{
	if (str == NULL)
	{
		this->len = 0;
		this->a = NULL;
	}

	if (a != NULL)
		delete[] a;
	a = new char[strlen(str)];
	this->len = strlen(str);
	int idx = 0;
	while (str[idx])
	{
		this->a[idx] = str[idx];
		idx++;
	}
	this->a[idx] = '\0';
}

MyString::MyString(const MyString & str)
{
	this->len = str.len;
	this->a = new char[len];
	for (int i = 0; i < this->len; ++i)
		a[i] = str.a[i];
	a[len] = '\0';
}


MyString::~MyString()
{
}

MyString & MyString::operator=(const MyString & str)
{
	if (this->a == str.a)
		return *this;
	a = NULL;
	len = 0;
	for (int i = 0; i < str.len; ++i)
		this->push_back(str.a[i]);
	return *this;
}


void MyString::Input()
{
	/*cout << "Nhap do dai chuoi: ";
	cin >> len;
	cin.ignore();
	a = new char[len + 1];
	cin.getline(a, len + 1);*/
	char key;
	int value;
	while (1)
	{
		key = _getch();
		value = key;
		if (value == 13)
			break;
		cout << key;
		++len;
		a = (char*)realloc(a, len * sizeof(char));
		a[len - 1] = key;
	} 
	a[len] = '\0';
	cout << endl;
}

void MyString::Output()
{
	if (a == NULL)
	{
		cout << "Chuoi rong" << endl;
		return;
	}
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

MyString MyString::resize(int len)
{
	if (len < this->len)
	{
		a = (char*)realloc(a, len * sizeof(char));
		a[len] = '\0';
		this->len = this->length();
	}
	else if (len > this->len)
	{
		int idx = this->len;
		a = (char*)realloc(a, len * sizeof(char));
		for (int i = idx; i < len; ++i)
			this->push_back(' ');
		a[len] = '\0';
	}
	return *this;
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
		return a[this->len - 1];
}

char MyString::front()
{
	if (a != NULL)
		return a[0];
}

MyString MyString::replace(int pos, int len, const MyString & str)
{
	if (pos + len > this->len)
		len = this->len - pos;
	erase(pos, len);
	insert(pos, str);
	return *this;
}

MyString MyString::replace(int pos, int len, const char * s)
{
	if (pos + len > this->len)
		len = this->len - pos;
	erase(pos, len);
	MyString str(s);
	insert(pos, str);
	return *this;
}

MyString MyString::insert(int pos, char c)
{
	if (pos >= 0 && pos < this->len)
	{
		this->a = (char*)realloc(this->a, ++this->len * sizeof(char));
		int n = this->len;
		for (int i = n - 1; i > pos; --i)
			a[i] = a[i - 1];
		a[pos] = c;
		a[len] = '\0';
	}
	return *this;
}

MyString MyString::insert(int pos, const MyString & str)
{
	if (pos >= 0 || pos < this->len)
	{
		for (int i = 0; i < str.len; ++i)
		{
			this->insert(pos, str.a[i]);
			pos++;
		}
	}
	return *this;
}

MyString MyString::erase(int pos, int len)
{
	if (pos >= 0 && pos < this->length())
	{
		int time = 0;
		while (time < len && a[pos] != NULL)
		{
			erase(pos);
			time++;
		}
	}
	a[this->len] = '\0';
	return *this;
}

MyString MyString::erase(int pos)
{
	if (pos >= 0 || pos < this->len)
	{
		for (int i = pos; i < len - 1; ++i)
			a[i] = a[i + 1];
		--len;
		a[len] = '\0';
	}
	return *this;
}

char MyString::getChar(int i)
{
	if (i >= 0 && i < len)
		return a[i];
}

void MyString::assign(char x, int i)
{
	if (i < 0 || i >= this->len)
		return;
	a[i] = x;
}


void MyString::pop_back()
{
	if (this->len > 1)
	{
		a = (char*)realloc(a, --len * sizeof(char));
		a[this->len] = '\0';
	}
}

MyString MyString::append(MyString str)
{
	for (int i = 0; i < str.len; ++i)
		this->push_back(str.a[i]);
	return *this;
}

MyString & MyString::replace(size_t pos, size_t len, char c)
{
	if (pos + len > this->len)
		len = this->len - pos;
	erase(pos, len);
	insert(pos, c);
	return *this;
}

void MyString::swap(MyString & str)
{
	MyString newthis(str);
	MyString newstr(*this);

	this->len = newthis.len;
	this->a = (char*)realloc(a, len * sizeof(char));
	for (int i = 0; i < this->len; ++i)
		a[i] = newthis.a[i];
	a[len] = '\0';

	str.len = newstr.len;
	str.a = (char*)realloc(str.a, str.len * sizeof(char));
	for (int i = 0; i < str.len; ++i)
		str.a[i] = newstr.a[i];
	str.a[str.len] = '\0';

	/*if (len > str.len)
	{
		int t = str.len;
		str.a = (char*)realloc(str.a, len * sizeof(char));
		for (int i = 0; i < len; ++i)
		{
			char temp = a[i];
			a[i] = str.a[i];
			str.a[i] = temp;
		}
		str.a[this->len] = '\0';
		a[t] = '\0';
	}
	else if (len < str.len)
	{
		a = (char*)realloc(a, str.len * sizeof(char));
		for (int i = 0; i < str.len; ++i)
		{
			char temp = a[i];
			a[i] = str.a[i];
			str.a[i] = temp;
		}
		a[str.len] = '\0';
		str.a[this->len] = '\0';
	}*/
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

MyString & MyString::operator+=(const char * s)
{
	this->a = (char*)realloc(this->a, (this->len + strlen(s)) * sizeof(char));
	for (int i = len, idx = 0; i < len; ++i, ++idx)
		a[i] = s[idx];
	this->len += strlen(s);
	this->a[len] = '\0';
	return *this;
}

MyString & MyString::operator+=(char c)
{
	a = (char*)realloc(a, ++len * sizeof(char));
	a[this->len - 1] = c;
	a[this->len] = '\0';
	return *this;
}

void MyString::push_back(char c)
{
	a = (char*)realloc(a, ++len * sizeof(char));
	a[this->len - 1] = c;
	a[this->len] = '\0';
}

//MyString MyString::ChuanHoa()
//{
//	while (a[0] == ' ') this->erase(0);
//	while (a[len - 1] == ' ' && len >= 0) this->erase(len - 1);
//	for (int i = 0; i < len - 1; ++i)
//	{
//		while (a[i] == ' ' && a[i + 1] == ' ')
//			this->erase(i);
//	}
//	return *this;
//}

//MyString MyString::DaoChuoi()
//{
//	for (int i = 0; i < len / 2; ++i)
//		swap(this->a[i], a[len - i - 1]);
//	return *this;
//}

bool MyString::operator>(const MyString & str)
{
	int new_len;
	if (len > str.len) new_len = str.len;
	else new_len = len;
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
	int new_len;
	if (len > str.len) new_len = str.len;
	else new_len = len;
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
	int new_len;
	if (len > str.len) new_len = str.len;
	else new_len = len;
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
	int new_len;
	if (len > str.len) new_len = str.len;
	else new_len = len;
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
	int new_len;
	if (len > str.len) new_len = str.len;
	else new_len = len;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] > str.a[i]) return 1;
		if (a[i] < str.a[i]) return -1;
	}
	if (len > str.len) return 1;
	else if (len < str.len) return -1;
	else return 0;
}


const char * MyString::c_str() const
{
	return const_cast<const char*>(a);
}

const char * MyString::data() const
{
	char* a = &this->a[0];
	return a;
}

int MyString::copy(char*& s, int len, int pos)
{
	if (pos + len > this->len)
		len = this->len - pos;
	s = new char[len];
	for (int i = pos, idx = 0; i < pos + len; ++i, ++idx)
	{
		s[idx] = this->a[i];
	}
	s[len] = '\0';
	return len;
}

int MyString::find(char c, int pos)
{
	if (pos < 0 || pos >= len)
		return MyString::npos;
	for (int i = pos; i < len; ++i)
		if (a[i] == c)
			return i;
	return npos;
}

int MyString::find(const MyString & str, int pos) const
{
	if (pos < 0 || pos >= len || str.len > this->len)
		return MyString::npos;
	for (int i = pos; i <= len - str.len; ++i)
	{
		int flag = 1;
		for (int j = i, idx = 0; idx < str.len; ++j, ++idx)
		{
			if (a[j] != str.a[idx])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}

int MyString::find(const char * s, size_t pos) const
{
	int s_len = strlen(s);
	if (pos < 0 || pos >= len || s_len > this->len)
		return MyString::npos;
	for (int i = pos; i <= len - s_len; ++i)
	{
		int flag = 1;
		for (int j = i, idx = 0; idx < s_len; ++j, ++idx)
		{
			if (a[j] != s[idx])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}

size_t MyString::rfind(const MyString & str, size_t pos) const
{
	if (str.len > this->len)
		return npos;
	for (int i = len - 1; i >= str.len - 1; --i)
	{
		int flag = 1;
		for (int j = i, idx = str.len - 1; idx >= 0; --j, --idx)
		{
			if (a[j] != str.a[idx])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i - str.len + 1;
	}
	return npos;
}

size_t MyString::find_first_of(char c, size_t pos) const
{
	if (pos < 0 || pos >= len)
		return MyString::npos;
	for (int i = pos; i < len; ++i)
		if (a[i] == c)
			return i;
	return npos;
}

size_t MyString::find_first_of(const MyString & str, size_t pos) const
{
	if (pos < 0 || pos >= len || str.len > this->len)
		return MyString::npos;
	for (int i = pos; i < len; ++i)
	{
		for (int j = 0; j < str.len; ++j)
		{
			if (a[i] == a[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_first_of(const char * s, size_t pos) const
{
	int s_len = strlen(s);
	if (pos < 0 || pos >= len || s_len > this->len)
		return MyString::npos;
	for (int i = pos; i < len; ++i)
	{
		for (int j = 0; j < s_len; ++j)
		{
			if (a[i] == s[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_last_of(char c, size_t pos) const
{
	if (pos < 0 || pos >= len)
		return MyString::npos;
	for (int i = len - 1; i >= 0; --i)
		if (a[i] == c)
			return i;
	return npos;
}

size_t MyString::find_last_of(const MyString & str, size_t pos) const
{
	if (pos < 0 || pos >= len || str.len > this->len)
		return MyString::npos;
	for (int i = len; i >= 0; --i)
	{
		for (int j = 0; j < str.len; ++j)
		{
			if (a[i] == a[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_last_of(const char * s, size_t pos) const
{
	int s_len = strlen(s);
	if (pos < 0 || pos >= len)
		return MyString::npos;
	for (int i = len - 1; i >= 0; --i)
	{
		for (int j = 0; j < s_len; ++j)
		{
			if (a[i] == s[j])
				return i;
		}
	}
	return npos;
}

size_t MyString::find_first_not_of(char c, size_t pos) const
{
	for (int i = pos; i < len; ++i)
		if (a[i] != c)
			return i;
	return npos;
}

size_t MyString::find_first_not_of(const MyString & str, size_t pos) const
{
	for (int i = pos; i < len; ++i)
	{
		int flag = 1;
		for (int j = 0; j < str.len; ++j)
		{
			if (a[i] == a[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}

size_t MyString::find_first_not_of(const char * s, size_t pos) const
{
	int s_len = strlen(s);
	for (int i = pos; i < len; ++i)
	{
		int flag = 1;
		for (int j = 0; j < s_len; ++j)
		{
			if (a[i] == a[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}

size_t MyString::find_last_not_of(char c, size_t pos) const
{
	for (int i = len - 1; i >= 0; --i)
		if (a[i] != c)
			return i;
	return npos;
}

size_t MyString::find_last_not_of(const MyString & str, size_t pos) const
{
	for (int i = len - 1; i >= 0; --i)
	{
		int flag = 1;
		for (int j = 0; j < str.len; ++j)
		{
			if (a[i] == a[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}

size_t MyString::find_last_not_of(const char * s, size_t pos) const
{
	int s_len = strlen(s);
	for (int i = len - 1; i >= 0; --i)
	{
		int flag = 1;
		for (int j = 0; j < s_len; ++j)
		{
			if (a[i] == a[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}

MyString MyString::substr(size_t pos, size_t len) const
{
	if (pos >= 0 && pos < this->len)
	{
		MyString str;
		if (len == npos || pos + len > this->len)
			len = this->len - pos;
		for (int i = pos; i < pos + len; ++i)
			str.push_back(this->a[i]);
		return str;
	}
	return *this;
}


void swap(MyString & x, MyString & y)
{
	MyString new_x(y);
	MyString new_y(x);

	x.len = new_x.len;
	x.a = (char*)realloc(x.a, x.len * sizeof(char));
	for (int i = 0; i < x.len; ++i)
		x.a[i] = new_x.a[i];
	x.a[x.len] = '\0';

	y.len = new_y.len;
	y.a = (char*)realloc(y.a, y.len * sizeof(char));
	for (int i = 0; i < y.len; ++i)
		y.a[i] = new_y.a[i];
	y.a[y.len] = '\0';
}

istream & operator>>(istream & is, MyString & str)
{
	/*cout << "Nhap do dai cua chuoi: ";
	is >> str.len;
	str.a = new char[str.len];
	fflush(stdin);
	is.getline(str.a, str.len);
	return is;*/

	/*char key;
	int value;
	while (1)
	{
		key = _getch();
		value = key;
		if (value == 13)
			break;
		cout << key;
		++str.len;
		str.a = (char*)realloc(str.a, str.len * sizeof(char));
		str.a[str.len - 1] = key;
	}
	str.a[str.len] = '\0';
	cout << endl;
	return is;*/
	char* input = new char[100];
	is.getline(input, 100);

	int i = 0;
	while (input[i] != '\0')
	{
		i++;
	}
	str.len = i;
	delete[] str.a;
	str.a = new char[i];
	for (int j = 0; j < i; j++)
	{
		str.a[j] = input[j];
	}
	str.a[i] = '\0';
	delete[] input;
	return is;
}

ostream & operator<<(ostream & os, MyString & str)
{
	for (int i = 0; i < str.len; ++i)
		os << str.a[i];
	return os;
}

istream & getline(istream & is, MyString & str)
{
	char *c = new char[100];
	is.get(c, 100);
	int i = 0;
	while (c[i] != '\n' && i < strlen(c))
	{
		str += c[i];
		++i;
	}
	str.a[str.len] = '\0';
	delete[]c;
	return is;
}

istream & getline(istream & is, MyString & str, char delim)
{
	char *c = new char[100];
	is.get(c, 100, delim);
	int i = 0;
	while (c[i] != delim && i < strlen(c))
	{
		str += c[i];
		++i;
	}
	str.a[str.len] = '\0';
	delete[]c;
	return is;
}
