#include <emscripten.h>

EMSCRIPTEN_KEEPALIVE
void DoiTien(int *arr ,int tien_can_doi) {
    int tien = tien_can_doi;

    int to_tien[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int first = 0;

    for (int i = 0; i < 9; i++)
    {
        if (tien >= to_tien[i])
        {
            if (first == 0 && tien == to_tien[i])
            {
                first+=1;
                continue;
            }
            
            arr[i] = tien/to_tien[i];
            tien %= to_tien[i];
            first+=1;
        }
        
    }
    
}