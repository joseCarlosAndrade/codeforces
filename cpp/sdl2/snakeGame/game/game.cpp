#include"../include/SDLSnakeGameAi.hpp"

int main(int argc, char ** argv) {
    Game game(1, 5, 650, 900, 50, 36);
    game.initSnakes();

    game.mainLoop();
}