#pragma once

#include <iostream>
#include <array>
#include <random>
#include <vector>

#include "../include/inputs.hpp"


class Player{
    private:
        std::string name;
        int id;
    public:
        Player(int player_id, std::string player_name);
        std::string get_name();
        void set_name(std::string player_name);

        int get_id();
        void set_id(int player_id);
        virtual std::array<int, 2> play_move(std::array<std::array<int, 3>, 3> grid) = 0;
};


class HumanPlayer : public Player {
    private:
        std::string get_default_name();
    public:
        HumanPlayer(int player_id, std::string player_name="");
        std::array<int, 2> play_move(std::array<std::array<int, 3>, 3> grid);
};


class EasyBotPlayer : public Player {
    private:
        std::string get_default_name();
        std::array<int, 2> get_random_move();
    public:
        EasyBotPlayer(int player_id, std::string player_name="");
        std::array<int, 2> play_move(std::array<std::array<int, 3>, 3> grid);
};