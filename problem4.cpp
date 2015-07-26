https://projecteuler.net/problem=4

#include <iostream>
#include <stack>
#include <string>


bool is_palin(std::string str) {
    
    std::size_t len = str.length();

    std::stack<char> stk;

    unsigned i;

    for (i = 0; i < len / 2; ++i)
        stk.push(str[i]);

    if (str.length() % 2 != 0)
        ++i;

    for ( ; i < len; ++i) {

        if (stk.top() != str[i])
            return false;

        stk.pop();
    }

    return true;
}

long max = 0;

int main() {
    
    for (int i = 100; i < 999; ++i) {
        for (int j = 100; j < 999; ++j) {
            if (is_palin(std::to_string(j * i))) {
                if (j * i > max)
                    max = j * i;
            }
        }
    }

    std::cout << "Largest palindrome: " << max << std::endl;
}



