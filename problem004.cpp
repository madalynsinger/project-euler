#include <iostream>

bool is_palindrome(long n);

int main()
{
    auto p = 0L;
    for (auto n = 999L; n*n > p; --n) {
        auto q = 0L;
        for (auto m = n; m >= 100 && (q = n*m) > p; --m) {
            std::cout << m << " " << n << std::endl;
            if (is_palindrome(q)) {
                p = q;
            }
        }
    }

    std::cout << p << std::endl;
    return 0;
}

bool is_palindrome(long n)
{
    auto m = n, r = 0L;
    while (m != 0) {
        r = r * 10 + m % 10;
        m /= 10;
    }
    return r == n;
}