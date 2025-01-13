#include <iostream>
#include <array>


bool check_rows_win(std::array<std::array<int, 3>, 3> grid){
    for (int i = 0; i < 3; i++) {
        if (grid[i][0]!=0) {
            if (grid[i][0]==grid[i][1] & grid[i][0]==grid[i][2]){
                return true;
            }
        }
        if (grid[0][i]!=0) {
            if (grid[0][i]==grid[1][i] & grid[0][i]==grid[2][i]){
                return true;
            }
        }
    }
    return false;
}

bool check_columns_win(std::array<std::array<int, 3>, 3> grid){
    for (int i = 0; i < 3; i++) {
        if (grid[0][i]!=0) {
            if (grid[0][i]==grid[1][i] & grid[0][i]==grid[2][i]){
                return true;
            }
        }
    }
    return false;
}

bool check_diags_win(std::array<std::array<int, 3>, 3> grid){
    if (grid[0][0]!=0) {
            if (grid[0][0]==grid[1][1] & grid[0][0]==grid[2][2]){
                return true;
            }
        }
    if (grid[2][0]!=0) {
            if (grid[2][0]==grid[1][1] & grid[2][0]==grid[0][2]){
                return true;
            }
        }
    return false;
}

bool check_win(std::array<std::array<int, 3>, 3> grid){
    if (check_rows_win(grid) | check_columns_win(grid) | check_diags_win(grid)){
        return true;
    } else {
        return false;
    }
}


bool check_full(std::array<std::array<int, 3>, 3> grid){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j]==0) {
                return false;
            }
        }
    }
    return true;
};