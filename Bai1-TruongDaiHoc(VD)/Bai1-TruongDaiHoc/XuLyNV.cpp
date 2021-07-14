#include"NV.h"

NV::NV(string ms, string ht, string khoa, int sk) : DTXS(ms, ht, khoa, 3), sosk(sk) {}

int NV::GetSoSK() {
	return sosk;
}
void NV::SetSoSK(int sk) {
	while (sk < 0) {
		cout << "Nhap so sang kien: ";
		cin >> sk;
	}
	sosk = sk;
}
void NV::Nhap() {
	loai = 3;
	DTXS::Nhap();
	do {
		cout << "Nhap so sang kien: ";
		cin >> sosk;
	} while (sosk < 0);
}
void NV::Xuat() {
	DTXS::Xuat();
	cout << "\tSoSK: " << sosk << "\nTien thuong: " << TinhTienThuong() << endl;
}
long NV::TinhTienThuong() {
	long thuong = sosk * 3000000;
	if (sosk >= 3) {
		thuong = thuong * 120 / 10;
	}
	return thuong;
}
int NV::GetSoBB() {
	return -1;
}
double NV::GetDTB() {
	return -1;
}
double NV::GetDRL() {
	return -1;
}
void NV::SetSoBB(int bb) {}
void NV::SetDTB(double tb) {}
void NV::SetDRL(double rl) {}
