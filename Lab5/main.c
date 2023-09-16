#include <stdio.h>

int GiaTriLonNhat(int so_1, int so_2, int so_3) {
    if( so_1 > so_2) {
        if (so_1 > so_3)
        {
            return so_1;
        } else {
            return so_3;
        }
    } else if (so_2 > so_3)
    {
        return so_2;
    } else {
        return so_3;
    }
}

int CheckYear(int year) {
    if (year % 400 == 0)
    {
        return 1;
    }

    if (year % 4 == 0 && year % 100 != 0)
    {
        return 1;
    }
    
    return 0;
}

void HoanVi(int *so_1, int *so_2) {
    int temp;
    temp = *so_1;
    *so_1 = *so_2;
    *so_2 = temp;
}

void main() {
    // TÌM GIÁ TRỊ LỚN NHẤT
    {
        int so_1, so_2, so_3;
        printf("Nhap lan luot 3 so: ");
        scanf("%d %d %d", &so_1, &so_2, &so_3);
        
        int value = GiaTriLonNhat(so_1, so_2, so_3);
        printf("%d\n", value);
    }
    // TÌM GIÁ TRỊ LỚN NHẤT

    // TÍNH NĂM NHUẬN
    {
        int year;
        printf("Moi nhap nam: ");
        scanf("%d", &year);

        int value = CheckYear(year);
        if (value == 1)
        {
            printf("%d la nam nhuan\n", year);
        } else
        {
            printf("%d khong phai la nam nhuan\n", year);
        }
    }
    // TÍNH NĂM NHUẬN

    // HOÁN VỊ
    {
        int so_1, so_2;
        printf("Moi nhap 2 so: ");
        scanf("%d %d", &so_1, &so_2);
        
        HoanVi(&so_1, &so_2);
        printf("Sau khi hoan vi: so_1=%d so_2=%d\n", so_1, so_2);
    }
    // HOÁN VỊ
}