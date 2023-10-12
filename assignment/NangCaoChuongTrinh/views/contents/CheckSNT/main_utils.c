#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
int XacDinhSoNguyenTo(int x) {
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
           
    }
    return 1;
}

EMSCRIPTEN_KEEPALIVE
int SoChinhPhuong(int x) {
    for (int i = 0; i < x; i++)
    {
        if (i*i == x)
        {
            return 1;
        }   
    }
    return 0;
}