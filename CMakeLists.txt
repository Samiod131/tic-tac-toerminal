cmake_minimum_required(VERSION 3.10)
project(TicTacToerminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

file(GLOB tictactoe_SRC
"src/*.cpp"
)

add_executable(${PROJECT_NAME} ${tictactoe_SRC})

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Widgets)