#include <stdio.h>

// THAM KHẢO TẠI https://stackoverflow.com/questions/3437404/min-and-max-in-c
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

void InVaNhapGiaTriKhongAm(char *text, int *so) {
    printf(text);
    scanf("%d",so);
    
    while (*so < 0)
        {
            printf("!!!! CHI DUOC PHEP NHAP SO DUONG !!!!\n");
            printf("Nhap lai: ");
            scanf("%d",so);
        }
}

void InVaNhapGiaTriDuongKhac0(char *text, int *so) {
    printf(text);
    scanf("%d",so);
    
    while (*so == 0 || *so < 0)
        {
            printf("\t!!!! CHI DUOC PHEP NHAP SO DUONG KHAC 0 !!!!\n");
            printf("Nhap lai: ");
            scanf("%d",so);
        }
}

void InVaNhapGiaTriKhongAmCoDieuKien(char *text, int *so, int dieu_kien_1, int dieu_kien_2) {
    printf(text);
    scanf("%d",so);
    
    while (*so < 0 || *so < dieu_kien_1 || *so > dieu_kien_2)
        {
            printf("\t!!!! CHI DUOC PHEP NHAP SO DUONG VA DUNG VOI DIEU KIEN!!!!\n");
            printf("Nhap lai: ");
            scanf("%d",so);
        }
}

// KIỂM TRA SỐ NGUYÊN TỐ
int XacDinhSoNguyenTo(int x) {
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            // printf("\t%d khong phai la so nguyen to\n", x);
            return 0;
        }
           
    }
    printf("\t%d la so nguyen to\n",x);
    return 1;
}

int SoChinhPhuong(int x) {
    for (int i = 0; i < x; i++)
    {
        if (i*i == x)
        {
            printf("\t%d la so chinh phuong\n",x);
            return 1;
        }
        
    }
    // printf("\t%d khong phai la so chinh phuong\n",x);   
    return 0;
}

void KiemTraSoNguyen() {
    printf("\n\tKiem tra so nguyen\n");
    int x;
    InVaNhapGiaTriKhongAm("\tMoi nhap so can xac dinh: ", &x);
    int err1 = XacDinhSoNguyenTo(x);
    int err2 = SoChinhPhuong(x);

    if (err1 == 0 && err2 == 0)
    {
        printf("\t%d la so nguyen", x);
    }
    
}
// KIỂM TRA SỐ NGUYÊN TỐ

// TÌM UCLN VÀ BCNN
int UCLN(int x, int y) {
    int temp = 0;
    int min = MIN(x, y);
    int max = MAX(x, y);
    
    for (int i = 1; i < max; i++)
    {
        if (min % i == 0 && max % i ==0)
        {
            temp = i;
        }   
    }
    printf("\tUCLN la %d", temp);
    return temp;
}

void BCNN(int x, int y, int ucln) {
    int bcnn = (x*y)/ucln;
    printf("\tBCNN la %d", bcnn);
}

void UocChungBoiChung() {
    printf("\n\tTim uoc chung, boi chung\n");
    int x,y;
    InVaNhapGiaTriDuongKhac0("\tMoi nhap so thu nhat: ", &x);
    InVaNhapGiaTriDuongKhac0("\tMoi nhap so thu hai: ", &y);
    int ucln = UCLN(x,y);
    BCNN(x, y, ucln);
}
// TÌM UCLN VÀ BCNN

// TÍNH TIỀN KARAOKE
void TinhTienKaraoke(int gio_bat_dau,int gio_ket_thuc) {
    const int GIA3GIODAU = 150000;
    const float GIASAU4GIO = GIA3GIODAU - (GIA3GIODAU * 30)/100;
    int so_gio_hat = gio_ket_thuc - gio_bat_dau;
    float tien;

    if (so_gio_hat < 4)
    {
        tien = GIA3GIODAU * so_gio_hat;
    } else
    {
        tien = GIA3GIODAU * 3 + GIASAU4GIO * (so_gio_hat - 3);
    }
    
    if (gio_bat_dau >= 14 && gio_bat_dau <= 17)
    {
        tien = tien - (tien * 10)/100;
    }
    
    printf("\tTong tien karaoke la: %.2f", tien);
    
}

void Karaoke() {
    printf("\n\tTinh tien karaoke\n");
    int gio_bat_dau, gio_ket_thuc;
    InVaNhapGiaTriKhongAmCoDieuKien("\tVui long nhap gio bat dau: ", &gio_bat_dau, 12, 23);
    InVaNhapGiaTriKhongAmCoDieuKien("\tVui long nhap gio ket thuc: ", &gio_ket_thuc, 12, 23);
    if (gio_bat_dau > gio_ket_thuc)
    {
        printf("\tERR: GIO BAT DAU KHONG DUOC LON HON GIO KET THUC!!!!");
        return;
    }
    
    TinhTienKaraoke(gio_bat_dau, gio_ket_thuc);
}
// TÍNH TIỀN KARAOKE

