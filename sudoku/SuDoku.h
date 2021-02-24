#ifndef SUDOKU_H
#define SUDOKU_H

#include <array>
#include <iostream>
#include <set>
#include <stack>
#include <queue>

class SuDoku
{
public:
    SuDoku() {};
    std::istream& read(std::istream&);
    int solve();

private:
    using digit_t = char;
    using cell_t = std::set<digit_t>;
    using grid_t = std::array<std::array<cell_t, 9>, 9>;
    using coord_t = grid_t::size_type;

    struct fill_t {
        coord_t i, j;
        digit_t n;
    };

    struct guess_t {
        grid_t old_grid;
        fill_t fill;
    };

    grid_t grid;
    std::stack<guess_t> guesses;
    std::queue<fill_t> fills;
    int num_empty = 0;

    std::ostream& print(std::ostream&) const;
};

#endif