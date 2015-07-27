
#include <iostream>


int collatz_sequence(unsigned num) {
    
    int seq_len = 0;
    
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        }
        else {
            num = 3 * num + 1;
        }
        ++seq_len;
    }
    return seq_len + 1;
}


int main() {
    
    int max_seq = 0;
    unsigned longest = 0;
    
    for (unsigned i = 1; i <= 1000000; ++i) {
        int seq = collatz_sequence(i);
        if (seq > max_seq) {
            max_seq = seq;
            longest = i;
        }
    }
    
    std::cout << "Longest Collatz chain: " << max_seq << " for starting value: " << longest << std::endl;
}
