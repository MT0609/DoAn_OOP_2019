#include "SachTiengViet.h"



SachTiengViet::SachTiengViet()
{
}


SachTiengViet::~SachTiengViet()
{
}

int SachTiengViet::getType()
{
	return 1;
}

void SachTiengViet::Nhap()
{
	Sach::Nhap();
}

void SachTiengViet::Xuat()
{
	Sach::Xuat();
}

void SachTiengViet::Sua()
{
	Sach::Sua();
}

void SachTiengViet::setMaISBN(string isbn)
{
}

void SachTiengViet::set_Gia(float gia)
{
	Gia = gia;
}

void SachTiengViet::XuatFile(ofstream out)
{
	Sach::XuatFile(out);
}
