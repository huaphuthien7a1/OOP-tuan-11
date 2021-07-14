
#include"DTXS.h"

class GV :public DTXS {
private:
	int sobb;
public:
	GV(string = "", string = "", string = "", int = 0);
	int GetSoBB();
	void SetSoBB(int);
	void Nhap();
	void Xuat();
	long TinhTienThuong();
	double GetDRL();
	double GetDTB();
	int GetSoSK();
	void SetDRL(double);
	void SetDTB(double);
	void SetSoSK(int);

};
