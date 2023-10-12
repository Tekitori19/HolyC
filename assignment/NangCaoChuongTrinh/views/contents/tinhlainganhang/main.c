#include <emscripten.h>
#include <stdio.h>
// Khai báo hàm VayNganHangTraGop
EMSCRIPTEN_KEEPALIVE
void VayNganHangTraGop(float tien_can_vay) {
    const float lai_suat = 0.05;
    const int ky_han = 12;
    float tien = tien_can_vay;
    float goc_phai_tra = tien / ky_han;

    for (int i = 0; i < ky_han; i++) {
        char lai_phai_tra_buff[15];
        char tien_phai_tra_buff[15];
        char tien_con_lai_buff[15];
        float lai_phai_tra = tien * lai_suat;
        float tien_phai_tra = lai_phai_tra + goc_phai_tra;
        tien -= goc_phai_tra;

        // Chuyển các giá trị sang JavaScript thông qua hàm đặt sẵn
        char js_code[200];  // Đảm bảo bạn có đủ không gian cho chuỗi
        sprintf(js_code, "addToResultArray(%f, %f, %f);", lai_phai_tra, tien_phai_tra, tien);
        emscripten_run_script(js_code);
    }
}
