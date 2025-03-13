#include <array>
#include <iostream>

std::string get_ascii_header() {
    std::string header = R"(
                                                                                   
 _____  _           _____               _____                       _            _ 
|_   _||_| ___  ___|_   _|___  ___  ___|_   _|___  ___  ___  _____ |_| ___  ___ | |
  | |  | ||  _||___| | | | .'||  _||___| | | | . || -_||  _||     || ||   || .'|| |
  |_|  |_||___|      |_| |__,||___|      |_| |___||___||_|  |_|_|_||_||_|_||__,||_|
                                                                                   )";
    return header;
};

std::string get_description() {
    std::string description = "A overengineered tic tac toe game made for fun.";
    return description;
};

std::string get_separator() {
    std::string separator = std::string(48, '_');
    return separator;
};

void clear_terminal() { std::cout << "\033[2J\033[1;1H"; };

void print_text(std::string some_text) { std::cout << some_text << std::endl; };

void reset_terminal() {
    clear_terminal();
    print_text(get_ascii_header());
    print_text(get_description());
    print_text(get_separator());
    print_text("\n");
}

char get_grid_value_symbol(int value) {
    char symbol = ' ';
    if (value == 1) {
        symbol = 'X';
    } else if (value == 2) {
        symbol = 'O';
    };

    return symbol;
};

void print_grid(std::array<std::array<int, 3>, 3> grid) {
    for (int i = 0; i < 3; i++) {
        std::cout << '|';
        for (int j = 0; j < 3; j++) {
            std::cout << get_grid_value_symbol(grid[i][j]) << "|";
        }
        std::cout << std::endl;
    }
    print_text("");
};

void print_player_win(std::string player_name) {
    std::string congrat_text = player_name + " wins! Congratulations! ";
    print_text(congrat_text);
};

void print_draw() {
    std::string draw_text = "The grid is full... yet no one wins!";
    print_text(draw_text);
};
