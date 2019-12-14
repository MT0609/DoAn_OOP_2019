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

	ofstream out;
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
	cout << "10 - Xem danh sach cac loai sach, doc gia" << endl;
	cout << "11 - Xuat thong tin sach, doc gia ra file" << endl;

	string id;
	int flag;
	do
	{	
		cout << endl << "\tChon option: ";
		cin >> option; 
		switch (option)
		{
		case 1:
			lib.ThemSach();
			cout << endl;
			break;
		case 2:
			cout << endl << "Nhap ma sach can xoa: ";
			cin >> id;
			lib.XoaSach(id);
			cout << endl;
			break;
		case 3:
			cout << endl << "Nhap ma sach can sua: ";
			cin >> id;
			lib.SuaSach(id);
			cout << endl;
			break;
		case 4:
			cout << endl << "Nhap ma sach can tim: ";
			cin >> id;
			lib.TimSach(id);
			break;
		case 5:
			lib.ThemDocGia();
			cout << endl;
			break;
		case 6:
			cout << endl << "Nhap ma doc gia can xoa khoi danh sach: ";
			cin >> id;
			lib.XoaDocGia(id);
			cout << endl;
			break;
		case 7:
			cout << endl << "Nhap ma doc gia can sua thong tin: ";
			cin >> id;
			lib.SuaDocGia(id);
			cout << endl;
			break;
		case 8:
			cout << endl << "Nhap ma doc gia can tim: ";
			cin >> id;
			lib.TimDocGia(id);
			cout << endl;
			break;
		case 9:
			lib.list_MuonQuaHan();
			cout << endl;
			break;
		case 10:
			lib.XuatDocGia();
			cout << endl;
			lib.XuatSach();
			cout << endl;
			break;
		case 11:
			cout << endl << "Nhap duong dan file xuat: ";
			cin >> str;
			out.open(str);
			lib.XuatFile(out);
			out.close();
			break;
		default:
			goto Menu;
		}

		cout << "Tiep tuc thao tac? (1 / other): ";
		cin >> flag;
	} while (flag == 1);

	system("pause");
}