#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Để sử dụng hàm isalpha

void DemNguyenAmVaPhuAm() {
    printf("Xin moi nhap vao chuoi: ");
    int i = 0, n = 0, p = 0;
    char s[100];
    fgets(s, sizeof(s), stdin);
    
    size_t do_dai_chuoi = strlen(s);

    if (do_dai_chuoi > 0 && s[do_dai_chuoi-1] == '\n')
    {
        s[do_dai_chuoi-1] = '\0';
    }
    

    while (s[i] != '\0')
    {
        if (isalpha(s[i])) // dùng hàm isalpha để kiểm tra chữ cái trong chuỗi (bỏ khoảng trống)
        {
            if(s[i]=='e' || s[i]=='u' || s[i]=='o' || s[i]=='a' || s[i]=='i' ||
            s[i]=='A' || s[i]=='I' || s[i]=='E' || s[i]=='U' || s[i]=='O'){
                n++;
            }else{
                p++;
            }
            // printf("%d\n", s[i]);
        }
        i++;
    }
    
    printf("Chuoi '%s' co chua: %d nguyen am va %d phu am.\n",s,n,p);
}

int DangNhap(char *user, int pass) {
    char userSys[] = "admin";
    int passSys = 12345;
    if (strcmp(user, userSys)==0 && pass == passSys)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}


void main() {
    DemNguyenAmVaPhuAm();
    
    // ĐĂNG NHẬP
    {
        char user[100];
        int password;
        
        printf("\nMoi nhap ten dang nhap: ");
        fgets(user, sizeof(user), stdin);
        printf("Moi nhap password: ");
        scanf("%d", &password);

        size_t do_dai_chuoi = strlen(user);

        if (do_dai_chuoi > 0 && user[do_dai_chuoi-1] == '\n')
        {
            user[do_dai_chuoi-1] = '\0';
        }

        int err = DangNhap(&user, password);
        if (err == 1)
        {
            printf("Dang nhap thanh cong\n");
        }
        else
        {
            printf("ERR: Dang nhap khong thanh cong\n");
            
        }
        
    }
    // ĐĂNG NHẬP

    // SẮP XẾP CHUỖI THEO CHỮ CÁI
    {
        char s[5][20];
        printf("Nhap 5 chuoi bat ki:\n");
        for (int i = 0; i < 5; i++)
        {
            gets(s[i]);
        }

        for (int i = 1; i < 5; i++)
        {
            for (int j = 1; j < 5; j++)
            {
                if (strcmp(s[j-1], s[i]) > 0)
                {
                    char temp[20];
                    strcpy(temp, s[j-1]);
                    strcpy(s[j-1], s[i]);
                    strcpy(s[i], temp);
                }
                
            }
            
        }
        printf("\nSau khi sap xep thu tu cua cac chuoi:");
        for(int i = 0; i < 5; i++){
            printf("\n%s\n",s[i]);
        }
        
        
    }
    // SẮP XẾP CHUỖI THEO CHỮ CÁI
}