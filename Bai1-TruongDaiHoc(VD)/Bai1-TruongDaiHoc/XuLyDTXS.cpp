#include"DTXS.h"
DTXS::DTXS(string ms, string ht, string khoa, int l): maso(ms), hoten(ht),khoa(khoa),loai(l){}
string DTXS::GetMaSo() {
	return maso;
}
string DTXS::GetHoTen() {
	return hoten;
}
string DTXS::GetKhoa() {
	return khoa;
}
int DTXS::GetLoai() {
	return loai;
}
void DTXS::SetHoTen(string ht) {
	hoten = ht;
}
void DTXS::SetKhoa(string kh) {
	khoa = kh;
}
void DTXS::Nhap() {
	cin.ignore();
	cout << "Nhap ma so: ";
	getline(cin, maso);
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap khoa: ";
	getline(cin, khoa);

}
void DTXS::Xuat() {
	cout << "MS: " << maso << "\tTen: " << hoten << "\tKhoa: " << khoa << "\tLoai: " <<(loai == 1 ? "GV" : (loai == 2 ? "SV" : (loai == 3 ? "NV" : "???")));
}
