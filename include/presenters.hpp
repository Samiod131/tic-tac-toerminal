#pragma once

#include <iostream>
#include <array>
#include <memory>
#include <mutex>


#include "../include/views.hpp"


class PresenterBase {
    public:
        virtual void init_view() = 0;

        virtual void send_message(std::string message, int priority=0) = 0;
        // virtual void set_current_player(int player_id) = 0;

        virtual std::string get_text_input(std::string question) = 0;
        virtual bool get_yorn_input(std::string question) = 0;
        // virtual void refresh_grid(std::array<std::array<int, 3>, 3> grid) = 0;
        // virtual void reset_grid() = 0;
        // virtual void reset_game_setup() = 0;


        virtual std::array<int, 2> get_position_play(std::array<std::array<int, 3>, 3> grid) = 0;
        virtual  bool get_rematch() = 0;
        virtual bool get_continue() = 0;

        virtual void reset_terminal() = 0;
        virtual void print_grid(std::array<std::array<int, 3>, 3> grid) = 0;
        virtual void print_text(std::string some_text) = 0;
        virtual void print_player_win(std::string player_name) = 0;
        virtual void print_draw() = 0;        


    

};

class TerminalPresenter : public PresenterBase {
    private:
        TerminalView view;
    public:
        void init_view(){
            view = TerminalView();
        }

        void send_message(std::string message, int priority=0){
            view.print_text(message);
        };



        bool get_rematch() {
            return view.get_rematch();
        }

        std::string get_text_input(std::string question) {
            view.print_text(question);
            return view.get_user_input();
        }

        bool get_yorn_input(std::string question) {
            view.print_text(question);
            return view.get_yorn_input();
        }
        
        bool get_continue() {
            return view.get_continue();
        }

        void reset_terminal() {
            return view.reset_terminal();
        }

        void print_grid(std::array<std::array<int, 3>, 3> grid) {
            return view.print_grid(grid);
        }

        void print_text(std::string some_text) {
            return view.print_text(some_text);
        }

        std::array<int, 2> get_position_play(std::array<std::array<int, 3>, 3> grid) {
            return view.get_position_play(grid);
        }

        void print_player_win(std::string player_name) {
            return view.print_player_win(player_name);
        }

        void print_draw() {
            return view.print_draw();
        }

};

class QtPresenter : public PresenterBase {
    private:
    

    public:
};


class PresenterManager {
    private:
        static PresenterBase* instance;
        static std::mutex instanceMutex;
        
        PresenterManager() = delete;
        
    public:
        template<typename T>
        static void initialize() {
            std::lock_guard<std::mutex> lock(instanceMutex);
            if (instance != nullptr) {
                delete instance;
            }
            instance = new T();
            instance->init_view();
        }
        
        static PresenterBase* get_instance() {
            std::lock_guard<std::mutex> lock(instanceMutex);
            if (instance == nullptr) {
                throw std::runtime_error("Presenter not initialized. Call initialize<T>() first.");
            }
            return instance;
        }

        static void destroy() {
            std::lock_guard<std::mutex> lock(instanceMutex);
            if (instance != nullptr) {
                delete instance;
                instance = nullptr;
            }
        }
    };

