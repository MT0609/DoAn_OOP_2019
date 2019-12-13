#include "Sach.h"



Sach::Sach()
{
}


Sach::~Sach()
{
}

void Sach::Nhap()
{
	cout << "Nhap ma sach: ";
	cin.ignore();
	getline(cin, Ma);
	cout << "Nhap ten sach: ";
	cin.ignore();
	getline(cin, Ten);
	cout << "Nhap tac gia: ";
	cin.ignore();
	getline(cin, TacGia);
	cout << "Nhap Nha xuat ban: ";
	cin.ignore();
	getline(cin, NXB);
	cout << "Nhap gia sach: ";
	cin >> Gia;
}

void Sach::Xuat()
{
	cout << "Ma sach: " << Ma << endl;
	cout << "Ten sach: " << Ten << endl;
	cout << "Tac gia: " << TacGia << endl;
	cout << "Nha xuat ban: " << NXB << endl;
	cout << "Gia sach: " << Gia << endl;
}

string Sach::get_Ma()
{
	return Ma;
}

string Sach::get_Ten()
{
	string Ten = "";
	int i = Ten.length() - 1;
	while (i >= 0 && Ten[i] != ' ')
		--i;
	for (int idx = i + 1; idx < Ten.length(); ++idx)
		Ten.push_back(Ten[idx]);
	return Ten;
}

string Sach::get_NXB()
{
	return NXB;
}

string Sach::get_TacGia()
{
	return TacGia;
}

void Sach::set_Ma(string ma)
{
	Ma = ma;
}

void Sach::set_Ten(string ten)
{
	Ten = ten;
}

void Sach::set_NXB(string nxb)
{
	NXB = nxb;
}

void Sach::set_TacGia(string tacgia)
{
	TacGia = tacgia;
}

void Sach::Sua()
{
	int key;
	cout << "Ban muon sua ma sach khong? ";
	cin >> key;
	if (key == 1)
	{
		cout << "Nhap ma sach muon sua";
		getline(cin, Ma);
	}
	cout << "Ban muon sua ten sach khong? ";
	cin >> key;
	if (key == 1)
	{
		cout << "Nhap ten sach muon sua";
		getline(cin, Ten);
	}
	cout << "Ban muon sua nha xuat ban khong? ";
	cin >> key;
	if (key == 1)
	{
		cout << "Nhap ten nha xuat ban moi: ";
		getline(cin, NXB);
	}
	cout << "Ban muon ten tac gia khong? ";
	cin >> key;
	if (key == 1)
	{
		cout << "Nhap ma sach muon sua";
		getline(cin, TacGia);
	}
}

void Sach::XuatFile(ofstream & out)
{
	out << Ma << endl;
	out << Ten << endl;
	out << TacGia << endl;
	out << NXB << endl;
	out << Gia << endl;
}

