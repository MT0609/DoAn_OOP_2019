#include"MyString.h"

void main()
{
	MyString str;
	str.Nhap();
	cout << str << endl;
	cout << "Do dai chuoi: " << str.getLength() << endl;
	cout << "Ki tu o chi so thu 2: " << str.getChar(2) << endl;

	char x; int i;
	cout << "Nhap 1 ki tu moi muon gan vao chuoi va chi so muon gan: ";
	fflush(stdin);
	cin >> x;
	cin >> i;
	str.GanKiTu(x, i);
	cout << str << endl;
	cout << "Ket qua dao chuoi "; str.DaoChuoi().Xuat();

	MyString str2;
	str2.Nhap();
	cout << str2 << endl;

	cout << "Ket qua noi 2 chuoi va chuan hoa: ";
	(str + str2).ChuanHoa().Xuat();

	if (str > str2)
		cout << "Chuoi 1 lon hon chuoi 2" << endl;
	else
		cout << "Chuoi 1 nho hon chuoi 2" << endl;

	if (str == str2)
		cout << "Chuoi 1 bang chuoi 2" << endl;
	else
		cout << "Chuoi 1 khong bang chuoi 2" << endl;
	system("pause");
}