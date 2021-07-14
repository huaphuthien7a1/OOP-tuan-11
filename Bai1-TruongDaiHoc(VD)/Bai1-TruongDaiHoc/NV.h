
#ifndef _NV
#define _NV
#include"DTXS.h"
class NV : public DTXS {
private:
	int sosk;
public:
	NV(string = "", string = "", string = "", int = 0);
	int GetSoSK();
	void SetSoSK(int);
	void Nhap();
	void Xuat();
	long TinhTienThuong();
	int GetSoBB();
	void SetSoBB(int);
	double GetDTB();
	double GetDRL();
	void SetDTB(double);
	void SetDRL(double);


};


#endif // !_NV
