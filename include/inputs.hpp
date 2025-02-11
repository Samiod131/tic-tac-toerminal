#pragma once

#include <iostream>
#include <array>

std::string get_user_input();

bool get_continue(void);

std::array<int, 2> get_position_play(std::array<std::array<int, 3>, 3> grid);