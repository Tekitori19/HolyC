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

void InVaNhapGiaTri(char *text, int *so) {
    printf(text);
    scanf("%d",so);
}

void TongCacSoChiaHetCho3() {
    int phan_tu;
    InVaNhapGiaTriKhongAm("Moi nhap so phan tu cua mang: ", &phan_tu);
    int mang[phan_tu];

    for (int i = 0; i < phan_tu; i++)
    {
        int gia_tri;
        printf("Phan tu so %d ", i+1);
        InVaNhapGiaTri("moi nhap gia tri: ", &gia_tri);
        mang[i] = gia_tri;
    }

    float tong = 0;
    float trung_binh;
    int count = 0;
    
    for (int i = 0; i < phan_tu; i++)
    {
        if (mang[i] % 3 == 0)
        {
            tong += mang[i];
            count++;
        }
    }
    
    if (count == 0)
    {
        printf("mang khong co so chia het cho 3");
        return;
    }
    
    trung_binh = tong/count;
    printf("trung binh cong cac so chia het cho 3 trong mang la: %.2f\n", trung_binh);

}

void MinMaxTrongMang() {
    int phan_tu;
    InVaNhapGiaTriKhongAm("Moi nhap so phan tu cua mang: ", &phan_tu);
    int mang[phan_tu];

    for (int i = 0; i < phan_tu; i++)
    {
        int gia_tri;
        printf("Phan tu so %d ", i+1);
        InVaNhapGiaTri("moi nhap gia tri: ", &gia_tri);
        mang[i] = gia_tri;
    }

    int min = mang[0];
    int max = mang[0];
    
    for (int i = 0; i < phan_tu; i++)
    {
        if (mang[i] > max)
        {
            max = mang[i];
        }
        if (mang[i] < min)
        {
            min = mang[i];
        }
    }

    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);   
}

void HoanVi(int *so_1, int *so_2) {
    int temp;
    temp = *so_1;
    *so_1 = *so_2;
    *so_2 = temp;
}

void SapXepMang() {
    int phan_tu;
    InVaNhapGiaTriKhongAm("Moi nhap so phan tu cua mang: ", &phan_tu);
    int mang[phan_tu];

    for (int i = 0; i < phan_tu; i++)
    {
        int gia_tri;
        printf("Phan tu so %d ", i+1);
        InVaNhapGiaTri("moi nhap gia tri: ", &gia_tri);
        mang[i] = gia_tri;
    }

    for (int i = 0; i < phan_tu -1; i++)
    {
        for (int j = i + 1; j < phan_tu; j++)
        {
            if (mang[i] > mang[j])
            {
                HoanVi(&mang[i], &mang[j]);
            }   
        }   
    }

    for (int i = 0; i < phan_tu; i++) {
        printf("Vi tri thu mang[%d] la : %d \n",i,mang[i]);
    }    
}

void BinhPhuongCacPhanTuTrongMang() {
    int n, m;
    InVaNhapGiaTriKhongAm("Moi nhap so phan tu cua mang cha: ", &n);
    InVaNhapGiaTriKhongAm("Moi nhap so phan tu cua mang con: ", &m);
    int mang[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {    
            int gia_tri;
            printf("Phan tu so [%d][%d] ", i, j);
            InVaNhapGiaTri("moi nhap gia tri: ", &gia_tri);
            mang[i][j] = gia_tri;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {    
            int binh_phuong = mang[i][j]*mang[i][j];
            printf("Phan tu so [%d][%d] sau binh phuong la: %d\n", i, j, binh_phuong);
        }
    }
}

void main() {
    TongCacSoChiaHetCho3();
    MinMaxTrongMang();
    SapXepMang();
    BinhPhuongCacPhanTuTrongMang();
}