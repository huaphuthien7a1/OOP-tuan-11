#include"DTSV.h"

DTSV::DTSV(string ms, string ht, string kh, double dtb, int l): maso(ms) , hoten(ht),khoa(kh),dtb(dtb),loai(l){}

string DTSV::GetMaSo() {
	return maso;
}
string DTSV::GetHoTen() {
	return hoten;
}
string DTSV::GetKhoa() {
	return khoa;
}
double DTSV::GetDTB() {
	return dtb;
}
int DTSV::GetLoai() {
	return loai;
}

void DTSV::SetHoTen(string ht) {
	hoten = ht;
}
void DTSV::SetKhoa(string kh) {
	khoa = kh;
}
void DTSV::SetDTB(double dtb) {
	this->dtb = dtb;
}
void DTSV::Nhap() {
	cin.ignore();
	cout << "Nhap ma so: ";
	getline(cin, maso);
	cout << "Nhap ho ten: ";
	getline(cin, hoten);
	cout << "Nhap khoa: ";
	getline(cin, khoa);
	do {
		cout << "Nhap DTB: ";
		cin >> dtb;
	} while (dtb < 0 || dtb>10);
}
void DTSV::Xuat() {
	cout << "MS: " << maso << "\tTen: " << hoten << "\tKhoa: " << khoa << "\tLoai: " << (loai == 1 ? "SVCQ" : (loai==2? "SVLT":"Khong xac dinh")) << "\tDTB: " << dtb;
}