#include"DTSV.h"

class SVLT :public DTSV {
private:
	int sbv;
public:
	SVLT(string = "", string = "", string = "", double = 0, int = 0);
	int GetSoBV();
	void SetSoBV(int);
	void Nhap();
	void Xuat();
	long TinhTienHocBong();
	double GetDRL();
	void SetDRL(double);

};