#include<SDL2/SDL.h>
#include<iostream>
#include"neural_network.hpp"
#include"snake.hpp"
#include<ctime>

#define FPS 30 // it is not the snake movements fps, because the inputs are also based on this fps



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
        NeuralNetwork::CONTAINER_SIZE n_snakes;
        std::vector<SnakeGame::Snake> snakes;
        NeuralNetwork::NetworkContainer *snakeContainer;
    
    public:
        Game(NeuralNetwork::CONTAINER_SIZE n_s, int height = 500, int width = 500, int w_squares = 25, int h_squares = 25);
        ~Game();

        void input();
        void update();
        void draw();
};

Game::Game(NeuralNetwork::CONTAINER_SIZE n_s, int g_height = 500, int g_width = 500, int gw_squares = 25, int gh_squares = 25) 
    : n_snakes(n_s), height(g_height), width(g_width), w_squares(gw_squares), h_squares(gh_squares)
{
    // initializing container of neural networks
    snakeContainer = new NeuralNetwork::NetworkContainer(n_s, 10, 4);
    assert(snakeContainer != NULL);

    // intializing game attributes
    running = 1;
    fullscreen = 0;
    lastTime = 0;

    //loop variables
    int drawTimer = 0;
    int snakeTimer = 0, lastSnakeTimer = 0;
    int first = 1;

    universal_s = (int) 5*width/(6*w_squares-1);

    // snakes boiiii (and their foods)
    std::srand(std::time(nullptr));
    int food_x, food_y;

    for ( int i = 0; i < n_snakes; i++) {
        food_x = std::rand() % w_squares;
        food_y = std::rand() % h_squares;
        SnakeGame::Snake c_snake(w_squares/2, h_squares/2, w_squares, h_squares, true, true, food_x, food_y);
        snakes.push_back(c_snake);
    }

    // std::vector<SnakeGame::Snake>::iterator snake_iterator;
    // snake_iterator = snakes.begin();

    // while (snake_iterator != snakes.end()) {
    //     food_x = std::rand() % w_squares;
    //     food_y = std::rand() % h_squares;
    //     *snake_iterator()
    // }
    
    

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed to initialize sdl2" << std::endl;
    
    if(SDL_CreateWindowAndRenderer(width, height,  SDL_RENDERER_ACCELERATED, &window, &renderer) < 0) {
        std::cout << "Failed to create window and renderer" << std::endl;
        exit(1); 
    }

    SDL_SetWindowTitle(window, "my littles snakes");
    SDL_ShowCursor(SDL_TRUE);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}

// proccess input events, like quitting, reseting
void Game::input() {
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) running = false;
    }
    
}

void Game::update();
void Game::draw();