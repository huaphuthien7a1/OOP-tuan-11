#include"SVCQ.h"

SVCQ::SVCQ(string maso, string hoten, string khoa, double dtb, double drl): DTSV(maso,hoten,khoa,dtb,1), drl(drl){}
double SVCQ::GetDRL() {
	return drl;
}
void SVCQ::SetDRL(double rl) {
	drl = rl;
}
void SVCQ::Nhap() {
	DTSV::Nhap();
	do {
		cout << "Nhap DRL: ";
		cin >> drl;
	} while (drl < 0 || drl > 100);
}
void SVCQ::Xuat() {
	DTSV::Xuat();
	cout << "\tDRL: " << drl << "\tHoc bong: " << TinhTienHocBong() << endl;
}
long SVCQ::TinhTienHocBong() {
	long thuong = 0;
	if (drl >= 85) {
		if (dtb >= 9.5) thuong = 1500000;
		else if (dtb >= 8.5) thuong = 1200000;
		else if (dtb >= 7.5) thuong = 1000000;
	}
	return thuong;
}
int SVCQ::GetSoBV() {
	return -1;
}
void SVCQ::SetSoBV(int){}
