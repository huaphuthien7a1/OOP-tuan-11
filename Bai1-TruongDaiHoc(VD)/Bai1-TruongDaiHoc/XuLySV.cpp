#include"SV.h"
SV::SV(string ms, string ht, string khoa, double tb, double rl) : DTXS(ms, ht, khoa, 2), dtb(tb), drl(rl) {}
double SV::GetDTB() {
	return dtb;
}
double SV::GetDRL() {
	return drl;
}
void SV::SetDTB(double tb) {
	while (tb < 0 || tb > 10) {
		cout << "Nhap diem trung binh: ";
		cin >> tb;
	}
	dtb = tb;
}
void SV::SetDRL(double rl) {
	while (rl < 0 || rl > 100) {
		cout << "Nhap diem ren luyen: ";
		cin >> rl;
	}
	drl = rl;
}

void SV::Nhap() {
	loai = 2;
	DTXS::Nhap();
	do {
		cout << "Nhap diem trung binh: ";
		cin >> this->dtb;
	} while (dtb < 0 || dtb > 100);
	do {
		cout << "Nhap diem ren luyen: ";
		cin >> this->drl;
	} while (drl < 0 || drl > 100);

}
void SV::Xuat() {
	DTXS::Xuat();
	cout << "\tDTB: " << dtb << "\tDRL: " << drl << "\tTien thuong: " << TinhTienThuong() << endl;
}
long SV::TinhTienThuong() {
	long thuong = 0;
	if (drl >= 85) thuong = (dtb > 9 ? 7000000 : (dtb >= 8.5 ? 5000000 : 0));
	return thuong;
}
int SV::GetSoBB() {
	return -1;
}
int SV::GetSoSK() {
	return -1;
}
void SV::SetSoBB(int bb) {}
void SV::SetSoSK(int sk) {}
