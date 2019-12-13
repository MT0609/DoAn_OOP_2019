#pragma once
#include"Sach.h"

class SachNgoaiVan: public Sach
{
	string ISBN;
public:
	SachNgoaiVan();
	~SachNgoaiVan();
public:
	int getType();
	void Nhap();
	void Xuat();	
	void XuatFile(ofstream& out);
	void setMaISBN(string isbn);
	void Sua();
};

