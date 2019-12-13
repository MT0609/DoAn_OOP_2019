#include"ThuVien.h"

void main()
{
	ThuVien lib;

	ifstream in;
	string str;
	cout << "Nhap duong dan file cau truc luu tru thong tin sach: ";
	cin >> str;
	in.open(str);
	lib.NhapSach(in);
	cout << endl;
	in.close();

	cout << "Nhap duong dan file cau truc luu tru thong tin doc gia: ";
	cin >> str;
	in.open(str);
	lib.NhapDocGia(in);
	in.close();
	cout << endl << endl;


	int option;
Menu:
	cout << "1 - Them Sach" << endl;
	cout << "2 - Xoa Sach khoi danh sach" << endl;
	cout << "3 - Sua thong tin sach" << endl;
	cout << "4 - Tim Sach" << endl;
	cout << "5 - Them Doc gia" << endl;
	cout << "6 - Xoa Doc gia khoi danh sach" << endl;
	cout << "7 - Sua thong tin doc gia" << endl;
	cout << "8 - Tim Doc gia" << endl;
	cout << "9 - Liet ke danh sach doc gia muon sach qua han" << endl;
	cout << "10 - Xuat thong tin sach, doc gia ra file" << endl;

	string s;
	int flag;
	do
	{	
		cout << endl << "\tChon option: ";
		cin >> option; 
		switch (option)
		{
		case 1:
			lib.ThemSach();
			break;
		case 2:
			cout << endl << "Nhap ma sach can xoa: ";
			cin >> s;
			lib.XoaSach(s);
			break;
		case 3:
			cout << endl << "Nhap ma sach can sua: ";
			cin >> s;
			lib.SuaSach(s);
			break;
		case 4:
			cout << endl << "Nhap ma sach can tim: ";
			cin >> s;
			lib.TimSach(s);
			break;
		case 5:
			lib.ThemDocGia();
			break;
		case 6:
			cout << endl << "Nhap ma doc gia can xoa khoi danh sach: ";
			cin >> s;
			lib.XoaDocGia(s);
			break;
		case 7:
			cout << endl << "Nhap ma doc gia can sua thong tin: ";
			cin >> s;
			lib.SuaDocGia(s);
			break;
		case 8:
			cout << endl << "Nhap ma doc gia can tim: ";
			cin >> s;
			lib.TimDocGia(s);
			break;
		case 9:
			lib.list_MuonQuaHan();
			break;
		default:
			goto Menu;
		}

		cout << "Tiep tuc thao tac? (1 / other): ";
		cin >> flag;
	} while (flag == 1);

	string path;
	cout << endl << "Nhap duong dan file xuat: ";
	cin >> path;
	ofstream out(path);
	lib.XuatFile(out);

	system("pause");
}