#include <iostream>

int main() {
    static const int LIM = 1000;

    int sum = 0;
    for (int i = 1; i < LIM; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    std::cout << sum << std::endl;
}