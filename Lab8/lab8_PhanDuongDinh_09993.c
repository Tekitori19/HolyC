#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien {
    char mssv[50];
    char ten[50];
    char nganh[50];
    float diem;
} SV[50];

void DanhSach() {
    int n;
    printf("Nhap so sinh vien can them: ");
    scanf("%d", &n);

    // Loại bỏ ký tự '\n' khi nhập số n
    while ((getchar()) != '\n');

    for (int i = 0; i < n; i++) {
        printf("\nNhap Mssv thu %d la: ", i + 1);
        gets(SV[i].mssv);

        printf("Nhap Ho Ten sv thu %d la: ", i + 1);
        gets(SV[i].ten);

        printf("Nhap Nganh sv thu %d la: ", i + 1);
        gets(SV[i].nganh);

        printf("Nhap Diem TB sv thu %d la: ", i + 1);
        scanf("%f", &SV[i].diem);

        // Loại bỏ ký tự '\n' khi nhập điểm
        while ((getchar()) != '\n');
    }

    int is_sort;
    printf("Ban co muon sap xep sv hay khong (1:CO, 0:KHONG): ");
    scanf("%d",&is_sort);
    if (is_sort == 1)
    { 
        SapXep();
    }
    
    for (int i = 0; i < n; i++) {
        printf("\nThong tin SV thu %d", i+1);
        printf("\nMSSV: %s", SV[i].mssv);
        printf("\nHo Ten: %s", SV[i].ten);
        printf("\nNganh: %s", SV[i].nganh);
        printf("\nDiem TB: %.1f\n", SV[i].diem);
    }

    int is_found;
    printf("Ban co muon tim kiem sv hay khong (1:CO, 0:KHONG): ");
    scanf("%d",&is_found);
    if (is_found == 1)
    { 
        TimKiem(n);
    }

}

//Sắp xếp
int SoSanh(const void *a,const void *b){
    const struct SinhVien* sv1 = (const struct SinhVien*)a;
    const struct SinhVien* sv2 = (const struct SinhVien*)b;
    return sv2->diem - sv1->diem;
    // return (sv2->diem > sv1->diem) - (sv2->diem < sv1->diem);
}

void SapXep() {
    qsort(SV, 50, sizeof(struct SinhVien), SoSanh);
}
//Sắp xếp

//Tìm kiếm
void TimKiem(int n) {
    char ma_sv[50];
    printf("Nhap ma SV: ");
    // Loại bỏ ký tự '\n' khi nhấn enter
    while ((getchar()) != '\n');
    gets(ma_sv);
    for (int i = 0; i < n; i++)
    {
        const int result = strcmp(SV[i].mssv, ma_sv);
        if (result == 0)
        {
            printf("Tim thay");
            printf("\nMSSV: %s",SV[i].mssv);
	        printf("\nHo Ten: %s",SV[i].ten);
	        printf("\nNganh: %s",SV[i].nganh);
	        printf("\nDiem TB: %.1f\n",SV[i].diem);
        }
        
    }
    
}
//Tìm kiếm

int main() {
    DanhSach();
    return 0;
}
