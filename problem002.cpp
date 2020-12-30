#include <iostream>

int main() {
    int a = 0, b = 1, c;
    int sum = 0;
    while (a <= 4000000) {
        if (a % 2 == 0) {
            sum += a;
        }
        c = a + b;
        a = b;
        b = c;
    }
    std::cout << sum << std::endl;
}