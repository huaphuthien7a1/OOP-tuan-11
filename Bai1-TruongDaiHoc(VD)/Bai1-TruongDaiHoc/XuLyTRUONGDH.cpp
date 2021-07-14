#include"TRUONGDH.h"
#include"GV.h"
#include"SV.h"
#include"NV.h"
TRUONGDH::TRUONGDH() {
	pdtxs = NULL;
	sl = 0;
}
TRUONGDH::~TRUONGDH() {
	if (sl > 0) {
		for (int i = 0; i < sl; i++) 
			delete[]pdtxs[i];
		delete[]pdtxs;
		pdtxs = NULL;
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
	pdtxs = new DTXS * [sl];
	for (int i = 0; i < sl; i++) {
		cout << "-------------------------------\n";
		cout << "Nhap thong tin DTXS thu: " << i + 1 << ":\n";
		do {
			cout << "Nhap loai (1: GV, 2: SV, 3: NV): ";
			cin >> l;
		} while (l < 1 || l > 3);
		if (l == 1) pdtxs[i] = new GV;
		else if (l == 2) pdtxs[i] = new SV;
		else pdtxs[i] = new NV;
		pdtxs[i]->Nhap();

	}
}
void TRUONGDH::Xuat() {
	for (int i = 0; i < sl; i++) {
		pdtxs[i]->Xuat();
	}
}
void TRUONGDH::LietKeGVCoTu5BaiBao() {
	int dem = 0;
	for(int i=0;i<sl;i++)
		if (pdtxs[i]->GetLoai() == 1 && pdtxs[i]->GetSoBB() >= 5)
		{
			pdtxs[i]->Xuat();
			dem++;
		}
	if (dem == 0) cout << "Khong co GV nao co 5 bai bao tro len\n";
}

int TRUONGDH::DemSVCoDRLToiDa() {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pdtxs[i]->GetLoai() == 2 && pdtxs[i]->GetDRL() == 100)
			dem++;
	return dem;
}
long TRUONGDH::TinhTongTienThuongNVCo3SKKNTroLen() {
	long sum = 0;
	for (int i = 0; i < sl; i++)
		if (pdtxs[i]->GetLoai() == 3 && pdtxs[i]->GetSoSK() >= 3)
			sum += pdtxs[i]->TinhTienThuong();
	return sum;
}
double TRUONGDH::TinhDTBCuaSVCoDRLDuoi50() {
	double tongdtb = 0;
	int dem = 0;
	for(int i=0;i<sl;i++) 
		if (pdtxs[i]->GetLoai() == 2 && pdtxs[i]->GetDRL() < 50)
		{
			tongdtb += pdtxs[i]->GetDTB();
			dem++;
		}
	return dem > 0 ? tongdtb / dem : 0;
}
int TRUONGDH::KiemTraGVChuaCoBaiBao() {
	int kt = 1;
	for (int i = 0; i < sl; i++)
		if (pdtxs[i]->GetLoai() == 1)
			if (pdtxs[i]->GetSoBB() == 0)
			{
				kt = 2;
				break;
			}else kt = 3;
	return kt;
}
void TRUONGDH::TimNVCoSKKNNhieuNhat() {
	int skmax = -1, vt = -1;
	for(int i=0;i<sl;i++) 
		if (pdtxs[i]->GetLoai() == 3)
		{
			vt = i;
			skmax = pdtxs[i]->GetSoSK();
			break;
		}
	if (vt != -1)
	{
		for (int i = vt + 1; i < sl; i++)
			if (pdtxs[i]->GetLoai() == 3 && pdtxs[i]->GetSoSK() > skmax)
				skmax = pdtxs[i]->GetSoSK();
		for (int i = 0; i < sl; i++)
			if (pdtxs[i]->GetLoai() == 3 && pdtxs[i]->GetSoSK() == skmax)
				pdtxs[i]->Xuat();
	}
	else cout << "Truong khong co NV";
}

string TRUONGDH::DoiChuoiInHoa(string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	return str;
}
string TRUONGDH::DoiChuoiInThuong(string str) {
	for (int i = 0; i < str.length(); i++)
		str[i] = tolower(str[i]);
	return str;
}
void TRUONGDH::SapXepMaSoTangDan() {
	for (int i = 0; i < sl; i++)
		for (int j = i + 1; j < sl;j++)
			if (DoiChuoiInHoa(pdtxs[i]->GetMaSo()) > DoiChuoiInHoa(pdtxs[j]->GetMaSo()))
			{
				DTXS* ptam = pdtxs[i];
				pdtxs[i] = pdtxs[j];
				pdtxs[j] = ptam;
			}
}
void TRUONGDH::SapXepGiamDanTheoTienThuong() {
	for (int i = 0; i < sl; i++)
		for (int j = i + 1; j < sl; j++)
			if (pdtxs[i]->TinhTienThuong() < pdtxs[j]->TinhTienThuong())
			{
				DTXS* ptam = pdtxs[i];
				pdtxs[i] = pdtxs[j];
				pdtxs[j] = ptam;
			}
}

