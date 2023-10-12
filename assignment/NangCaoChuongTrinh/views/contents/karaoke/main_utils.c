#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
float TinhTienKaraoke(int gio_bat_dau,int gio_ket_thuc) {
    const int GIA3GIODAU = 150000;
    const float GIASAU4GIO = GIA3GIODAU - (GIA3GIODAU * 30)/100;
    int so_gio_hat = gio_ket_thuc - gio_bat_dau;
    float tien;

    if (so_gio_hat < 4)
    {
        tien = GIA3GIODAU * so_gio_hat;
    } else
    {
        tien = GIA3GIODAU * 3 + GIASAU4GIO * (so_gio_hat - 3);
    }
    
    if (gio_bat_dau >= 14 && gio_bat_dau <= 17)
    {
        tien = tien - (tien * 10)/100;
    }
    
    return tien;
    
}