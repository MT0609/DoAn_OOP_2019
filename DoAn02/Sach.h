#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<fstream>

class Sach
{
protected:
	string Ma;
	string Ten;
	string TacGia;
	string NXB;
	float Gia;
public:
	Sach();
	~Sach();
public:
	virtual int getType() = 0;
	virtual void Nhap();
	virtual void Xuat();
	string get_Ma();
	string get_Ten();
	string get_NXB();
	string get_TacGia();
	void set_Ma(string Ma);
	void set_Ten(string Ten);
	void set_NXB(string NXB);
	void set_TacGia(string tacgia);
	virtual void setMaISBN(string isbn) = 0;
	virtual void set_Gia(float gia) = 0;
	virtual void Sua();
	virtual void XuatFile(ofstream & out);
};