void TRUONGDH::TimDTXSTheoTungKhoa(string kh) {
	int dem = 0;
	for(int i=0;i<sl;i++)
		if (DoiChuoiInHoa(pdtxs[i]->GetKhoa()) == DoiChuoiInHoa(kh))
		{
			pdtxs[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co DTXS thuoc khoa " << kh << endl;
}
void TRUONGDH::TimDTXSTheoMaSo(string ms) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (DoiChuoiInHoa(pdtxs[i]->GetKhoa()) == DoiChuoiInHoa(ms))
		{
			pdtxs[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co DTXS co ma so " << ms << endl;
}
void TRUONGDH::TimDTXSTheoHoTen(string ht) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (DoiChuoiInHoa(pdtxs[i]->GetKhoa()) == DoiChuoiInHoa(ht))
		{
			pdtxs[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co DTXS co ho ten la: " << ht << endl;
}
void TRUONGDH::TimDTXSTheoTienThuong(long tt) {
	int dem = 0;
	for (int i = 0; i < sl; i++)
		if (pdtxs[i]->TinhTienThuong() == tt)
		{
			pdtxs[i]->Xuat();
			dem++;
		}
	if (!dem) cout << "Khong co DTXS co tien thuong la: " << tt << endl;
}
void TRUONGDH::CapNhatThongTinTheoMaSo(string ms) {
	int timthay = -1;
	for(int i=0;i<sl;i++) 
		if (DoiChuoiInHoa(pdtxs[i]->GetMaSo()) == DoiChuoiInHoa(ms))
		{
			timthay = 1;
			string ht, kh;
			
			cout << "Nhap ho ten: ";
			getline(cin, ht);
			cout << "Nhap khoa: ";
			getline(cin, kh);
			pdtxs[i]->SetKhoa(kh);
			if (pdtxs[i]->GetLoai() == 1) {
				int bb;
				cout << "Nhap so bai bao: ";
				cin >> bb;
				pdtxs[i]->SetSoBB(bb);
			}
			else if (pdtxs[i]->GetLoai() == 2) {
				double tb, rl;
				cout << "Nhap DTB: ";
				cin >> tb;
				pdtxs[i]->SetDTB(tb);
				cout << "Nhap DRL: ";
				cin >> rl;
				pdtxs[i]->SetDRL(rl);

			}else{
				int sk;
				cout << "Nhap so SKKN: ";
				cin >> sk;
				pdtxs[i]->SetSoSK(sk);
			}
			cout << "Da cap nhat thong tin DTXS co ma so la " << ms << endl;
			Xuat();
		}
	if (timthay == -1) cout << "Khong tim thay DTXS co ma so la " << ms << endl;
}
void TRUONGDH::ThemDTXS() {
	DTXS* newEle;
	int l;
	cout << "Nhap thong tin DTXS muon them\n";
	do {
		cout << "Nhap loai (1: GV, 2: SV, 3: NV): ";
		cin >> l;
	} while (l < 1 || l > 3);
	if (l == 1) newEle = new GV;
	else if (l == 2) newEle = new SV;
	else newEle = new NV;
	newEle->Nhap();
	DTXS** temp = new DTXS * [sl + 1];
	for (int i = 0; i < sl; i++) temp[i] = pdtxs[i];
	//for (int i = 0; i < sl; i++) delete[]pdtxs[i];
	//delete[]pdtxs;
	pdtxs = temp;
	pdtxs[sl++] = newEle;
	Xuat();
}
void TRUONGDH::XoaDTXS(string ms) {


	int j=0;
	
	DTXS** temp = new DTXS * [sl - 1];
	for (int i = 0; i < sl; i++) {
		if (DoiChuoiInHoa(pdtxs[i]->GetMaSo()) == DoiChuoiInHoa(ms)) i++;
		temp[j++] = pdtxs[i];
	}
	pdtxs = temp;
	sl--;
	Xuat();
}
void TRUONGDH::XoaToanBo() {
	for (int i = sl - 1; i > 0; i--)
	{
		XoaDTXS(pdtxs[i]->GetMaSo());
	}
	sl = 0;
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
void TRUONGDH::DocFileDTXS(string tenfile)
{
	ifstream inputFile(tenfile);
	if (!inputFile.fail())
	{
		inputFile >> sl;
		if (sl > 0) {
			pdtxs = new DTXS * [sl];
			string ms, ht, kh;
			int l, bb, sk;
			double tb, rl;
			long tt;
			for (int i = 0; i < sl; i++) {
				inputFile >> ms;
				inputFile >> ht;
				inputFile >> kh;
				inputFile >> l;
				if (l == 1) {
					inputFile >> bb;
					pdtxs[i] = new GV(ms, ht, kh, bb);

				}
				else if (l == 2) {
					inputFile >> tb;
					inputFile >> rl;
					pdtxs[i] = new SV(ms, ht, kh, tb, rl);
				}
				else {
					inputFile >> sk;
					pdtxs[i] = new NV(ms, ht, kh, sk);
				}
				inputFile >> tt;
			}
			cout << "Da doc file va luu danh sach DTXS thanh cong\n";

		}
		else {
			cout << "So luong DTXS phai lon hon 0 \n";
		}
		inputFile.close();
	}
	else cout << "Loi doc file \n";
}
void TRUONGDH::GhiFileDTXS(string tenfile) {
	ofstream outputFile(tenfile);
	if (!outputFile.fail()) {
		outputFile << sl << endl;
		for (int i = 0; i < sl; i++)
		{
			outputFile << pdtxs[i]->GetMaSo() << "\t" << pdtxs[i]->GetHoTen() << "\t" << pdtxs[i]->GetKhoa() << "\t" << pdtxs[i]->GetLoai() << "\t";
			if (pdtxs[i]->GetLoai() == 1)
				outputFile << pdtxs[i]->GetSoBB() << "\t";
			else if (pdtxs[i]->GetLoai() == 2)
				outputFile << pdtxs[i]->GetDTB() << "\t" << pdtxs[i]->GetDRL() << "\t";
			else if (pdtxs[i]->GetLoai() == 3)
				outputFile << pdtxs[i]->GetSoSK() << "\t";
			outputFile << pdtxs[i]->TinhTienThuong() << "\t";
		}
		outputFile.close();
		cout << "Da ghi file thanh cong\n";
	}
	else cout << "Loi ghi file\n";
}