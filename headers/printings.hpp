#include <iostream>


std::string get_ascii_header(){

    std::string header = R"(
                                                                                   
 _____  _           _____               _____                       _            _ 
|_   _||_| ___  ___|_   _|___  ___  ___|_   _|___  ___  ___  _____ |_| ___  ___ | |
  | |  | ||  _||___| | | | .'||  _||___| | | | . || -_||  _||     || ||   || .'|| |
  |_|  |_||___|      |_| |__,||___|      |_| |___||___||_|  |_|_|_||_||_|_||__,||_|
                                                                                   )";
    return header;
}

std::string get_description(){

    std::string description = "A small tic tac toe game made for fun.";
    return description;
}


void print_text(std::string some_text){
    std::cout << some_text << std::endl;
}

char get_grid_value(int value){
    char symbol = ' ';
    if (value == 1) {
        symbol = 'X';
    }
    else if (value == 2){
        symbol = 'O';
    };

    return symbol;

}

void print_grid(int grid[3][3]){
    for (int i = 0; i < 3; i++) {
        std::cout << '|';
        for (int j = 0; j < 3; j++) {
            std::cout << get_grid_value(grid[i][j]) << "|";
        }
        std::cout << std::endl;

    }
}