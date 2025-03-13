#include "../include/players.hpp"

#include <array>
#include <iostream>
#include <random>
#include <vector>

Player::Player(int player_id, std::string player_name) {
    set_id(player_id);
    set_name(player_name);
};

std::string Player::get_name() { return name; };
void Player::set_name(std::string player_name) { name = player_name; };

int Player::get_id() { return id; };
void Player::set_id(int player_id) { id = player_id; };

HumanPlayer::HumanPlayer(int player_id, std::string player_name) : Player(player_id, player_name) {
    set_name(player_name.empty() ? get_default_name() : player_name);
};
std::string HumanPlayer::get_default_name() { return "Player_" + std::to_string(get_id()); };
std::array<int, 2> HumanPlayer::play_move(std::array<std::array<int, 3>, 3> grid) {
    return get_position_play(grid);
};

EasyBotPlayer::EasyBotPlayer(int player_id, std::string player_name)
    : Player(player_id, player_name) {
    set_name(player_name.empty() ? get_default_name() : player_name);
};
std::string EasyBotPlayer::get_default_name() { return "Easy_Bot"; };
std::array<int, 2> EasyBotPlayer::get_random_move() {
    std::array<int, 2> coordinates;
    coordinates[0] = (int)(std::rand() % 3);
    coordinates[1] = (int)(std::rand() % 3);
    return coordinates;
};
std::array<int, 2> EasyBotPlayer::play_move(std::array<std::array<int, 3>, 3> grid) {
    bool valid = false;
    std::array<int, 2> move = get_random_move();
    while (!valid) {
        if (!grid[move[0]][move[1]]) {
            valid = true;
        } else {
            move = get_random_move();
        };
    }
    return move;
};
