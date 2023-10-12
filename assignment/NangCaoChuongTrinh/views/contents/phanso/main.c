#include <emscripten.h>
#include <stdio.h>

EMSCRIPTEN_KEEPALIVE
void PhanSo(int tu_1, int mau_1, int tu_2, int mau_2) {
    int x1,x2,x3,x4,y1,y2,y3,y4;
    int rut_gon;

    x1 = (tu_1*mau_2)+(mau_1*tu_2);
	y1 = mau_1*mau_2;
	x2 = (tu_1*mau_2)-(mau_1*tu_2);
	y2 = mau_1*mau_2;
	x3 = tu_1*tu_2;
	y3 = mau_1*mau_2;
	x4 = tu_1*mau_2;
	y4 = mau_1*tu_2;

    for (int i = 1; i <= x1 && i <= y1; i++)
    {
        if (x1 % i == 0 && y1 % i ==0)
        {
            rut_gon = i;
        }
        
    }
    char js_code[200];  // Đảm bảo bạn có đủ không gian cho chuỗi
    sprintf(js_code, "Print(%d, %d,%d, %d,%d, %d,%d, %d, %d);", x1, y1, x2, y2, x3, y3, x4, y4, rut_gon);
    emscripten_run_script(js_code);
    

}