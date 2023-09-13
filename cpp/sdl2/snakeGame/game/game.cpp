#include"../include/SDLSnakeGameAi.hpp"

int main(int argc, char ** argv) {
    Game game(30);
    game.initSnakes();

    game.mainLoop();
}