#include "DocGia.h"



DocGia::DocGia()
{
}


DocGia::~DocGia()
{
}

string DocGia::get_Ma()
{
	return Ma;
}

string DocGia::get_Ten()
{
	string Ten = "";
	int i = HoTen.length() - 1;
	while (i >= 0 && HoTen[i] != ' ')
		--i;
	for (int idx = i + 1; idx < HoTen.length(); ++idx)
		Ten.push_back(HoTen[idx]);
	return Ten;
}

void DocGia::set_Ma(string ma)
{
	Ma = ma;
}

void DocGia::set_Ten(string ten)
{
	HoTen = ten;
}

void DocGia::set_PhieuMuon(string masach, int songaymuon)
{
	phieu_muon[masach] = songaymuon;
}

void DocGia::Nhap()
{
	cout << "Nhap ma doc gia: ";
	cin.ignore();
	getline(cin, Ma);
	cout << "Nhap Ho ten doc gia: ";
	getline(cin, HoTen);

	int option;
	while (1)
	{
		cout << "Tiep tuc nhap sach muon? (1 / other): ";
		cin >> option;
		if (option != 1)
			break;
		string ma_sach;
		cout << "Nhap ma sach muon: ";
		getline(cin, ma_sach);
		Date date;
		cout << "Nhap ngay muon (dd): ";
		cin >> date.Ngay;
		cout << "Nhap thang muon (mm): ";
		cin >> date.Thang;
		cout << "Nhap nam muon (yyyy): ";
		cin >> date.Nam;

		phieu_muon[ma_sach] = date.Ngay * 1000000 + date.Thang * 10000 + date.Nam; // dang ddmmyyyy
	}
}

void DocGia::Xuat()
{
	cout << "Ma Doc gia: " << Ma << endl;
	cout << "Ho ten Doc gia: " << HoTen << endl;
	cout << "Thong tin sach muon: " << endl;
	for (auto pair : phieu_muon)
		cout << "Ma sach: " << pair.first << ":\tMuon " << get_songayMuon(pair.second) << " ngay" << endl;
}

void DocGia::XuatFile(ofstream & out)
{
	out << Ma << endl;
	out << HoTen << endl;
	out << phieu_muon.size() << endl;
	for (auto pair : phieu_muon)
	{
		out << pair.first << endl;
		out << pair.second << endl;
	}
}

void DocGia::Sua()
{
	int key;
	cout << "Ban muon sua ma doc gia? ";
	cin >> key;
	if (key == 1)
	{
		cout << "Nhap Ma moi: ";
		cin >> Ma;
	}
	cout << "Ban muon sua ten doc gia? ";
	cin >> key;
	if (key == 2)
	{
		cout << "Nhap ho ten moi: ";
		cin >> HoTen;
	}
}

int DocGia::get_songayMuon(int thoigianMuon)
{
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);

	// lay ra ngay thang nam muon tu thoi giam muon dang ddmmyyyy
	int dayMuon = thoigianMuon;
	int ngayMuon = dayMuon / 1000000;
	int thangMuon = (dayMuon / 10000) % 100;
	int namMuon = dayMuon % 10000;

	int day1 = 365 * namMuon + namMuon / 4 - namMuon / 100 + namMuon / 400 + (153 * thangMuon + 8) / 5 + ngayMuon - 306;
	int day2 = 365 * (local.tm_year + 1900) + (local.tm_year + 1900) / 4 - (local.tm_year + 1900) / 100 + (local.tm_year + 1900) / 400 + (153 * local.tm_mon + 153 + 8) / 5 + local.tm_mday + 1 - 306;
	return day2 - day1;
}