// TÍNH TIỀN ĐIỆN
void TinhTienDien() {
    int so_dien;
    float tien;

    InVaNhapGiaTriKhongAm("\tVui long nhap so dien tieu thu: ", &so_dien);

    const int gia_dien_bac1 = 1678;
    const int gia_dien_bac2 = 1734;
    const int gia_dien_bac3 = 2014;
    const int gia_dien_bac4 = 2536;
    const int gia_dien_bac5 = 2834;
    const int gia_dien_bac6 = 2927;

    if (so_dien <= 50) {
        tien = so_dien*gia_dien_bac1;
        printf("\tGia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 100) {
        tien = (50*gia_dien_bac1) + (so_dien - 50) * gia_dien_bac2;
        tien = tien + (tien * 8)/100;
        printf("\tGia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 200) {
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (so_dien - 100) * gia_dien_bac3;
        tien = tien + (tien * 8)/100;
        printf("\tGia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 300) {
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (so_dien - 200) * gia_dien_bac4;
        tien = tien + (tien * 8)/100;
        printf("\tGia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 400) { 
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (100 * gia_dien_bac4) + (so_dien - 300) * gia_dien_bac5;
        tien = tien + (tien * 8)/100;
        printf("\tGia tien la: %0.1f dong", tien);
    }
    else{
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (100 * gia_dien_bac4) + (100 * gia_dien_bac5) + (so_dien - 400) * gia_dien_bac6;
        tien = tien + (tien * 8)/100;
        printf("\tGia tien la: %0.1f dong", tien);
    }
}
// TÍNH TIỀN ĐIỆN

// ĐỔI TIỀN
void DoiTien() {
    printf("\tChuc nang doi tien");
    int tien_can_doi;
    int tien_500 = 0;
    int tien_200 = 0;
    int tien_100 = 0;
    int tien_50 = 0;
    int tien_20 = 0;
    int tien_10 = 0;
    int tien_5 = 0;
    int tien_2 = 0;
    int tien_1 = 0;
    InVaNhapGiaTriDuongKhac0("\n\tNhap tien can doi: ", &tien_can_doi);
    int tien = tien_can_doi;
    while (tien_can_doi > 0)
    {
        if (tien_can_doi >= 500)
        {
            tien_500 = tien_can_doi/500;
            tien_can_doi %= 500;
        } else if (tien_can_doi >= 200)
        {
            tien_200 = tien_can_doi/200;
            tien_can_doi %= 200;
        } else if (tien_can_doi >= 100)
        {
            tien_100 = tien_can_doi/100;
            tien_can_doi %= 100;
        } else if (tien_can_doi >= 50)
        {
            tien_50 = tien_can_doi/50;
            tien_can_doi %= 50;
        } else if (tien_can_doi >= 20)
        {
            tien_20 = tien_can_doi/20;
            tien_can_doi %= 20;
        } else if (tien_can_doi >= 10)
        {
            tien_10 = tien_can_doi/10;
            tien_can_doi %= 10;
        } else if (tien_can_doi >= 5)
        {
            tien_5 = tien_can_doi/5;
            tien_can_doi %= 5;
        } else if (tien_can_doi >= 2)
        {
            tien_2 = tien_can_doi/2;
            tien_can_doi %= 2;
        }else
        {
            tien_can_doi -= 1;
            tien_1++;
        }
    }
    printf("\t%d =  %d to 500,\n\t\t%d to 200,\n\t\t%d to 100,\n\t\t%d to 50,\n\t\t%d to 20,\n\t\t%d to 10,\n\t\t%d to 5,\n\t\t%d to 2,\n\t\t%d to 1", tien, tien_500, tien_200, tien_100, tien_50, tien_20, tien_10, tien_5, tien_2, tien_1);

}
// ĐỔI TIỀN

void VayNganHangTraGop() {
    printf("vay ngan hang");
}

void TinhLaiVayTienMuaXe() {
    printf("vay tien mua xe");
}

void SapXepThongTinSinhVien() {
    printf("sap xep sv");
}

void Fpoly_Lott() {
    printf("FPOLY LOTT");
}

void TinhToanPhanSo() {
    printf("tinh phan so");
}


void GiaoDienMenu() {
    printf("\n\n===============================================\n");
    printf("= 0. Thoat chuong trinh                       =\n");
    printf("= 1. Kiem tra so nguyen                       =\n");
    printf("= 2. Uoc chung va boi chung cua 2 so          =\n");
    printf("= 3. Tinh tien quan karaoke                   =\n");
    printf("= 4. Tinh tien dien                           =\n");
    printf("= 5. Doi tien                                 =\n");
    printf("= 6. Tinh lai xuat ngan hang vay tra gop      =\n");
    printf("= 7. Vay tien mua xe                          =\n");
    printf("= 8. Sap xep thong tin sinh vien              =\n");
    printf("= 9. Game FPOLY-LOTT                          =\n");
    printf("= 10.Tinh toan phan so                        =\n");
    printf("===============================================\n");
}

void Menu() {
    int lua_chon;
    GiaoDienMenu();
    InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
    while (lua_chon)
    {
        switch (lua_chon)
        {
        case 0:
            break;
        
        case 1:
            KiemTraSoNguyen();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 2:
            UocChungBoiChung();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 3:
            Karaoke();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 4:
            TinhTienDien();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 5:
            DoiTien();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 6:
            VayNganHangTraGop();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 7:
            TinhLaiVayTienMuaXe();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 8:
            SapXepThongTinSinhVien();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 9:
            Fpoly_Lott();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 10:
            TinhToanPhanSo();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        default:
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap LAI lua chon: ", &lua_chon);
            break;
        }
    }
        printf("============================================>100%\n Thoat chuong trinh thanh cong\n");
}

void main() {
    Menu();
}