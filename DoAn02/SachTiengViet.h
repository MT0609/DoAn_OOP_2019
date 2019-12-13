#pragma once
#include"Sach.h"

class SachTiengViet: public Sach
{
public:
	SachTiengViet();
	~SachTiengViet();
public:
	int getType();
	void Nhap();
	void Xuat();
	void Sua();
	void setMaISBN(string isbn);
	void XuatFile(ofstream out);
};

