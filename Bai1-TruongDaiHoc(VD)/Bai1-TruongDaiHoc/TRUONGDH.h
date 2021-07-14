
#ifndef _TRUONGDH
#define _TRUONGDH
#include"DTXS.h"
#include"fstream"
class TRUONGDH {
private:
	DTXS** pdtxs;
	int sl;
public:
	TRUONGDH();
	~TRUONGDH();
	int GetSL();
	
	void Nhap();
	void Xuat();
	void LietKeGVCoTu5BaiBao();
	int DemSVCoDRLToiDa();
	long TinhTongTienThuongNVCo3SKKNTroLen();
	double TinhDTBCuaSVCoDRLDuoi50();
	int KiemTraGVChuaCoBaiBao();
	void TimNVCoSKKNNhieuNhat();
	string DoiChuoiInHoa(string);
	string DoiChuoiInThuong(string);
	void SapXepMaSoTangDan();
	void SapXepGiamDanTheoTienThuong();
	void TimDTXSTheoTungKhoa(string);
	void TimDTXSTheoMaSo(string);
	void TimDTXSTheoHoTen(string);
	void TimDTXSTheoTienThuong(long);
	void CapNhatThongTinTheoMaSo(string);
	void ThemDTXS();
	void XoaDTXS(string);
	void XoaToanBo();
	void GhiFile(string);
	void DocFile(string);
	void DocFileDTXS(string);
	void GhiFileDTXS(string);

};



#endif
