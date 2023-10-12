#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    int id;
    float diem;
} sv[50];

int in_dex = 0;

int SoSanh(const void* a, const void* b) {
    const struct SinhVien* sv1 = (const struct SinhVien*)a;
    const struct SinhVien* sv2 = (const struct SinhVien*)b;
    return (sv2->diem > sv1->diem) - (sv2->diem < sv1->diem);
}

EMSCRIPTEN_KEEPALIVE
void ThemSinhVien(int id, float diem) {
    sv[in_dex].id = id;
    sv[in_dex].diem = diem;
    in_dex++;
}

EMSCRIPTEN_KEEPALIVE
void SapXepSinhVien() {
    qsort(sv, 50, sizeof(struct SinhVien), SoSanh);

    for (int i = 0; i < in_dex; i++) {

        // Chuyển các giá trị sang JavaScript thông qua hàm đặt sẵn
        char js_code[200];  // Đảm bảo bạn có đủ không gian cho chuỗi
        sprintf(js_code, "addToArray(%d, %f);", sv[i].id, sv[i].diem);
        emscripten_run_script(js_code);
    }
}