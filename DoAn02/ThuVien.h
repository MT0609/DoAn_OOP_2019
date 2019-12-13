#pragma once
#include"Sach.h"
#include"SachNgoaiVan.h"
#include"SachTiengViet.h"

class ThuVien
{
public:
	ThuVien();
	~ThuVien();
public:
	void Them(Sach);
	void Xoa(Sach);
	void Tim(Sach);
};

