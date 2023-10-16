#include <stdio.h>
#include <stdlib.h>


int n = 5;

void NhapMang(int* mang) {
    for (int i = 0; i < n; i++)
    {
        int temp;
        printf("Nhap phan tu so %d: ", i+1);
        scanf("%d", &temp);
        mang[i] = temp;
    }
    
}

void InMang(int* mang) {
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", mang[i]);
    }
    
}

//Sap xep tang dan
int SoSanhTang(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void SapXepTangDan(int* mang) {
    qsort(mang, n, sizeof(int), SoSanhTang);
}
//Sap xep tang dan

//Sap xep giam dan
int SoSanhGiam(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

void SapXepGiamDan(int* mang) {
    qsort(mang, n, sizeof(int), SoSanhGiam);
}
//Sap xep giam dan

void TBCMang(int* mang) {
    int tong = 0;
    int tong_chan = 0;
    int tong_le = 0;
    for (int i = 0; i < n; i++)
    {
        tong += mang[i];
        if (mang[i] % 2 == 0)
        {
            tong_chan += mang[i]
        }
        if (mang[i] % 2 == 1)
        {
            tong_le += mang[i]
        }
        
        
    }
    printf("--Tong la %d", tong);
    printf("--Tong chan la %d", tong_chan);
    printf("--Tong le la %d", tong_le);
}


void main() {
    int mang[n];
    NhapMang(mang);
    InMang(mang);
    SapXepTangDan(mang);
    InMang(mang);

    SapXepGiamDan(mang);
    InMang(mang);
}