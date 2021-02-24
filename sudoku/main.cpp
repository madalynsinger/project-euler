#include <iostream>
#include "SuDoku.h"

int main()
{
    int sum = 0;
    SuDoku puzzle;

    while (puzzle.read(std::cin)) {
        sum += puzzle.solve();
    }

    std::cout << sum << std::endl;
    return 0;
}
