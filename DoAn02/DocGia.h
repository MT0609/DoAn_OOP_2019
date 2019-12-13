#pragma once
#include"Sach.h"
#include<unordered_map>
#include<time.h>

struct Date
{
	int Ngay;
	int Thang;
	int Nam;
};

class DocGia
{
	string Ma;
	string HoTen;
public:
	unordered_map <string, int> phieu_muon;				//int: ngay muon dang ddmmyyyy
public:
	DocGia();
	~DocGia();
public:	
	string get_Ma();
	string get_Ten();
	void set_Ma(string);
	void set_Ten(string);
	void set_PhieuMuon(string masach, int songaymuon);
	void Nhap();
	void Xuat();
	void Sua();
	void XuatFile(ofstream &out);
	int get_songayMuon(int ngaymuon); // so voi thoi gian he thong
};

