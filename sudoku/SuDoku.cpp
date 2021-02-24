#include <iostream>
#include <limits>
#include <string>
#include "SuDoku.h"

std::istream& SuDoku::read(std::istream& in)
{
    static cell_t const empty_cell { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    in.ignore(256, '\n');
    if (in) {
        for (coord_t i = 0; i != 9; ++i) {
            for (coord_t j = 0; j != 9; ++j) {
                digit_t const n = in.get() - '0';
                if (n == 0) {
                    grid[i][j] = empty_cell;
                    ++num_empty;
                } else {
                    grid[i][j] = cell_t{n};
                    fills.push(fill_t{i, j, n});
                }
            }
            in.get();
        }
    }

    return in;
}

int SuDoku::solve()
{
    std::cout << "Solving..." << std::endl;
    print(std::cout);
    return 0;
}

std::ostream& SuDoku::print(std::ostream& out) const
{
    for (coord_t i = 0; i != 9; ++i) {
        for (coord_t j = 0; j != 9; ++j) {
            cell_t const & cell = grid[i][j];
            if (cell.size() == 1) {
                auto digit = *cell.begin();
                out << digit;
            } else {
                out << '0';
            }
        }
        out << '\n';
    }
    out << std::endl;
}
