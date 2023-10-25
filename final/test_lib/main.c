#include <stdio.h>

// Khai báo nguyên mẫu của hàm đã xuất từ Rust
void greet_from_rust(void);

int main() {
    // Gọi hàm từ thư viện Rust
    greet_from_rust();
    return 0;
}