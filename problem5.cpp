
#include <iostream>

long divide() {

    long num = 1;

    for (;;) {
        ++num;
        for (int div = 1; div <= 20; ++div) {
            if (num % div != 0) {
                break;
        }
        else if (div == 20 && num % div == 0)
            return num;
        }
    }
}

int main() {
    std::cout << divide() << std::endl;
}
