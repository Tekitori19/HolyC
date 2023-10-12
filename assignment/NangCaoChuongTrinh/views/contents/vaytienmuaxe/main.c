#include <emscripten.h>
#include <stdio.h>
// Khai báo hàm VayNganHangTraGop
EMSCRIPTEN_KEEPALIVE
void VayTienMuaXe(float phan_tram_vay) {
    const float lai_suat = 0.072/12;
    const int ky_han = 24*12;
    float tien = 500000;
    float tra_truoc_const = (1.0 - phan_tram_vay) * tien;
    tien -= tra_truoc_const;
    float goc_phai_tra = tien / ky_han;

    for (int i = 0; i < ky_han; i++) {
        char lai_phai_tra_buff[15];
        char tien_phai_tra_buff[15];
        char tien_con_lai_buff[15];
        float lai_phai_tra = tien * lai_suat;
        float tien_phai_tra = lai_phai_tra + goc_phai_tra;
        tien -= goc_phai_tra;
        float tra_truoc = tra_truoc_const;
        
        // Chuyển các giá trị sang JavaScript thông qua hàm đặt sẵn
        char js_code[200];  // Đảm bảo bạn có đủ không gian cho chuỗi
        sprintf(js_code, "addToResultArray(%f, %f, %f, %f, %f);", lai_phai_tra, tien_phai_tra, tien, goc_phai_tra, tra_truoc);
        emscripten_run_script(js_code);
    }
}

