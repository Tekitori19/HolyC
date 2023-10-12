#include <time.h>
#include <stdlib.h>
#include <emscripten.h>


EMSCRIPTEN_KEEPALIVE
int FpolyLott(int so_1, int so_2) {
    int tong = 0;
    int ket_qua[2];
    srand(time(0));

    for (int i = 0; i < 2; i++)
    {
        int r = 1 + rand() % 15; // 1 -> 15
        ket_qua[i] = r;
    }
    for (int i = 0; i < 2; i++)
    {
        if (so_1 == ket_qua[i])
        {
            tong++;
        }
    
        if (so_2 == ket_qua[i])
        {
            tong++;
        }
        
    }
    
    
    return tong;
}