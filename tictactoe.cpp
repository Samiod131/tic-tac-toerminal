#include <iostream>
#include <array>

#include "include/inputs.hpp"
#include "include/printings.hpp"
#include "include/grid_checks.hpp"


void run_new_game(){
    bool game_over = false;

    std::array<std::array<int, 3>, 3> grid = {{{0,0,0}, {0,0,0}, {0,0,0}}};
    print_grid(grid);

    int current_player = 1;
    while (!game_over){
        print_text("Player "+std::to_string(current_player)+"\'s turn:");
        std::array<int, 2> position = get_position_play(grid);
        grid[position[0]][position[1]] = current_player;
        print_grid(grid);

        if (check_win(grid)) {
            print_player_win(current_player);
            game_over=true;
        } else if (check_full(grid)) {
            print_draw();
            game_over=true;
        };

        if (current_player==1) {
            current_player=2;
        } else if (current_player==2) {
            current_player=1;
        };
    };
}

int main() {
    print_text(get_ascii_header());
    print_text(get_description());

    bool continue_program = true;
    while (continue_program) {
        run_new_game();
        continue_program = get_continue();

    }
    

    return 0;
}

