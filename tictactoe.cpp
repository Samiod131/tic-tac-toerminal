#include <iostream>
#include <array>
#include <stdexcept>

#include "include/inputs.hpp"
#include "include/printings.hpp"
#include "include/grid.hpp"


void run_new_game(){
    bool game_over = false;

    Board game_board = Board();
    print_grid(game_board.get_grid());

    int current_player = 1;
    int winner = 0;
    while (!game_over){
        print_text("Player "+std::to_string(current_player)+"\'s turn:");
        std::array<int, 2> position = get_position_play(game_board.get_grid());
        game_board.set_value(position, current_player);
        print_grid(game_board.get_grid());

        winner = game_board.check_win();
        if (winner) {
            print_player_win(winner);
            game_over=true;
        } else if (game_board.check_full()) {
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

