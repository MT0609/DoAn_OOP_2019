#pragma once
#include"Sach.h"
#include"SachNgoaiVan.h"
#include"SachTiengViet.h"
#include"DocGia.h"
#include<vector>

class ThuVien
{
	vector<Sach*> books;
	vector<char> book_type;
	vector<DocGia> readers;
public:
	ThuVien();	
	~ThuVien();
public:
	void NhapSach(ifstream & in);
	void ThemSach();
	void XoaSach(int pos);
	void XoaSach(string Ma);
	void SuaSach(string Ma);
	void TimSach(string Ma);
	void XuatSach();


	void NhapDocGia(ifstream & in);
	void ThemDocGia();
	void TimDocGia(string Ma);
	void XoaDocGia(int pos);
	void XoaDocGia(string Ma_DG);
	void SuaDocGia(string Ma_DG);
	void XuatDocGia();
	void list_MuonQuaHan();

	// Lưu trữ thông tin sách, độc giả, phiếu mượn trả xuống tập tin
	void XuatFile(ofstream & out);

	// Lưu File có cấu trúc cho việc load dữ liệu sau này
	void XuatFileSach(ofstream &out);
	void XuatFileDocGia(ofstream &out);
};

