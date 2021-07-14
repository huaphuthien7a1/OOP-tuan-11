
#ifndef _DTXS
#define _DTXS
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class DTXS {
protected:
	string maso, hoten, khoa;
	int loai; // 1: GV, 2: SV, 3: NV
public: 
	DTXS(string = "", string = "", string = "", int = 0);
	string GetMaSo();
	string GetHoTen();
	string GetKhoa();
	int GetLoai();
	void SetHoTen(string);
	void SetKhoa(string);
	//ham ao
	virtual void Nhap();
	virtual void Xuat();
	// ham ao thuan tuy
	virtual long TinhTienThuong()=0;
	virtual int GetSoBB()=0;
	virtual double GetDTB()=0;
	virtual double GetDRL()=0;
	virtual int GetSoSK() = 0;
	virtual void SetSoBB(int)=0;
	virtual void SetDTB(double) = 0;
	virtual void SetDRL(double) = 0;
	virtual void SetSoSK(int) = 0;



};

#endif // !_DTXS
