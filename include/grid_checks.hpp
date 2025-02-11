#pragma once

#include <iostream>
#include <array>

bool check_rows_win(std::array<std::array<int, 3>, 3> grid);

bool check_columns_win(std::array<std::array<int, 3>, 3> grid);

bool check_diags_win(std::array<std::array<int, 3>, 3> grid);

bool check_win(std::array<std::array<int, 3>, 3> grid);

bool check_full(std::array<std::array<int, 3>, 3> grid);