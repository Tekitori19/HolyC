#include <stdio.h>
#include <stdlib.h>

int PHANTU;

void NhapSoNguyen(char *van_mau, int *so) {
    int flag = 0;

    // int test;
    // printf("test");
    // scanf("%d",&test);
    // printf("%d", test);

    do
    {
        if (flag != 0)
        {
            printf("!!!Nhap sai vui long nhap lai!!!\n");
        }
        
        printf(van_mau);
        scanf("%d", so);

        while (getchar() != '\n'); // de xoa dau xuong dong tranh loi vong lap vo han
        
        flag = 1;
    } while (*so>10 || *so<5);
    
}

void NhapMang(char *van_mau, int *arr) {
    for (int i = 0; i < PHANTU; i++)
    {
        printf("Vui long nhap so thu %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    
}

int CheckSNT(int so) {
    for (int i = 2; i < so; i++)
    {
        if (so % i == 0)
        {
            // printf("K phai snt");
            return 0; // false k phai la snt
        }   
    }

    // printf("la snt");
    return 1;
}

void main() {
   // Bai 1 - 2 -3
   {
        NhapSoNguyen("Moi nhap so nguyen: ",&PHANTU);
        if (PHANTU % 3 ==0)
        {
            printf("\tSo %d chia het cho 3\n", PHANTU);
        }
    }
   // Bai 1 - 2 -3

    // Bai 4 - 5 -6
   {
        int arr[PHANTU];
        NhapMang("Moi nhap mang: ",&arr);
        
        // for (int i = 0; i < PHANTU; i++)
        // {
        //     printf("%d\t", arr[i]);
        // }
    
        int err = CheckSNT(arr[1]);
        if (err == 0)
        {
            printf("\tphan tu thu 2 (%d) KHONG PHAI la so nguyen to\n", arr[1]);
        } else if ( err == 1)
        {
            printf("\tphan tu thu 2 (%d) la so nguyen to\n", arr[1]);
        }    
   }
   // Bai 4 - 5 -6
}