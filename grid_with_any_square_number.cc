//
// Created by tedac on 14/04/2022.
//

#include "grid_with_any_square_number.hh"

/* Returns the possible numbers that can be placed in the given cell */
std::vector<int> matching_number(std::vector<std::vector<int>> grid, int row, int col) {

    std::vector<int> numbers;

    // Create a vector of all the numbers in the grid //
    for (int num = 1; num < grid.size() + 1; num++) {
        numbers.push_back(num);
    }

    // Verification if the cell is not empty //
    if (grid[row][col] != 0) {
        std::vector<int> only_one_number;
        only_one_number.push_back(grid[row][col]);
        return only_one_number;
    }

    /* Removing all the numbers that can't be placed in the cell from the numbers vector */

    // Row
    for (int c = 0; c < grid.size(); c++) {
        if (grid[row][c] != 0) {
            auto pos = std::find(numbers.begin(), numbers.end(), grid[row][c]);
            if (pos != numbers.end()) {
                numbers.erase(pos);
            }
        }
    }

    // Column
    for (int r = 0; r < grid.size(); r++) {
        if (grid[r][col] != 0) {
            auto pos = std::find(numbers.begin(), numbers.end(), grid[r][col]);
            if (pos != numbers.end()) {
                numbers.erase(pos);
            }
        }
    }

    // Square
    int mod = floor(sqrt(grid.size()));
    int square_row = row - (row % mod);
    int square_col = col - (col % mod);
    for (int r = square_row; r < square_row + mod; r++) {
        for (int c = square_col; c < square_col + mod; c++) {
            if (grid[r][c] != 0) {
                auto pos = std::find(numbers.begin(), numbers.end(), grid[r][c]);
                if (pos != numbers.end()) {
                    numbers.erase(pos);
                }
            }
        }
    }

    return numbers;
}

/* Returns the next empty cell in the grid */
std::pair<int, int> next_empty_cell(std::vector<std::vector<int>> grid) {

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid.size(); c++) {

            if (grid[r][c] == 0) {
                return std::make_pair(r, c);
            }

        }
    }
    return std::make_pair(-1, -1);
}

/* Prints the grid */
void pretty_print_grid(std::vector<std::vector<int>> grid) {

    int mod = floor(sqrt(grid.size()));

    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid.size(); c++) {

            if (grid[r][c] < 10 && grid.size() > 10) {
                std::cout << "0";
            }
            std::cout << grid[r][c];

            if (c % mod == mod - 1 && c != grid.size() - 1) {
                std::cout << " | ";
            }
            else {
                std::cout << " ";
            }
        }

        std::cout << std::endl;

        if (r % mod == mod - 1 && r != grid.size() - 1) {
            for (int i = 0; i < mod; i++) {
                for (int j = 0; j < mod; j++) {
                    if (grid.size() > 10) {
                        std::cout << "-";
                    }
                    std::cout << "- ";
                }
                if (i != mod - 1) {
                    std::cout << "+ ";
                }
            }
            std::cout << std::endl;
        }
    }
}

/* Solves the grid */
bool resolve(std::vector<std::vector<int>> grid) {

    // Verification if the size of the grid is a square number
    if (ceil(sqrt(grid.size())) != floor(sqrt(grid.size()))) {
        std::cerr << "Error : The grid is not a square number" << std::endl;
        return false;
    }

    auto empty = next_empty_cell(grid);
    int row = empty.first;
    int col = empty.second;

    // If the grid is full, we are done
    if (row == -1 && col == -1) {
        std::cout << "Grid is solved!" << std::endl;
        pretty_print_grid(grid);
        return true;
    }

    // If the cell is empty, we can place a number in it
    std::vector<int> numbers = matching_number(grid, row, col);

    for (int n : numbers) {
        grid[row][col] = n;
        if (resolve(grid)) {
            return true;
        }
        else {
            grid[row][col] = 0;
        }
    }
    return false;
}