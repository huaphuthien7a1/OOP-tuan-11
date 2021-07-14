#ifndef _DTSV
#define _DTSV
#include<iostream>
#include<string>

using namespace std;

class DTSV {
protected:
	string maso, hoten, khoa;
	double dtb;
	int loai;
public:
	DTSV(string = "", string = "", string = "", double = 0, int = 0);
	string GetMaSo();
	string GetHoTen();
	string GetKhoa();
	double GetDTB();
	int GetLoai();
	void SetHoTen(string);
	void SetKhoa(string);
	void SetDTB(double);
	virtual void Nhap();
	virtual void Xuat();
	virtual long TinhTienHocBong() = 0;
	virtual double GetDRL() = 0;
	virtual void SetDRL(double) = 0;
	virtual int GetSoBV() = 0;
	virtual void SetSoBV(int) = 0;
};

#endif // !_DTSV

