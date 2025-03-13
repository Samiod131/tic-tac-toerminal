#include "../include/game_setup.hpp"

#include <array>
#include <iostream>
#include <memory>

#include "../include/board.hpp"
#include "../include/inputs.hpp"
#include "../include/players.hpp"
#include "../include/printings.hpp"

GameSetup::GameSetup(std::shared_ptr<Player>& player_1, std::shared_ptr<Player>& player_2) {
    players[0] = player_1;
    players[1] = player_2;
    starting_player_id = 1;
};

void GameSetup::run() {
    reset_game();
    play_new_game();
    while (get_rematch()) {
        set_rematch();
        play_new_game();
    }
};

void GameSetup::reset_game() {
    game_board.reset_grid();
    player_id = starting_player_id;
    winner = 0;
    game_over = false;
}


void GameSetup::set_rematch() {
    if (game_over) {
        starting_player_id = starting_player_id % 2 + 1;  // alternates between 1 and 2
        reset_game();
    }
};

void GameSetup::play_new_game() {
    reset_game();
    while (!game_over) {
        reset_terminal();
        print_grid(game_board.get_grid());
        print_text(players[player_id - 1]->get_name() + "\'s turn:");
        game_board.set_value(players[player_id - 1]->play_move(game_board.get_grid()),
                             players[player_id - 1]->get_id());

        winner = game_board.check_win();
        if (winner) {
            print_player_win(players[winner - 1]->get_name());
            game_over = true;
        } else if (game_board.check_full()) {
            print_draw();
            game_over = true;
        };

        player_id = player_id % 2 + 1;  // alternates between 1 and 2
    };
};
