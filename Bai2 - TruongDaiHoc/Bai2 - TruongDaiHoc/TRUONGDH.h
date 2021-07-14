#include"DTSV.h"
#include"fstream"

class TRUONGDH {
private: 
	int sl;
	DTSV** pdtsv;
public:
	TRUONGDH();
	~TRUONGDH();
	int GetSL();
	void Nhap();
	void Xuat();
	string DoiChuoiInHoa(string);
	void LietKeSVCQCoDRLLa100();
	int SoLuongSVLTKhongNghiBuoiNao();
	long TongHocBongCapChoSV();
	void KiemTraTruongCoSVLTCoDTBLonHon9VaKhongNghiBuoiNao();
	void TimSVCQCoDTBCaoNhat();
	void SapXepTangDanTheoMaSo();
	void Them1SVMoi();
	void XoaSVCoMaSoNguoiDungNhapVao(string);
	void TimKiemSVTheoMaSo(string);
	void TimKiemSVTheoHoTen(string);
	void TimKiemSVTheoKhoa(string);
	void TimKiemSVTheoDTB(double);
	void TimKiemSVTheoHocBong(long);
	void GhiFile(string);
	void DocFile(string);
	void DocFileDTSV(string);
	void GhiFileDTSV(string);
};