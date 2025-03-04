#pragma once

#include <iostream>
#include <array>
#include <memory>

#include "../include/board.hpp"
#include "../include/players.hpp"


class GameSetup{
    private:
        Board game_board = Board();
        std::shared_ptr<Player> players [2];
        int player_id;
        int starting_player_id;
        int winner;
        bool game_over;
    public: 
        GameSetup(std::shared_ptr<Player>& player_1, std::shared_ptr<Player>& player_2);
        void run();
        void reset_game();
        void set_rematch();
        void play_new_game();
};

