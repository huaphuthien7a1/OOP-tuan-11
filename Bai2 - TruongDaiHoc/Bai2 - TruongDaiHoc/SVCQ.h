#include"DTSV.h"

class SVCQ :public DTSV {
private:
	double drl;
public:
	SVCQ(string = "", string = "", string = "", double = 0, double = 0);
	double GetDRL();
	void SetDRL(double);
	void Nhap();
	void Xuat();
	long TinhTienHocBong();
	int GetSoBV();
	void SetSoBV(int);

};