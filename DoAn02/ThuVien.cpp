#include "ThuVien.h"

ThuVien::ThuVien()
{
}


ThuVien::~ThuVien()
{
}

void ThuVien::NhapSach(ifstream & in)
{
	Sach* sach;
	int giaSach;
	while (!in.eof())
	{
		int loai;
		in >> loai;
		if (loai == 1) 
			sach = new SachTiengViet;
		else
			sach = new SachNgoaiVan;

		string str; 
		in.get();
		getline(in, str);
		sach->set_Ma(str);

		getline(in, str);
		sach->set_Ten(str);

		getline(in, str);
		sach->set_TacGia(str);

		getline(in, str);
		sach->set_NXB(str);

		if (loai == 2)
		{
			getline(in, str);
			sach->setMaISBN(str);
		}

		in >> giaSach;
		sach->set_Gia(giaSach);

		books.push_back(sach);
	}
}

void ThuVien::ThemSach()
{
	char flag;
	int count = 0;		
	Sach* sach;

	do
	{
		cout << "Nhap thong tin sach muon them: " << endl;
		cout << "Sach tieng viet (1) / sach ngoai van (2): ";
		cin >> flag;
		if (flag == '1')
			sach = new SachTiengViet;
		else
			sach = new SachNgoaiVan;
		sach->Nhap();
		books.push_back(sach);

		cout << "Nhap tiep thong tin sach (1 - tiep tuc): ";
		cin >> flag;
	} while (flag == '1');
}

void ThuVien::XoaSach(int pos)
{
	if (pos < 0 || pos >= books.size())
		return;		
	for (int i = pos; i < books.size() - 1; ++i)
		books[i] = books[i + 1];
	books.resize(books.size() - 1);
}

void ThuVien::XoaSach(string Ma)
{
	bool flag = 0;
	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i]->get_Ma().compare(Ma) == 0)
		{
			flag = 1;
			XoaSach(i);
		}
	}
	if (flag == 0)
		cout << "Khong tim thay sach can xoa!" << endl;
}

void ThuVien::SuaSach(string Ma)
{
	bool flag = 0;
	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i]->get_Ma().compare(Ma) == 0)
		{		
			flag = 1;
			books[i]->Sua();
		}
	}
	if (flag == 0)
		cout << "Khong tim thay sach can sua!" << endl;
}

void ThuVien::TimSach(string Ma)
{
	char flag = 0;
	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i]->get_Ma().compare(Ma) == 0)
		{		
			flag = 1;
			books[i]->Xuat(); 
			cout << endl;
		}
	}
	if (flag == 0)
		cout << "Khong tim thay sach!" << endl;
}

void ThuVien::XuatSach()
{
	if (books.size() == 0)
	{
		cout << "danh sach rong! ";
		return;
	}
	for (int i = 0; i < books.size(); ++i)
	{
		books[i]->Xuat();
		cout << endl;
	}
}

void ThuVien::NhapDocGia(ifstream & in)
{
	DocGia reader;
	while (!in.eof())
	{
		reader.phieu_muon.clear();
		string str;
		getline(in, str);
		reader.set_Ma(str);

		getline(in, str);
		reader.set_Ten(str);

		int sl_sachMuon;
		in >> sl_sachMuon;
		for (int j = 0; j < sl_sachMuon; ++j)
		{
			int ngayMuon;
			in >> ngayMuon;
			in.get();
			getline(in, str);	// ma sach muon	
			reader.phieu_muon[str] = ngayMuon;
		}
		readers.push_back(reader);
	}
}

void ThuVien::ThemDocGia()
{
	char flag;
	int count = 0;
	do
	{
		cout << "Nhap thong tin doc gia muon them: " << endl;
		DocGia dg;
		dg.Nhap();
		readers.push_back(dg);

		cout << "Nhap tiep (1 - tiep tuc): ";
		cin >> flag;
	} while (flag == '1');
}

