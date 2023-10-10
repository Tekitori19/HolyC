#include <stdio.h>
#include <string.h>
#include<ctype.h>

char *strlwr(char *str)
{
  unsigned char *p = (unsigned char *)str;

  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }

  return str;
}


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
    int n;
    scanf("%d",&n);
    int so_dem =n+1;
    char ho_va_ten[so_dem][30];
    printf("Nhap danh sach\n");
    for (int i = 0; i < so_dem; i++)
    {
        if (i !=0 )
        {
            printf("\nMoi nhap nguoi thu %d: ", i);
        }
        //ERROR: buffer overfow(NEED TO CHECK) 
        gets(ho_va_ten[i]);
    }
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("gia tri: ");
    //     puts(ho_va_ten[i]);
    // }
    const char name[5]="cons";
    char *point = strstr("draco", name);
    printf("\n%s\n", point);

    char ten[20];
    printf("Nhap ten: ");
    gets(ten);
    int isFound = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(ten, ho_va_ten[i])==0)
        {
            printf("\ntim thay\n");
            // printf("%d\n", strlwr ("ADALDJALKDJ"));
            isFound = 1;
        }
        
    }
    if (isFound == 0)
    {
        printf("Khong tim thay ten\n");
    }

}