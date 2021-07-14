
#ifndef _SV
#define _SV
#include"DTXS.h"
class SV : public DTXS {
private:
	double dtb, drl;
public:
	SV(string = "", string = "", string = "", double = 0, double = 0);
	double GetDTB();
	double GetDRL();
	void SetDTB(double);
	void SetDRL(double);
	void Nhap();
	void Xuat();
	long TinhTienThuong();
	int GetSoBB();
	int GetSoSK();
	void SetSoBB(int);
	void SetSoSK(int);
	

};

#endif // !_SV
