#pragma once

#include <array>
#include <iostream>

std::string get_user_input();

bool get_continue(void);

bool get_rematch(void);

bool get_yorn_input(void);

std::array<int, 2> get_position_play(std::array<std::array<int, 3>, 3> grid);