#include <iostream>
#include <cmath>

int main() {
    int64_t n, temp, res = 0;

    std::cout << "Enter a number?\t";
    std::cin >> n;
    int64_t tn = n;

    while (n != 0) {
        temp = n % 10;
        res = res * 10 + temp;
        n /= 10;
    }

    if (res == tn) {
        std::cout << "Palindrome!!!";
    } else{
        std::cout << "Not Palindrome!!!";
    }

}
