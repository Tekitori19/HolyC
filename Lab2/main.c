#include <stdio.h>


const float PI = 3.14159265;

// Xử dụng để in ra thông báo cần thiết và nhập giá trị
void InVaNhapGiaTri(char *text, float *so) {
    printf(text);
    scanf("%f",so);
}

void InVaNhapGiaTriKhongAm(char *text, float *so) {
    printf(text);
    scanf("%f",so);
    
    while (*so < 0 )
        {
            printf("!!!! CHI DUOC PHEP NHAP SO DUONG !!!!\n");
            printf("Nhap lai: ");
            scanf("%f",so);
        }
}

//Kiểm tra điểm số xem có hợp lệ hay không
void KiemTraDiemSo(char *text, float *so) {
    printf(text);
    scanf("%f",so);
    
    while (*so < 0 || *so >10)
        {
            printf("!!!! CHI DUOC PHEP NHAP SO DUONG NHO HON HOAC BANG 10 !!!!\n");
            printf("Nhap lai: ");
            scanf("%f",so);
        }
}

//======================================= XÂY DỰNG CHƯƠNG TRÌNH +- 2 SỐ ============================================================
void TongHieu2So(float so_thu_nhat,  float so_thu_hai) {
    printf("Tong 2 so: %.1f\n", so_thu_nhat+so_thu_hai);
    printf("So thu nhat - so thu hai= %.1f\n", so_thu_nhat-so_thu_hai);
    printf("So thu hai - so thu nhat= %.1f\n", so_thu_hai-so_thu_nhat);
}
//======================================= XÂY DỰNG CHƯƠNG TRÌNH +- 2 SỐ ============================================================


//======================================= XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH HCN =======================================
void HCN(float chieu_dai, float chieu_rong) {

    if (chieu_dai < 0 || chieu_rong <0) {
        printf("ERROR: Chieu dai va chieu rong phai la so duong");
        return;
    }

    float chu_vi = (chieu_dai + chieu_rong)*2;
    float dien_tich = chieu_dai *chieu_rong;
    printf("Hinh chu nhat voi chieu dai %.1f, chieu rong %.1f co dien tich la: %.1f\n", chieu_dai, chieu_rong, dien_tich);
    printf("Hinh chu nhat voi chieu dai %.1f, chieu rong %.1f co chu vi la: %.1f\n", chieu_dai, chieu_rong, chu_vi);
}
//======================================= XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH HCN =======================================


//======================================= XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH TRÒN ======================================
void HinhTron(float ban_kinh) {
    
    if (ban_kinh < 0) {
        printf("ERROR: Ban kinh phai la so duong");
        return;
    }
    
    float chu_vi = 2*PI*ban_kinh;
    float dien_tich = ban_kinh*ban_kinh*PI;
    printf("Dien tich hinh tron co ban kinh %.1f la: %.1f\n", ban_kinh, dien_tich);
    printf("Chu vi hinh tron co ban kinh %.1f la: %.1f\n", ban_kinh, chu_vi);
}

//======================================= XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH TRÒN ======================================


//======================================= XÂY DỰNG CHƯƠNG TRÌNH TÍNH ĐIỂM TRUNG BÌNH ===============================================
void DiemTrungBinh(float toan, float li, float hoa) {

    if (toan < 0 || li < 0 || hoa <0) {
        printf("ERROR: Diem Toan-Li-Hoa khong duoc la so am");
        return;
    }

    float diem_trung_binh = (toan*3 + li*2 +hoa)/9;
    printf("Diem trung binh 3 mon la: %.2f", diem_trung_binh);
}
//======================================= XÂY DỰNG CHƯƠNG TRÌNH TÍNH ĐIỂM TRUNG BÌNH ===============================================

int main() {
    //  XÂY DỰNG CHƯƠNG TRÌNH +- 2 SỐ
    {
        float so_thu_nhat, so_thu_hai;

        InVaNhapGiaTri("Nhap so thu nhat: ", &so_thu_nhat);
        InVaNhapGiaTri("Nhap so thu hai: ", &so_thu_hai);

        TongHieu2So(so_thu_nhat,so_thu_hai);
    }
    //  XÂY DỰNG CHƯƠNG TRÌNH +- 2 SỐ

    // XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH HCN
    {
        printf("\n-----Tinh chu vi va dien tich hinh chu nhat-----\n");

        float chieu_dai, chieu_rong;

        InVaNhapGiaTriKhongAm("Nhap chieu dai: ", &chieu_dai);
        InVaNhapGiaTriKhongAm("Nhap chieu rong: ", &chieu_rong);

        HCN(chieu_dai, chieu_rong);
    }
    // XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH HCN
    
    // XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH HÌNH TRÒN
    {
        printf("\n-----Tinh chu vi va dien tich hinh tron-----\n");
        float ban_kinh;

        InVaNhapGiaTriKhongAm("Nhap ban kinh hinh tron: ", &ban_kinh);

        HinhTron(ban_kinh);
    }
    // XÂY DỰNG CHƯƠNG TRÌNH TÍNH CHU VI VÀ DIỆN TÍCH HÌNH TRÒN


    // XÂY DỰNG CHƯƠNG TRÌNH TÍNH ĐIỂM TRUNG BÌNH TOÁN, LÍ, HÓA
    {
        printf("\n-----Tinh diem trung binh-----\n");
        float toan, li, hoa;

        KiemTraDiemSo("Nhap diem toan: ", &toan);
        KiemTraDiemSo("Nhap diem li: ", &li);
        KiemTraDiemSo("Nhap diem hoa: ", &hoa);

        DiemTrungBinh(toan, li, hoa);
    }
    // XÂY DỰNG CHƯƠNG TRÌNH TÍNH ĐIỂM TRUNG BÌNH TOÁN, LÍ, HÓA

    return 0;
}
