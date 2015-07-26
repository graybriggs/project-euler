#include <iostream>

long sum_of_squares(int num) {
    
    long sum = 0;
    
    for (int i = 1; i <= num; ++i) {
        sum += i * i;
    }
    return sum;
}

long square_of_sum(int num) {
    
    long sum = 0;
    
    for (int i = 1; i <= num; ++i) {
        sum += i;
    }
    
    return sum * sum;
}

int main() {
    
    const int VALUE = 100;
    
    std::cout << "Result: " << square_of_sum(VALUE) - sum_of_squares(VALUE) << std::endl;
    
}
