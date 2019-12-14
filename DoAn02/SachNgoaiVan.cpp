#include "SachNgoaiVan.h"



SachNgoaiVan::SachNgoaiVan()
{
}


SachNgoaiVan::~SachNgoaiVan()
{
}

int SachNgoaiVan::getType()
{
	return 2;
}

void SachNgoaiVan::Nhap()
{
	Sach::Nhap();
	cout << "Nhap ma ISBN: ";
	cin.ignore();
	getline(cin, ISBN);
}

void SachNgoaiVan::Xuat()
{
	Sach::Xuat();
	cout << "ISBN: " << ISBN << endl;
}

void SachNgoaiVan::XuatFile(ofstream& out)
{
	Sach::XuatFile(out);
	out << "Ma ISBN: " << ISBN << endl;
}

void SachNgoaiVan::setMaISBN(string isbn)
{
	ISBN = isbn;
}

void SachNgoaiVan::set_Gia(float gia)
{
	Gia = gia;
}


void SachNgoaiVan::Sua()
{
	Sach::Sua();
	int key;
	cout << "Ban muon sua ma ISBN khong: ";
	cin >> key;
	if (key == 1)
	{
		cout << "Nhap ma ISBN moi: ";
		getline(cin, ISBN);
	}
}

void SachNgoaiVan::xuatFileCauTruc(ofstream & out)
{
	Sach::xuatFileCauTruc(out);
	out << endl << ISBN;
}