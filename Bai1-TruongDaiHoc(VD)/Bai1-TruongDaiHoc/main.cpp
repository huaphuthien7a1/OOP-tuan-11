#include"TRUONGDH.h"
#include <fstream>
int main() {
	ifstream file("Input.txt");
	TRUONGDH t;
	
	
	
	int button = -1;
	while (button != 0)
	{
		cout << "                                    ========MENU========" << endl;
		cout << setiosflags(ios::left) << setw(50) << "0 - Ket thuc chuong trinh.";
		cout << setiosflags(ios::left) << setw(50) << "8 - Tim nhan vien co sang kien nhieu nhat" << endl;
		cout << setiosflags(ios::left) << setw(50) << "1 - Nhap";
		cout << setiosflags(ios::left) << setw(50) << "9 - Sap xep tang dan theo ma so" << endl;
		cout << setiosflags(ios::left) << setw(50) << "2 - Xuat";
		cout << setiosflags(ios::left) << setw(50) << "10 - Sap xep giam dan theo tien thuong" << endl;
		cout << setiosflags(ios::left) << setw(50) << "3 - Liet ke GV co 5 bai bao cao tro len";
		cout << setiosflags(ios::left) << setw(50) << "11 - Them 1 DTXS moi" << endl;
		cout << setiosflags(ios::left) << setw(50) << "4 - Dem so luong SV co DRL to da";
		cout << setiosflags(ios::left) << setw(50) << "12 - Xoa 1 DTXS co ma nhap vao" << endl;
		cout << setiosflags(ios::left) << setw(50) << "5 - Tong tien cap cua NV co 3 SK tro len";
		cout << setiosflags(ios::left) << setw(50) << "13 - Tim kiem DTXS" << endl;
		cout << setiosflags(ios::left) << setw(50) << "6 - Tinh DTB cua sv co DRL duoi 50";
		cout << setiosflags(ios::left) << setw(50) << "14 - Cap nhat DTXS theo thong tin nhap vao" << endl;
		cout << setiosflags(ios::left) << setw(50) << "7 - Kiem tra truong co giao vien chua co bai bao khoa hoc";
		cout << setiosflags(ios::left) << setw(50) << "\t15 - Xoa toan bo danh sach"<<endl;
		cout << "**********************************\n";
		cout << "16 - Tao File\n";
		cout << "17 - Doc File\n";
		cout << "18 - Doc File va luu d/s DTXS\n";
		cout << "19 - Luu File d/s DTXS\n";


		if (t.GetSL() == 0) cout << "Ban chua nhap danh sach DTXS\n";
		else {
			cout << "Danh sach DTXS: \n";
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
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			t.Xuat();
			break;
		case 3:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			t.LietKeGVCoTu5BaiBao();
			break;
		case 4:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			cout << "So luong sinh vien co diem ren luyen toi da la: " << t.DemSVCoDRLToiDa();
			break;
		case 5:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			cout << "Tong tien cap cua NV co 3 SKKN tro len la: " << t.TinhTongTienThuongNVCo3SKKNTroLen();
			break;
		case 6:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			cout << "Diem trung binh cua sinh vien co diem ren luyen duoi 50: " << t.TinhDTBCuaSVCoDRLDuoi50();
			break;
		case 7:
		{
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			int kt = t.KiemTraGVChuaCoBaiBao();
			if (kt == 1) cout << "Danh sach DTXS khong co GV";
			else if (kt == 2) cout << "Ton tai GV chua co bai bao cao";
			else cout << "Tat ca giao vien deu co bai bao cao";
			break;
		}
		case 8:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			t.TimNVCoSKKNNhieuNhat();
			break;
		case 9:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			t.SapXepMaSoTangDan();
			cout << "Danh sach DTXS sau khi sap xep tang dan theo ma so\n";
			t.Xuat();
			break;
		case 10:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			t.SapXepGiamDanTheoTienThuong();
			cout << "Danh sach DTXS sau khi sap xep giam dan theo tien thuong\n";
			t.Xuat();
			break;
		case 11:
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			t.ThemDTXS();
			break;
		case 12:
		{
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			string ms;
			cin.ignore();
			cout << "Nhap ma so DTXS can xoa: ";
			getline(cin, ms);
			t.XoaDTXS(ms);
			break;
		}
		case 13:
		{
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			int l;
			do {
				cout << "Ban muon tiem kiem theo(1: MaSo, 2: HoTen, 3: Khoa, 4:TienThuong): ";
				cin >> l;
			} while (l < 1 || l > 4);
			cin.ignore();
			if (l == 1) {
				string ms;
				cout << "Nhap ma so muon tien kiem: ";
				getline(cin, ms);
				t.TimDTXSTheoMaSo(ms);
			}
			else if (l == 2) {
				string ht;
				cout << "Nhap ho ten muon tim kiem: ";
				getline(cin, ht);
				t.TimDTXSTheoHoTen(ht);
			}
			else if (l == 3) {
				string kh;
				cout << "Nhap khoa muon tim kiem: ";
				getline(cin, kh);
				t.TimDTXSTheoTungKhoa(kh);
			}
			else {
				long tt;
				cout << "Nhap tien thuong muon tim kiem: ";
				cin >> tt;
				t.TimDTXSTheoTienThuong(tt);
			}

			break;
		}
		case 14:
		{
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			string ms;
			cin.ignore();
			cout << "Nhap ma so DTXS: ";
			getline(cin, ms);
			t.CapNhatThongTinTheoMaSo(ms);
			break;
		}
		case 15:
		{
			if (t.GetSL() == 0)
			{
				cout << "Ban chua nhap danh sach DTXS \n";
				t.Nhap();
			}
			t.XoaToanBo();
			cout << "Da xoa toan bo danh sach";
			break;
		}
		case 16:
		{
			string tenfile;
			cin.ignore();
			cout << "Nhap ten file: ";
			getline(cin, tenfile);
			t.GhiFile(tenfile);
			break;
		}
		case 17:
		{
			string tenfile;
			cin.ignore();
			cout << "Nhap ten file: ";
			getline(cin, tenfile);
			t.DocFile(tenfile);
			break;
		}
		case 18:
		{
			if (t.GetSL() > 0)
			{
				string tenfile;
				cin.ignore();
				cout << "Nhap ten file: ";
				getline(cin, tenfile);
				t.DocFileDTXS(tenfile);

			}
			else cout << "Chua nhap thong tin\n";
			break;
		}
		case 19: 
		{

			if (t.GetSL() > 0)
			{
				string tenfile;
				cin.ignore();
				cout << "Nhap ten file: ";
				getline(cin, tenfile);
				t.GhiFileDTXS(tenfile);

			}
			else cout << "Chua nhap thong tin\n";
			break;
		}
		default:
			cout << "Vui long nhap dung thao tac!!!(0->19)";
			break;
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	ofstream file1("Output.txt");
	
	file1.close();
	return 0;
}