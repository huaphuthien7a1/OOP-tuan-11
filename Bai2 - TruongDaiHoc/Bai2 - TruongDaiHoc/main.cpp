#include<fstream>
#include"TRUONGDH.h"
#include<iomanip>
int main() {
	fstream file;
	file.open("Text.txt");
	TRUONGDH t;

	file.close();
	int button = -1;
	while (button != 0)
	{
		cout << "                                    ========MENU========" << endl;
		cout << setiosflags(ios::left) << setw(50) << "0 - Ket thuc chuong trinh.";
		cout << setiosflags(ios::left) << setw(50) << "6 - TKiem tra co SVLT co DTB tren 9 va khong nghi buoi nao" << endl;
		cout << setiosflags(ios::left) << setw(50) << "1 - Nhap";
		cout << setiosflags(ios::left) << setw(50) << "7 - Tim SVCQ co DTB cao nhat" << endl;
		cout << setiosflags(ios::left) << setw(50) << "2 - Xuat";
		cout << setiosflags(ios::left) << setw(50) << "8 - Sap xep danh sach tang dan theo ma so" << endl;
		cout << setiosflags(ios::left) << setw(50) << "3 - Liet ke SVCQ co DRL la 100";
		cout << setiosflags(ios::left) << setw(50) << "9 - Them 1 SV moi " << endl;
		cout << setiosflags(ios::left) << setw(50) << "4 - Dem so luong SVLT khong nghi buoi nao";
		cout << setiosflags(ios::left) << setw(50) << "10 - Xoa 1 SV co ma so do nguoi dung nhap vao" << endl;
		cout << setiosflags(ios::left) << setw(50) << "5 - Tinh tong hoc bong";
		cout << setiosflags(ios::left) << setw(50) << "11 - Tim kiem sinh vien" << endl;
		cout << "**********************************\n";
		cout << "12 - Tao File\n";
		cout << "13 - Doc File\n";
		cout << "14 - Doc File va luu d/s DTXS\n";
		cout << "15 - Luu File d/s DTXS\n";
		if (t.GetSL() == 0) cout << "Ban chua nhap danh sach DTXS\n";
		else {
			cout << "Danh sach sinh vien: \n";
			t.Xuat();
		}
		cout << "Nhap thao tac: ";
		cin >> button;
		switch (button) {
		case 0:
			cout << "Ket thuc chuong trinh.";
			break;
		case 1:
			t.Nhap();
			break;
		case 2:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			t.Xuat();
			break;
		case 3:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			t.LietKeSVCQCoDRLLa100();
			break;
		case 4:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			cout << "So luong SV khong nghi buoi nao: " << t.SoLuongSVLTKhongNghiBuoiNao();
			break;
		case 5:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			cout << "Tong hoc bong la: " << t.TongHocBongCapChoSV();
			break;
		case 6:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			t.KiemTraTruongCoSVLTCoDTBLonHon9VaKhongNghiBuoiNao();
			break;
		case 7:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			t.TimSVCQCoDTBCaoNhat();
			break;
		case 8:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			t.SapXepTangDanTheoMaSo();
			cout << "Danh sach sau khi sap xep tang dan theo ma so.\n";
			t.Xuat();
			break;
		case 9:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			t.Them1SVMoi();
			break;
		case 10:
		{
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			string ms;
			t.XoaSVCoMaSoNguoiDungNhapVao(ms);
			cout << "Danh sach sinh vien sau khi xoa\n";
			t.Xuat();
			break;
		}
		case 11:
		{
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach sinh vien \n";
				t.Nhap();
			}
			cout << "Nhap phuong thuoc tim kiem(1: MaSo, 2: HoTen, 3: Khoa, 4: DTB, 5: HocBong): ";
			int l;
			cin >> l;
			cin.ignore();
			if (l == 1) {
				string ms;
				cout << "Nhap ma so SV muon tim kiem: ";
				getline(cin, ms);
				t.TimKiemSVTheoMaSo(ms);

			}
			else if (l == 2) {
				string ht;
				cout << "Nhap ho ten SV muon tim kiem: ";
				getline(cin, ht);
				t.TimKiemSVTheoHoTen(ht);
			}
			else if (l == 3) {
				string kh;
				cout << "Nhap khoa SV muon tim kiem: ";
				getline(cin, kh);
				t.TimKiemSVTheoKhoa(kh);
			}
			else if (l == 4) {
				double dtb;
				cout << "Nhap dtb SV muon tim kiem: ";
				cin >> dtb;
				t.TimKiemSVTheoDTB(dtb);
			}
			else {
				long hb;
				cout << "Nhap hoc bong SV muon tim kiem: ";
				cin >> hb;
				t.TimKiemSVTheoHocBong(hb);
			}
			break;
		}
		case 12:
		{
			string tenfile;
			cin.ignore();
			cout << "Nhap ten file: ";
			getline(cin, tenfile);
			t.GhiFile(tenfile);
			break;
		}
		case 13:
		{
			string tenfile;
			cin.ignore();
			cout << "Nhap ten file: ";
			getline(cin, tenfile);
			t.DocFile(tenfile);
			break;
		}
		case 14:
		{
			if (t.GetSL() > 0)
			{
				string tenfile;
				cin.ignore();
				cout << "Nhap ten file: ";
				getline(cin, tenfile);
				t.DocFileDTSV(tenfile);

			}
			else cout << "Chua nhap thong tin\n";
			break;
		}
		case 15:
		{

			if (t.GetSL() > 0)
			{
				string tenfile;
				cin.ignore();
				cout << "Nhap ten file: ";
				getline(cin, tenfile);
				t.GhiFileDTSV(tenfile);

			}
			else cout << "Chua nhap thong tin\n";
			break;
		}
		default:
			cout << "Vui long nhap dung thao tac!!!(0->15)";
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	}

	return 0;
}