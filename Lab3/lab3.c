#include <stdio.h>
#include <math.h>

void InVaNhapGiaTriKhongAmCoDieuKien(char *text, float *so, int dieu_kien) {
    printf(text);
    scanf("%f",so);
    
    while (*so < 0 || *so > dieu_kien)
        {
            printf("!!!! CHI DUOC PHEP NHAP SO DUONG VA DUNG VOI DIEU KIEN!!!!\n");
            printf("Nhap lai: ");
            scanf("%f",so);
        }
}

void InVaNhapGiaTriKhongAm(char *text, float *so) {
    printf(text);
    scanf("%f",so);
    
    while (*so < 0)
        {
            printf("!!!! CHI DUOC PHEP NHAP SO DUONG !!!!\n");
            printf("Nhap lai: ");
            scanf("%f",so);
        }
}

void InVaNhapGiaTri(char *text, float *so) {
    printf(text);
    scanf("%f",so);
}

void TinhHocLuc() {
    printf("\n-Chuong trinh tinh hoc luc\n");
    
    float so_diem;
    
    InVaNhapGiaTriKhongAmCoDieuKien("Vui long nhap diem: ", &so_diem, 10);
    
    if (so_diem >= 9)
    {
        printf("Hoc luc xuat sac\n");
    } else if (so_diem >= 8)
    {
        printf("Hoc luc gioi\n");
    } else if (so_diem >= 6.5)
    {
        printf("Hoc luc kha\n");
    } else if (so_diem >= 5)
    {
        printf("Hoc luc trung binh\n");
    } else if (so_diem >= 3.5)
    {
        printf("Hoc luc yeu\n");
    } else {
        printf("Hoc luc kem\n");
    }
}

void GiaiPhuongTrinhBac1() {
    
    printf("\n-Chuong trinh giai phuong trinh bac 1 (ax + b = 0)\n");
    
    float a, b;
    
    InVaNhapGiaTri("Vui long nhap a: ", &a);
    InVaNhapGiaTri("Vui long nhap b: ", &b);

    if (a == 0)
    {
        if (b == 0)
        {
            printf("Phuong trinh vo so nghiem");
        } else
        {
            printf("Phuong trinh vo nghiem");
        }   
    } else
    {
        float ket_qua = -b/a;
        printf("Phuong trinh co nghiem x = %.1f\n", ket_qua);
    }
}

void GiaiPhuongTrinhBac2() {

    printf("\n-Chuong trinh giai phuong trinh bac 1 (ax^2 + bx +c = 0)\n");

    float a, b, c;

    InVaNhapGiaTri("Vui long nhap a: ", &a);
    InVaNhapGiaTri("Vui long nhap b: ", &b);
    InVaNhapGiaTri("Vui long nhap c: ", &c);

    if (a == 0)
    {
        GiaiPhuongTrinhBac1(b, c);
    } else {
        double delta = pow(b, 2) - 4*a*c;

        if (delta < 0)
        {
            printf("Phuong trinh vo nghiem\n");
        } else if (delta == 0)
        {
            double nghiem_kep = -b/(a*2);
            printf("Phuong trinh co nghiem kep: %.2lf\n", nghiem_kep);
        } else {
            double nghiem_x1 = (-b + sqrt(delta))/(2*a);
            double nghiem_x2 = (-b - sqrt(delta))/(2*a);

            printf("Phuong trinh co hai nghiem %.2lf va %.2lf\n", nghiem_x1, nghiem_x2);
        }
    }
}

void TinhTienDien() {

    float so_dien, tien;

    InVaNhapGiaTriKhongAm("Vui long nhap so dien tieu thu: ", &so_dien);

    const int gia_dien_bac1 = 1678;
    const int gia_dien_bac2 = 1734;
    const int gia_dien_bac3 = 2014;
    const int gia_dien_bac4 = 2536;
    const int gia_dien_bac5 = 2834;
    const int gia_dien_bac6 = 2927;

    if (so_dien <= 50) {
        tien = so_dien*gia_dien_bac1;
        printf("Gia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 100) {
        tien = (50*gia_dien_bac1) + (so_dien - 50) * gia_dien_bac2;
        printf("Gia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 200) {
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (so_dien - 100) * gia_dien_bac3;
        printf("Gia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 300) {
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (so_dien - 200) * gia_dien_bac4;
        printf("Gia tien la: %0.1f dong", tien);
    }
    else if (so_dien <= 400) { 
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (100 * gia_dien_bac4) + (so_dien - 300) * gia_dien_bac5;
        printf("Gia tien la: %0.1f dong", tien);
    }
    else{
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (100 * gia_dien_bac4) + (100 * gia_dien_bac5) + (so_dien - 400) * gia_dien_bac6;
        printf("Gia tien la: %0.1f dong", tien);
    }
}

void SubMenu(){
    printf("\n 0. Thoat chuong trinh");
    printf("\n 1. Tinh hoc luc");
    printf("\n 2. Giai pt bac 1");
    printf("\n 3. Giai pt bac 2");
    printf("\n 4. Tinh tien dien");
}

void Menu() {
    printf("===============================================\n");
    printf("= 0. Thoat chuong trinh                       =\n");
    printf("= 1. Tinh hoc luc                             =\n");
    printf("= 2. Giai phuong trinh bac 1                  =\n");
    printf("= 3. Giai phuong trinh bac 2                  =\n");
    printf("= 4. Tinh tien dien                           =\n");
    printf("===============================================\n");

    float lua_chon;

    InVaNhapGiaTriKhongAmCoDieuKien("Nhap lua chon: ", &lua_chon, 4);

    while (lua_chon != 0)
    {
        switch ((int) lua_chon)
        {
        case 1:
            TinhHocLuc();
            SubMenu();
            InVaNhapGiaTriKhongAmCoDieuKien("\n\t--Nhap lua chon: ", &lua_chon, 4);
            break;
        
        case 2:
            GiaiPhuongTrinhBac1();
            SubMenu();
            InVaNhapGiaTriKhongAmCoDieuKien("\n\t--Nhap lua chon: ", &lua_chon, 4);
            break;
        
        case 3:
            GiaiPhuongTrinhBac2();
            SubMenu();
            InVaNhapGiaTriKhongAmCoDieuKien("\n\t--Nhap lua chon: ", &lua_chon, 4);
            break;
        
        case 4:
            TinhTienDien();
            SubMenu();
            InVaNhapGiaTriKhongAmCoDieuKien("\n\t--Nhap lua chon: ", &lua_chon, 4);
            break;
        
        default:
            break;
        }
    }
    printf("============================================>100%\n Thoat chuong trinh thanh cong\n");
}

void main() {
    Menu();
}