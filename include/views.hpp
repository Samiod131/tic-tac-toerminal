#pragma once

#include <iostream>
#include <array>


class View {
};


class TerminalView : public View {
    private:
        std::string get_ascii_header(void){
            std::string header = R"(
                                                                            
   _____  _           _____               _____                       _            _ 
  |_   _||_| ___  ___|_   _|___  ___  ___|_   _|___  ___  ___  _____ |_| ___  ___ | |
    | |  | ||  _||___| | | | .'||  _||___| | | | . || -_||  _||     || ||   || .'|| |
    |_|  |_||___|      |_| |__,||___|      |_| |___||___||_|  |_|_|_||_||_|_||__,||_|
                                                                                )";
                return header;
        };
        std::string get_description(void) {
            std::string description = "A overengineered tic tac toe game made for fun.";
            return description;
        };
        std::string get_separator() {
            std::string separator = std::string(48, '_');
            return separator;
        };
        char get_grid_value_symbol(int value) {
            char symbol = ' ';
            if (value == 1) {
                symbol = 'X';
            } else if (value == 2) {
                symbol = 'O';
            };
        
            return symbol;
        };

    public:
        TerminalView() {
            reset_terminal();
        };

        void print_text(std::string some_text) { std::cout << some_text << std::endl; };

        void clear_terminal()  { std::cout << "\033[2J\033[1;1H"; };

        std::string get_user_input() {
            std::string input;
            std::cin >> input;
        
            return input;
        }
        
        bool get_yorn_input() {
            std::string input;
            input = get_user_input();
            if (input == "y" || input == "Y") {
                return true;
            } else if (input == "n" || input == "N") {
                return false;
            } else {
                print_text("Invalid input, must be \"y\" or \"n\" !");
                return get_yorn_input();
            };
        }
        
        bool get_rematch() {
            print_text("Do you want a rematch ? [y/n]");
            return get_yorn_input();
        }
        
        bool get_continue() {
            reset_terminal();
            print_text("Do you want to start a new game ? [y/n]");
            return get_yorn_input();
        }
        
        std::array<int, 2> get_position_play(std::array<std::array<int, 3>, 3> grid) {
            std::string input;
            input = get_user_input();
            std::array<int, 2> coordinates;
        
            if (input.length() != 2 || input.find_first_not_of("123") != std::string::npos) {
                print_text(
                    "Play position on grid must be in format \"12\" row no. (top to bottom) and column no. "
                    "(left to right).");
                return get_position_play(grid);
            };
        
            coordinates[0] = ((int)input[0]) - ((int)'0') - 1;
            coordinates[1] = ((int)input[1]) - ((int)'0') - 1;
        
            int previous_val = grid[coordinates[0]][coordinates[1]];
            if (previous_val != 0) {
                print_text("Please select an empty position.");
                return get_position_play(grid);
            };
        
            return coordinates;
        }
        

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
        
        void reset_terminal() {
            clear_terminal();
            print_text(get_ascii_header());
            print_text(get_description());
            print_text(get_separator());
            print_text("\n");
        };

};
