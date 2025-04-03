#include <iostream>
#include <array>
#include <memory>
#include <stdexcept>

#include "../include/presenters.hpp"
#include "../include/players.hpp"
#include "../include/game_setup.hpp"


//Declaring presenter singleton manager global values
PresenterBase* PresenterManager::instance = nullptr;
std::mutex PresenterManager::instanceMutex;


void run_new_setup()
{

    std::shared_ptr<Player> player_1;
    std::shared_ptr<Player> player_2;

    PresenterBase* presenter = PresenterManager::get_instance();

    std::string human_name = presenter->get_text_input("Enter your name:");
    player_1 = std::make_shared<HumanPlayer>(1, human_name);


    if (presenter->get_yorn_input("Will you play against a friend? (y/n)"))
    {
        std::string human_name = presenter->get_text_input("Enter second player's name:");
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
    PresenterManager::initialize<TerminalPresenter>();
    PresenterBase* presenter = PresenterManager::get_instance();
    
    do {
        run_new_setup();
    } while (presenter->get_continue());
    
    PresenterManager::destroy();
    return 0;
}



// #include <QApplication>
// #include <QWidget>
// #include <QLabel>
// #include <QVBoxLayout>



// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
    
//     // Create the main window
//     QWidget window;
//     window.setWindowTitle("Qt Test Window");
//     window.resize(300, 200);
    
//     // Create a label with some text
//     QLabel label("Qt is working correctly!");
    
//     // Create a layout and add the label
//     QVBoxLayout *layout = new QVBoxLayout(&window);
//     layout->addWidget(&label);
//     layout->setAlignment(Qt::AlignCenter);
    
//     // Show the window
//     window.show();
    
//     // Start the event loop
//     return app.exec();
// }