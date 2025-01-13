#include <iostream>
#include <array>


std::string get_ascii_header(){

    std::string header = R"(
                                                                                   
 _____  _           _____               _____                       _            _ 
|_   _||_| ___  ___|_   _|___  ___  ___|_   _|___  ___  ___  _____ |_| ___  ___ | |
  | |  | ||  _||___| | | | .'||  _||___| | | | . || -_||  _||     || ||   || .'|| |
  |_|  |_||___|      |_| |__,||___|      |_| |___||___||_|  |_|_|_||_||_|_||__,||_|
                                                                                   )";
    return header;
};

std::string get_description(){

    std::string description = "A small tic tac toe game made for fun.";
    return description;
};


void print_text(std::string some_text){
    std::cout << some_text << std::endl;
};

char get_grid_value_symbol(int value){
    char symbol = ' ';
    if (value == 1) {
        symbol = 'X';
    }
    else if (value == 2){
        symbol = 'O';
    };

    return symbol;

};

void print_grid(std::array<std::array<int, 3>, 3> grid){
    for (int i = 0; i < 3; i++) {
        std::cout << '|';
        for (int j = 0; j < 3; j++) {
            std::cout << get_grid_value_symbol(grid[i][j]) << "|";
        }
        std::cout << std::endl;

    }
};

void print_player_win(int player_id){
    std::string congrat_text = "Player "+std::to_string(player_id)+" wins! Congratulations! ";
    print_text(congrat_text);
};

void print_draw(){
    std::string draw_text = "The grid is full... yet no one wins!";
    print_text(draw_text);
};
