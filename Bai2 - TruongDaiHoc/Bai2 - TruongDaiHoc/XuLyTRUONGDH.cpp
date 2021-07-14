#include"TRUONGDH.h"
#include"SVLT.h"
#include"SVCQ.h"
TRUONGDH::TRUONGDH() {
	pdtsv = NULL;
	sl = 0;
}
TRUONGDH::~TRUONGDH() {
	if (sl > 0) {
		for (int i = 0; i < sl; i++)
			delete[]pdtsv[i];
		delete[]pdtsv;
		pdtsv = NULL;
		sl = 0;
	}
}
int TRUONGDH::GetSL() {
	return sl;
}
void TRUONGDH::Nhap() {
	int l;
	do {
		cout << "Nhap so luong DTXS: ";
		cin >> sl;
	} while (sl < 1);
	pdtsv = new DTSV * [sl];
	for (int i = 0; i < sl; i++) {
		cout << "-------------------------------\n";
		cout << "Nhap thong tin DTXS thu: " << i + 1 << ":\n";
		do {
			cout << "Nhap loai (1: SVCQ, 2: SVLT): ";
			cin >> l;
		} while (l < 1 || l > 2);
		if (l == 1) pdtsv[i] = new SVCQ;
		else pdtsv[i] = new SVLT;
		
		pdtsv[i]->Nhap();

	}
}
void TRUONGDH::Xuat() {
	for (int i = 0; i < sl; i++) {
		pdtsv[i]->Xuat();
	}
}
void TRUONGDH::LietKeSVCQCoDRLLa100() {
	int dem = 0;
	for(int i=0;i<sl;i++) 
		if (pdtsv[i]->GetLoai() == 1 && pdtsv[i]->GetDRL() == 100) {
			dem++;
			pdtsv[i]->Xuat();
		}
	if (dem == 0) cout << "Khong co SVCQ nao co DRL la 100";
}
string TRUONGDH::DoiChuoiInHoa(string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}
int TRUONGDH::SoLuongSVLTKhongNghiBuoiNao() {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pdtsv[i]->GetLoai() == 2 && pdtsv[i]->GetSoBV() == 0) {
			dem++;
		
		}
	return dem;
}
long TRUONGDH::TongHocBongCapChoSV() {
	long hocbong = 0;
	for (int i = 0; i < sl; i++)
		hocbong += pdtsv[i]->TinhTienHocBong();
	return hocbong;
}
void TRUONGDH::KiemTraTruongCoSVLTCoDTBLonHon9VaKhongNghiBuoiNao() {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pdtsv[i]->GetLoai() == 2 && pdtsv[i]->GetDTB() >= 9 && pdtsv[i]->GetSoBV() == 0) {
			dem++;
			pdtsv[i]->Xuat();
		}
	if (dem == 0) cout << "Khong co SVLT co DTB tu 9 tro len va khong nghi buoi nao";
}
void TRUONGDH::TimSVCQCoDTBCaoNhat() {
	int dtbmax = -1, vt = -1;
	for (int i = 0; i < sl; i++)
		if (pdtsv[i]->GetLoai() == 1)
		{
			vt = i;
			dtbmax = pdtsv[i]->GetDTB();
			break;
		}
	if (vt != -1)
	{
		for (int i = vt + 1; i < sl; i++)
			if (pdtsv[i]->GetLoai() == 3 && pdtsv[i]->GetDTB() > dtbmax)
				dtbmax = pdtsv[i]->GetDTB();
		for (int i = 0; i < sl; i++)
			if (pdtsv[i]->GetLoai() == 3 && pdtsv[i]->GetDTB() == dtbmax)
				pdtsv[i]->Xuat();
	}
	else cout << "Truong khong co SVCQ";
}
void TRUONGDH::SapXepTangDanTheoMaSo() {
	for (int i = 0; i < sl; i++)
		for (int j = i + 1; j < sl; j++)
			if (DoiChuoiInHoa(pdtsv[i]->GetMaSo()) > DoiChuoiInHoa(pdtsv[j]->GetMaSo()))
			{
				DTSV* ptam = pdtsv[i];
				pdtsv[i] = pdtsv[j];
				pdtsv[j] = ptam;
			}
}
void TRUONGDH::Them1SVMoi() {
	DTSV* newEle;
	int l;
	cout << "Nhap thong tin DTXS muon them\n";
	do {
		cout << "Nhap loai (1: SVCQ, 2: SVLT): ";
		cin >> l;
	} while (l < 1 || l > 2);
	if (l == 1) newEle = new SVCQ;
	else newEle = new SVLT;
	newEle->Nhap();
	DTSV** temp = new DTSV * [sl + 1];
	for (int i = 0; i < sl; i++) temp[i] = pdtsv[i];
	//for (int i = 0; i < sl; i++) delete[]pdtxs[i];
	//delete[]pdtxs;
	pdtsv = temp;
	pdtsv[sl++] = newEle;
	Xuat();
}
void TRUONGDH::XoaSVCoMaSoNguoiDungNhapVao(string ms) {
	cin.ignore();
	int j = 0;
	cout << "Nhap ma so cua DTXS can xoa: ";
	getline(cin, ms);
	DTSV** temp = new DTSV * [sl - 1];
	for (int i = 0; i < sl; i++) {
		if (DoiChuoiInHoa(pdtsv[i]->GetMaSo()) == DoiChuoiInHoa(ms)) i++;
		temp[j++] = pdtsv[i];
	}
	pdtsv = temp;
	sl--;
	Xuat();
}
void TRUONGDH::TimKiemSVTheoMaSo(string ms) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (DoiChuoiInHoa(pdtsv[i]->GetKhoa()) == DoiChuoiInHoa(ms))
		{
			pdtsv[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co SV co ma so " << ms << endl;
}
void TRUONGDH::TimKiemSVTheoHoTen(string ht) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (DoiChuoiInHoa(pdtsv[i]->GetKhoa()) == DoiChuoiInHoa(ht))
		{
			pdtsv[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co SV co ho ten la: " << ht << endl;
}
void TRUONGDH::TimKiemSVTheoKhoa(string kh) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (DoiChuoiInHoa(pdtsv[i]->GetKhoa()) == DoiChuoiInHoa(kh))
		{
			pdtsv[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co SV thuoc khoa " << kh << endl;
}
void TRUONGDH::TimKiemSVTheoDTB(double tb) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pdtsv[i]->GetDTB() == tb)
		{
			pdtsv[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co SV co DTB la: " << tb << endl;
}
void TRUONGDH::TimKiemSVTheoHocBong(long hb) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pdtsv[i]->TinhTienHocBong() == hb)
		{
			pdtsv[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co SV co hoc bong la: " << hb << endl;
}
void TRUONGDH::GhiFile(string tenfile)
{
	string nd;
	ofstream outputFile(tenfile);
	if (!outputFile.fail())
	{
		cout << "Ban nhap noi dung file(ket thuc bang dau ~): \n";
		while (1)
		{
			getline(cin, nd);
			if (nd.back() != '~')
				outputFile << nd << endl;
			else
			{
				nd.back() = '\0';
				outputFile << nd;
				break;
			}
		}
		outputFile.close();
		cout << "Da ghi thanh cong\n";

	}
	else cout << "Loi tao file\n";
}
void TRUONGDH::DocFile(string tenfile)
{
	string nd;
	ifstream inputFile(tenfile);
	if (!inputFile.fail())
	{
		while (getline(inputFile, nd)) cout << nd << endl;
		inputFile.close();
		cout << "Da doc file thanh cong\n";
	}
	else cout << "Loi doc file\n";
}
void TRUONGDH::DocFileDTSV(string tenfile)
{
	ifstream inputFile(tenfile);
	if (!inputFile.fail())
	{
		inputFile >> sl;
		if (sl > 0) {
			pdtsv = new DTSV * [sl];
			string ms, ht, kh;
			int l,bv;
			double tb, rl;
			long tt;
			for (int i = 0; i < sl; i++) {
				inputFile >> ms;
				inputFile >> ht;
				inputFile >> kh;
				inputFile >> l;
				inputFile >> tb;
				if (l == 1) {
					inputFile >> rl;
					pdtsv[i] = new SVCQ(ms, ht, kh, tb,rl);

				}
				else if (l == 2) {
					inputFile >> bv;
					pdtsv[i] = new SVLT(ms, ht, kh, tb, bv);
				}
				inputFile >> tt;
			}
			cout << "Da doc file va luu danh sach DTSV thanh cong\n";

		}
		else {
			cout << "So luong DTSV phai lon hon 0 \n";
		}
		inputFile.close();
	}
	else cout << "Loi doc file \n";
}
void TRUONGDH::GhiFileDTSV(string tenfile) {
	ofstream outputFile(tenfile);
	if (!outputFile.fail()) {
		outputFile << sl << endl;
		for (int i = 0; i < sl; i++)
		{
			outputFile << pdtsv[i]->GetMaSo() << "\t" << pdtsv[i]->GetHoTen() << "\t" << pdtsv[i]->GetKhoa() << "\t" << pdtsv[i]->GetLoai() << "\t" << pdtsv[i]->GetDTB() << "\t";
			if (pdtsv[i]->GetLoai() == 1)
				outputFile << pdtsv[i]->GetDRL() << "\t";
			else if (pdtsv[i]->GetLoai() == 2)
				outputFile << pdtsv[i]->GetSoBV() << "\t";
			outputFile << pdtsv[i]->TinhTienHocBong() << "\t";
		}
		outputFile.close();
		cout << "Da ghi file thanh cong\n";
	}
	else cout << "Loi ghi file\n";
}