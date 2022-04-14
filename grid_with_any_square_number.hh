//
// Created by tedac on 14/04/2022.
//

#ifndef SUDOKU_GRID_WITH_ANY_SQUARE_NUMBER_HH
#define SUDOKU_GRID_WITH_ANY_SQUARE_NUMBER_HH

#include <vector>
#include <iostream>
#include <math.h>

/* Returns the possible numbers that can be placed in the given cell */
std::vector<int> matching_number(std::vector<std::vector<int>> grid, int row, int col);

/* Returns the next empty cell in the grid */
std::pair<int, int> next_empty_cell(std::vector<std::vector<int>> grid);

/* Prints the grid */
void pretty_print_grid(std::vector<std::vector<int>> grid);

/* Solves the grid */
bool resolve(std::vector<std::vector<int>> grid);


#endif//SUDOKU_GRID_WITH_ANY_SQUARE_NUMBER_HH