void ThuVien::TimDocGia(string Ma)
{
	bool flag = 0;
	for (int i = 0; i < readers.size(); ++i)
	{
		if (readers[i].get_Ma().compare(Ma) == 0)
		{
			flag = 1;
			readers[i].Xuat();
			cout << endl;
		}
	}
	if (flag == 0)
		cout << "Khong tim thay doc gia!" << endl;
}

void ThuVien::XoaDocGia(int pos)
{
	if (pos < 0 || pos >= readers.size())
		return;
	for (int i = pos; i < readers.size() - 1; ++i)
		readers[i] = readers[i + 1];
	readers.resize(readers.size() - 1);
}

void ThuVien::XoaDocGia(string Ma_DG)
{
	bool flag = 0;
	for (int i = 0; i < readers.size(); ++i)
	{
		if (readers[i].get_Ma().compare(Ma_DG) == 0)
		{
			flag = 1;
			XoaDocGia(i);
		}
	}
	if (flag == 0)
		cout << "Khong tim thay doc gia can xoa!" << endl;
}

void ThuVien::SuaDocGia(string Ma_DG)
{
	bool flag = 0;
	for (int i = 0; i < readers.size(); ++i)
	{
		if (readers[i].get_Ma().compare(Ma_DG) == 0)
		{
			flag = 1;
			readers[i].Sua();
		}
	}
	if (flag == 0)
		cout << "Khong tim thay doc gia can sua!" << endl;
}

void ThuVien::XuatDocGia()
{
	if (readers.size() == 0)
	{
		cout << "danh sach rong! ";
		return;
	}
	for (int i = 0; i < readers.size(); ++i)
	{
		cout << endl << "Thong tin doc gia thu " << i + 1 << endl;
		readers[i].Xuat();
		cout << endl;
	}
}

void ThuVien::list_MuonQuaHan()
{
	bool flag = 0;
	for (int i = 0; i < readers.size(); ++i)
	{	
		int sum = 0;
		for (int j = 0; j < books.size(); ++j)
		{
			unordered_map<string, int>::const_iterator got = readers[i].phieu_muon.find(books[j]->get_Ma());
			if (got != readers[i].phieu_muon.end() && readers[i].get_songayMuon(readers[i].phieu_muon[books[j]->get_Ma()]) > 7)
			{
				if (books[i]->getType() == 1)															// sach tieng Viet
					sum += 10000 * readers[i].get_songayMuon(readers[i].phieu_muon[books[j]->get_Ma()]);
				else																					// type = 2 // sach ngoai van
					sum += 20000 * readers[i].get_songayMuon(readers[i].phieu_muon[books[j]->get_Ma()]);
			}
		}
		if (sum != 0)
		{
			flag = 1;
			readers[i].Xuat();
			cout << " So tien phat: " << sum << endl;
		}
	}
	if (flag == 0)
		cout << "Khong co doc gia nao dang muon sach qua han" << endl;
}

void ThuVien::XuatFile(ofstream & out)
{
	out << "\tThong tin sach: " << endl;
	for (int i = 0; i < books.size(); ++i)
	{
		out << "Thong tin cuon sach thu " << i + 1 << endl;
		books[i]->XuatFile(out);
		out << endl;
	}
	out << endl;
	out << "\tThong tin doc gia: " << endl;
	for (int i = 0; i < readers.size(); ++i)
	{
		out << "Thong tin doc gia thu " << i + 1 << endl;
		readers[i].XuatFile(out);
		out << endl;
	}
}

void ThuVien::XuatFileSach(ofstream & out)
{
	out << books.size() << endl;
	for (int i = 0; i < books.size(); ++i)
	{
		if (books[i]->getType() == 1)
			out << 1 << endl;
		else
			out << 2 << endl;
		books[i]->XuatFile(out);
	}
}

void ThuVien::XuatFileDocGia(ofstream & out)
{
	out << readers.size() << endl;
	for (int i = 0; i < readers.size(); ++i)
		readers[i].XuatFile(out);
}
