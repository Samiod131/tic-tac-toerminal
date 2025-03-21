#pragma once

#include <array>
#include <iostream>
#include <vector>

class Board {
   private:
    std::array<std::array<int, 3>, 3> grid;
    int check_rows_win();
    int check_columns_win();
    int check_diags_win();

   public:
    Board();
    int check_win();
    bool check_full();
    void set_value(std::array<int, 2> position, int player_id);
    int get_value(std::array<int, 2> position);
    void set_grid(std::array<std::array<int, 3>, 3> g);
    void reset_grid();
    std::array<std::array<int, 3>, 3> get_grid();
};
