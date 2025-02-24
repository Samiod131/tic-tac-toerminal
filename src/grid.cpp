#include <iostream>
#include <array>
#include <vector>

#include "../include/grid.hpp"


int Board::check_rows_win(){
    for (int i = 0; i < 3; i++) {
        if (grid[0][i]!=0) {
            if (grid[0][i]==grid[1][i] && grid[0][i]==grid[2][i]){
                return grid[0][i];
            }
        }
    }
    return 0;
}

int Board::check_columns_win(){
    for (int i = 0; i < 3; i++) {
            if (grid[i][0]!=0) {
                if (grid[i][0]==grid[i][1] && grid[i][0]==grid[i][2]){
                    return grid[i][0];
                }
            }
        }
    return 0;
}

int Board::check_diags_win(){
    if (grid[0][0]!=0) {
            if (grid[0][0]==grid[1][1] && grid[0][0]==grid[2][2]){
                return grid[0][0];
            }
        }
    if (grid[2][0]!=0) {
            if (grid[2][0]==grid[1][1] && grid[2][0]==grid[0][2]){
                return grid[2][0];
            }
        }
    return 0;
}

void Board::init_grid(){
    grid = {{{0,0,0}, {0,0,0}, {0,0,0}}};
}

Board::Board(){
    init_grid();
}

int Board::check_win(){
    int winner = 0;
    winner = check_rows_win();
    if (!winner){
        winner = check_columns_win();
    };
    if (!winner){
        winner = check_diags_win();
    };
    return winner;
};

bool Board::check_full(){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j]==0) {
                return false;
            }
        }
    }
    return true;
};

void Board::set_value(std::array<int, 2> position, int player_id){
    grid[position[0]][position[1]] = player_id;
}

int Board::get_value(std::array<int, 2> position){
    return grid[position[0]][position[1]];
}

void Board::set_grid(std::array<std::array<int, 3>, 3> g) {grid = g;}

std::array<std::array<int, 3>, 3> Board::get_grid() {return grid;}


