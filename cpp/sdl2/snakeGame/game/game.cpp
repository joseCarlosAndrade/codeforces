#include"../include/SDLSnakeGameAi.hpp"

int main(int argc, char ** argv) {
    Game game(200, 5, 650, 900, 50, 36);
    game.initSnakes();

    game.mainLoop();
}