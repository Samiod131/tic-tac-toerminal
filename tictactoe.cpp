#include <iostream>
#include <array>
#include "headers/printings.hpp"



std::string get_user_input(){
    std::string input;
    std::cin >> input;

    return input;
}

bool get_continue(){
    std::string input;
    
    print_text("Do you want to start a new game ? [y/n]");
    input = get_user_input();
    if (input=="y" || input =="Y"){
        return true;
    } else if (input=="n" || input =="N"){
        return false;
    } else {
        print_text("Invalid input, must be \"y\" or \"n\" !");
        return get_continue();
    };
}

std::array<int, 2> get_position_play(){
    std::string input;
    std::cin >> input;
    std::array<int, 2> coordinates;

    if (input.length()!=2 || input.find_first_not_of("123")!=std::string::npos){
        print_text("Play position on grid must be in format \"12\" row no. (top to bottom) and column no. (left to right).");
        return get_position_play();
    };

    coordinates[0] = ((int)input[0]) - ((int)'0')-1;
    coordinates[1] = ((int)input[1]) - ((int)'0')-1;

    return coordinates;
}




void run_new_game(){
    bool player1_win = false;
    bool player2_win = false;
    bool draw = false;

    std::array<std::array<int, 3>, 3> grid = {{{0,0,0}, {0,0,0}, {0,0,0}}};
    print_grid(grid);

    while (true){
        std::array<int, 2> position = get_position_play();
        grid[position[0]][position[1]] = 1;
        print_grid(grid);
    };
}

int main() {
    print_text(get_ascii_header());
    print_text(get_description());

    bool continue_program = true;
    while (continue_program) {
        run_new_game();
        continue_program = get_continue();

    }
    

    return 0;
}

