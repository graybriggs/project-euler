
#include <iostream>


long fib() {

    long first = 1;
    long second = 2;
    long sum = second; // first even number

    while (second < 4000000) {
        long next = first + second;
        if (next % 2 == 0)
            sum += next;
        first = second;
        second = next;
    }
    return sum;
}

int main() {
    std::cout << "Sum: " << fib() << std::endl;
}
