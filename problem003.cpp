#include <iostream>

long long largest_prime_factor(long long n);

int main()
{
    static auto const N = 600851475143LL;
    std::cout << largest_prime_factor(N) << std::endl;
    return 0;
}

long long largest_prime_factor(long long n)
{
    for (auto p = 2LL; p * p <= n;) {
        if (n % p == 0) n /= p;
        else ++p;
    }
    return n;
}
