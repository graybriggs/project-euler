
#include <iostream>

int main() {
    
    for (int a = 1; a < 1000; ++a) {
        for (int b = a + 1; b < 1000; ++b) {
            for (int c = b + 1; c < 1000; ++c) {
                if ((a * a + b * b - c * c == 0)
                    && (a + b + c == 1000)) {
                    std::cout << a * b * c << std::endl;
                    break;
                }
            }
        }
    }
}
