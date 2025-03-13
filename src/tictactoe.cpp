#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>

#include "../include/inputs.hpp"
#include "../include/printings.hpp"
#include "../include/players.hpp"
#include "../include/game_setup.hpp"

void run_new_setup()
{

    std::shared_ptr<Player> player_1;
    std::shared_ptr<Player> player_2;

    print_text("Enter your name:");
    std::string human_name = get_user_input();
    player_1 = std::make_shared<HumanPlayer>(1, human_name);

    print_text("Will you play against a friend? (y/n)");
    if (get_yorn_input())
    {
        print_text("Enter second player's name:");
        std::string human_name = get_user_input();
        player_2 = std::make_shared<HumanPlayer>(2, human_name);
    }
    else
    {
        player_2 = std::make_shared<EasyBotPlayer>(2, "Dumb Bot");
    }

    GameSetup new_setup = GameSetup(player_1, player_2);
    new_setup.run();
}

int main()
{
    reset_terminal();
    while (get_continue())
    {
        run_new_setup();
    }
    clear_terminal();

    return 0;
}
