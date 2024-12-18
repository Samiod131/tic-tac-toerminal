// Your First C++ Program

#include <iostream>
#include "headers/printings.hpp"


void run_new_game(){
    bool player1_win = false;
    bool player2_win = false;
    bool draw = false;

    int grid[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    print_grid(grid);

}

bool get_continue(){

    std::cout >> "Do you wnat to start a new game ? [y/n]";

}


int main() {
    print_text(get_ascii_header());
    print_text(get_description());

    bool close_program = false;

    while (!close_program) {

        std::cout >> "Do you wnat to start a new game ? [y/n]"

    }
    run_new_game();

    return 0;
}

