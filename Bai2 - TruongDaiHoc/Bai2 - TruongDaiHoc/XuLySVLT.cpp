#include"SVLT.h"
SVLT::SVLT(string ms, string ht, string kh, double dtb, int bv) : DTSV(ms,ht,kh,dtb,2), sbv(bv){}
int SVLT::GetSoBV() {
	return sbv;
}
void SVLT::SetSoBV(int bv){ 
	sbv = bv;
}
void SVLT::Nhap() {
	DTSV::Nhap();
	do {
		cout << "Nhap so boi vang: ";
		cin >> sbv;
	} while (sbv < 0);
}
void SVLT::Xuat() {
	DTSV::Xuat();
	cout << "\tSBV: " << sbv << "\tHoc bong: " << TinhTienHocBong() << endl;
}
long SVLT::TinhTienHocBong() {
	long thuong = 0;
	if (sbv <= 3) {
		if (dtb >= 9) thuong = 1500000;
		else if (dtb >= 8) thuong = 1200000;
		else if (dtb >= 7) thuong = 1000000;
	}
	return thuong;
}
double SVLT::GetDRL() {
	return -1;
}
void SVLT::SetDRL(double drl) {}