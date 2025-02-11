#pragma once

#include <iostream>
#include <array>


std::string get_ascii_header(void);

std::string get_description(void);

void print_text(std::string some_text);

char get_grid_value_symbol(int value);

void print_grid(std::array<std::array<int, 3>, 3> grid);

void print_player_win(int player_id);

void print_draw();