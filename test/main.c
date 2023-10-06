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

void InVaNhapGiaTriKhongAmCoDK(char *text, int *so,int dieu_kien) {
    printf(text);
    scanf("%d",so);
    
    while (*so < 0 || *so < dieu_kien)
        {
            printf("!!!! CHI DUOC PHEP NHAP SO DUONG !!!!\n");
            printf("Nhap lai: ");
            scanf("%d",so);
        }
}

void KiemTra() {
    int n;
    int phan_du = 0;
    InVaNhapGiaTriKhongAm("Nhap so n: ", &n);
    while (n > 0)
    {
        phan_du = n % 10;
        if (phan_du % 2 == 0)
        {
            printf("so N KHONG hoan toan tao thanh tu so le");
            return;
        }
        n/=10;
    }
    printf("so N hoan toan tao thanh tu so le");
    
}

// void DaoNguoc() {
//     int so_nhap;
//     int so_du;
//     int ket_qua = 0;
//     InVaNhapGiaTriKhongAm("nhap so dao ngc ", &so_nhap);

//     while (so_nhap > 0)
//     {
//         so_du = so_nhap % 10;
//         so_nhap /= 10;
//         ket_qua *= ket_qua *;
//     }
//     printf("%d\n", ket_qua);

// }

void NhiPhan(){
    int n;
    int phan_du[100];
    int i = 0;
    // int res = 0;

    InVaNhapGiaTriKhongAm("nhap so can chuyen: ", &n);
    while (n != 0)
    {
        phan_du[i] = n % 2;
        n = n /2;
        i++; 
        // res = res*10 + n %2;
    }

    for (int j = 0; j < i; j++)
    {
        printf("%d",phan_du[i -1 - j]);
    }
    // printf("\n%d", res);
}

void NhiPhan2() {
    int n;
    int du;
    int res = 0 ;

    InVaNhapGiaTriKhongAm("nhap so can chuyen: ", &n);

    while (n != 0)
    {
        du = n % 2;
        n =n /2;
        res = res * 10 +du;
    }

    printf("%d",res);
    
}

void main() {
    // NhiPhan();
    // NhiPhan2();
    int n=0; for (int i=0; i<10; i+=4) n+=i;
    printf("%d",n);
}