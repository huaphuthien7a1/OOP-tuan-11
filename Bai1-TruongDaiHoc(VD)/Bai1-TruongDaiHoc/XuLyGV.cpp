#include"GV.h"

GV::GV(string ms, string ht, string khoa, int bb) : DTXS(ms, ht, khoa, 1), sobb(bb) {}
int GV::GetSoBB() {
	return sobb;
}
void GV::SetSoBB(int bb) {
	while (bb < 0) {
		cout << "Nhap so bai bao:  ";
		cin >> bb;
	}
	sobb;
}

void GV::Nhap() {
	loai = 1;
	DTXS::Nhap();
	do {
		cout << "Nhap so bai bao: ";
		cin >> this->sobb;

	} while (sobb < 0);

}

void GV::Xuat() {
	DTXS::Xuat();
	cout << "\tSoBB: " << sobb << "\tTien thuong: " << TinhTienThuong() << endl;
}
long GV::TinhTienThuong() {
	long thuong, them;
	thuong = sobb * 20000000;
	them = (sobb >= 6 ? 15000000 : (sobb >= 3 ? 10000000 : 0));
	return thuong + them;
}
double GV::GetDTB() {
	return -1;
}
double GV::GetDRL() {
	return -1;
}
int GV::GetSoSK() {
	return -1;
}
void GV::SetDTB(double tb) {}
void GV::SetDRL(double rl) {}
void GV::SetSoSK(int sk) {}
