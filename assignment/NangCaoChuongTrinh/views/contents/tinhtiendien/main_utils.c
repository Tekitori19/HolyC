#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
float TinhTienDien(int so_dien) {
    float tien;

    const int gia_dien_bac1 = 1678;
    const int gia_dien_bac2 = 1734;
    const int gia_dien_bac3 = 2014;
    const int gia_dien_bac4 = 2536;
    const int gia_dien_bac5 = 2834;
    const int gia_dien_bac6 = 2927;

    if (so_dien <= 50) {
        tien = so_dien*gia_dien_bac1;
        return tien;
    }
    else if (so_dien <= 100) {
        tien = (50*gia_dien_bac1) + (so_dien - 50) * gia_dien_bac2;
        tien = tien + (tien * 8)/100;
        return tien;
    }
    else if (so_dien <= 200) {
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (so_dien - 100) * gia_dien_bac3;
        tien = tien + (tien * 8)/100;
        return tien;
    }
    else if (so_dien <= 300) {
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (so_dien - 200) * gia_dien_bac4;
        tien = tien + (tien * 8)/100;
        return tien;
    }
    else if (so_dien <= 400) { 
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (100 * gia_dien_bac4) + (so_dien - 300) * gia_dien_bac5;
        tien = tien + (tien * 8)/100;
        return tien;
    }
    else{
        tien = (50 * gia_dien_bac1) + (50 * gia_dien_bac2) + (100 * gia_dien_bac3) + (100 * gia_dien_bac4) + (100 * gia_dien_bac5) + (so_dien - 400) * gia_dien_bac6;
        tien = tien + (tien * 8)/100;
        return tien;
    }
}