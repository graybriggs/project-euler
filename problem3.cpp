
#include <iostream>
#include <vector>

std::vector<long> prime_factors;

void calculate_factors(long num) {
    
    while (num > 1) {
        
        for (long div = 2; div <= num; ++div) {
            if (num % div == 0) {
                num = num / div;
                prime_factors.push_back(div);
                break;
            }
        }
    }
}


int main() {
    calculate_factors(600851475143);
    for (auto a : prime_factors)
        std::cout << a << " " << std::endl;
}
