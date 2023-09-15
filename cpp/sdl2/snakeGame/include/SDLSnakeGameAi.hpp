#ifndef SDL_AI_SNAKE_H
#define SDL_AI_SNAKE_H

#include<SDL2/SDL.h>
#include<iostream>
#include"neural_network.hpp"
#include"snake.hpp"
#include<ctime>

#define FPS 30 // it is not the snake movements fps, because the inputs are also based on this fps


typedef enum {RANDOM, NEURAL_NETWORK} snake_behavior;
class Game {
    private:
        // game variables
        SDL_Renderer * renderer;
        SDL_Window * window;
        int width, height, w_squares, h_squares;
        int universal_s;

        // loop variables
        bool running, fullscreen;

        int frameCount, timerFPS, lastFrame, fps;
        int lastTime;

        // snake and network variables
        snake_behavior behavior;
        NeuralNetwork::CONTAINER_SIZE n_snakes;
        std::vector<SnakeGame::Snake> snakes;
        NeuralNetwork::NetworkContainer *snakeContainer;
        int deadSnakes;
        SnakeGame::SNAKE_VIEW_AREA snake_view;
    
    public:
        Game(NeuralNetwork::CONTAINER_SIZE n_s, SnakeGame::SNAKE_VIEW_AREA view, snake_behavior bh, int g_height = 500, int g_width = 500, int gw_squares = 25, int gh_squares = 25) ;
        ~Game();

        void initSnakes();

        void input();
        void update();
        void updateSnakes(snake_behavior mode);
        void draw();

        void mainLoop();

        int calculateFps();

        void drawFood(int step, SnakeGame::Food * food);

        void drawSnakes(int step, SnakeGame::Snake &snake, int i);

        //TODO:
        void makeSelection();
        void doCrossover();
        void resetSnakesAndNN();
};

#endif