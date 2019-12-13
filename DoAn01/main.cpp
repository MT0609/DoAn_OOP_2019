#include"MyString.h"

void main()
{
	MyString str;
	cout << "Nhap chuoi thu nhat: ";
	cin >> str;
	cout << str << endl;
	cout << "Do dai chuoi: " << str.length() << endl << endl;

	str.resize(str.length() + 2);
	cout << str.length() << " " << str << endl;
	str.erase(str.length() - 4, 3);
	cout << "erase (pos, len): " << str << endl;

	cout << "str[5] (phuong thuc string[] va string.at()): " << str[5] << "  " << str.at(5) << endl;
	cout << "front: " << str.front() << endl;
	cout << "back: " << str.back() << endl;

	str.pop_back();
	cout << "Chuoi sau khi pop_back: " << str << endl;

	str.push_back('t');
	cout << "Chuoi sau khi push_back: " << str << endl;

	cout << "substring: ";
	str.substr(str.length() - 4, 2).Output();

	MyString str2;
	cout << "Nhap chuoi thu 2: ";
	cin >> str2;
	cout << str2 << endl;

	if (str > str2)
		cout << "chuoi 1 lon hon chuoi 2" << endl;
	else
		cout << "chuoi 1 nho hon chuoi 2" << endl;

	if (str == str2)
		cout << "chuoi 1 bang chuoi 2" << endl;
	else
		cout << "chuoi 1 khong bang chuoi 2" << endl;

	if (str.compare(str2) == 1)
		cout << "chuoi 1 lon hon chuoi 2" << endl;
	else if (str.compare(str2) == -1)
		cout << "chuoi 1 nho hon chuoi 2" << endl;
	else
		cout << "chuoi 1 = chuoi 2" << endl;

	cout << "append: ";
	str.append(str2);
	cout << str << endl;

	cout << "insert (pos = 3): ";
	str.insert(3, str2);
	cout << str << endl;

	str.replace(2, 4, str2);
	cout << endl << "Chuoi 1 thay the: " << str << endl;
	cout << "Chuoi 2: " << str2 << endl;
	cout << str.length() << " " << str2.length() << endl;
	char* buffer;
	str.copy(buffer, 4, 2);
	cout << "copy: " << buffer << endl;

	cout << endl << "Swap chuoi 1 va chuoi 2: " << endl;
	str.swap(str2);
	cout << "Chuoi 1: " << str << endl;
	cout << "Chuoi 2: " << str2 << endl;

	cout << endl << "string.c_str() cho chuoi 1: " << str.data() << endl;
	cout << "string.data() cho chuoi 1: " << str.data() << endl;

	cout << endl << "Iterator: ";
	for (MyString::iterator it = str.begin(); it != str.end(); ++it)
		cout << *it;
	cout << endl;

	MyString a("There are two needles in this haystack with needles.");
	MyString b("needle");

	int found = a.find(b);
	cout << "first 'needle' found at: " << found << '\n';

	found = a.find("haystack");
	cout << "'haystack' also found at: " << found << '\n';
	
	MyString c("aeiou");
	found = c.find_first_of("aeiou");
	while (found != std::string::npos)
	{
		c.replace(found, 1, '!');
		found = c.find_first_of("aeiou", found + 1);
	}

	cout << c << '\n';

	MyString d("The sixth sick sheik's sixth sheep's sick.");
	MyString key("sixth");

	found = d.rfind(key);
	if (found != std::string::npos)
		d.replace(found, key.length(), "seventh");
	cout << d << '\n';

	MyString e("Please, erase trailing white-spaces   ");
	MyString whitespaces(" \t\f\v\r");

	found = e.find_last_not_of(whitespaces);
	if (found != std::string::npos)
		e.erase(found);
	else
		e.clear();            // str is all whitespace

	std::cout << '[' << e << "]\n";

	MyString f;
	cout << endl << "Nhap chuoi test getline: ";
	getline(cin, f);
	cout << "Chuoi vua nhap: " << f << endl;

	const char* cstr = "test string";
	if (memcmp(cstr, f.data(), f.length()) == 0)
		cout << "str and cstr have the same content.\n";
	system("pause");
}