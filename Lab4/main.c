#include <stdio.h>

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


void TrungBinhTong() {
    printf("\n\tTinh trung binh tong\n");
    int min, max;
    InVaNhapGiaTriKhongAm("\tNhap gia tri nho nhat: ", &min);
    InVaNhapGiaTriKhongAm("\tNhap gia tri lon nhat: ", &max);
    int i = min;
    float tong = 0, bien_dem = 0, trung_binh = 0;
    while (i <= max)
    {
        if (i % 2 == 0)
        {
            tong += i;
            bien_dem++;
        }
        i++;
    }
    trung_binh = tong/bien_dem;
    printf("\tTrung binh tong cac so chia het cho 2 tu %d den %d la %0.2f", min, max, trung_binh);
}

void XacDinhSoNguyenTo() {
    printf("\n\tTim so nguyen to\n");
    int x;
    InVaNhapGiaTriKhongAm("\tNhap gia tri can xac dinh: ", &x);
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            printf("\t%d khong phai la so nguyen to\n", x);
            return;
        }
           
    }
    printf("\t%d la so nguyen to\n",x);
}

void SoChinhPhuong() {
    printf("\n\tTim so chinh phuong\n");
    int x;
    InVaNhapGiaTriKhongAm("\tMoi nhap so can xac dinh la so chinh phuong: ", &x);
    for (int i = 0; i < x; i++)
    {
        if (i*i == x)
        {
            printf("\t%d la so chinh phuong\n",x);
            return;
        }
        
    }
    printf("\t%d khong phai la so chinh phuong\n",x);   
}

void GiaoDienMenu() {
    printf("\n===============================================\n");
    printf("= 1. Tinh trung binh tong                     =\n");
    printf("= 2. Tim so nguyen to                         =\n");
    printf("= 3. Tim so chinh phuong                      =\n");
    printf("= 4. Thoat                                    =\n");
    printf("===============================================\n");
}

void Menu() {
    int lua_chon;
    GiaoDienMenu();
    InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
    while (lua_chon != 4)
    {
        switch (lua_chon)
        {
        case 1:
            TrungBinhTong();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 2:
            XacDinhSoNguyenTo();
            GiaoDienMenu();
            InVaNhapGiaTriKhongAm("Xin moi nhap lua chon: ", &lua_chon);
            break;
        
        case 3:
            SoChinhPhuong();
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
    // TrungBinhTong();
    // XacDinhSoNguyenTo();
    // SoChinhPhuong();
    Menu();
}