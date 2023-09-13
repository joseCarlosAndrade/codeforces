#include<SDL2/SDL.h>
#include<iostream>
#include"../include/neural_network.hpp"
#include"../include/snake.hpp"
#include"../include/SDLSnakeGameAi.hpp"
#include<map>

Game::Game(NeuralNetwork::CONTAINER_SIZE n_s, int g_height , int g_width , int gw_squares, int gh_squares ) 
    : n_snakes(n_s), height(g_height), width(g_width), w_squares(gw_squares), h_squares(gh_squares)
    {
        // initializing container of neural networks
        snakeContainer = new NeuralNetwork::NetworkContainer(n_s, 10, 4);
        assert(snakeContainer != NULL);

        // intializing game attributes
        running = 1;
        fullscreen = 0;
        lastTime = 0;

        universal_s = (int) 5*width/(6*w_squares-1);


        if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed to initialize sdl2" << std::endl;
        
        if(SDL_CreateWindowAndRenderer(width, height,  SDL_RENDERER_ACCELERATED, &window, &renderer) < 0) {
            std::cout << "Failed to create window and renderer" << std::endl;
            exit(1); 
        }

        SDL_SetWindowTitle(window, "my littles snakes");
        SDL_ShowCursor(SDL_TRUE);
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
    }

Game::~Game() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

// intanciates all snakes
void Game::initSnakes() {
    // snakes boiiii (and their foods)
    std::srand(std::time(nullptr));
    int food_x, food_y;

    this->deadSnakes = 0;

    for ( int i = 0; i < n_snakes; i++) {
        food_x = std::rand() % w_squares;
        food_y = std::rand() % h_squares;
        SnakeGame::Snake c_snake(w_squares/2, h_squares/2, w_squares, h_squares, true, true, food_x, food_y);
        snakes.push_back(c_snake);
    }
}

// proccess input events, like quitting, reseting
void Game::input() {
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT) running = false;
    }
    
}

void Game::update() {
    // not really necessary for this
}

// update all snakes on game
void Game::updateSnakes() {
    std::map<int , SnakeGame::Direction> map;
        map[0] = SnakeGame::RIGHT;
        map[1] = SnakeGame::DOWN;
        map[2] = SnakeGame::LEFT;
        map[3] = SnakeGame::UP;

    std::vector<SnakeGame::Snake>::iterator snake_iterator = snakes.begin();
    int i =0;
    while(snake_iterator != snakes.end()) {
        if (i++ > n_snakes) break; // for safety
        
        if (snake_iterator->state == SnakeGame::DEAD) {
            snake_iterator++;
            continue;
        }

        int index = std::rand() % 4;
        
        // std::cout << i++ << " " << map[i] << std::endl;
        SnakeGame::Direction thisDirecion = map[index]; // all moving down for now

        snake_iterator->setSnakeDirection(thisDirecion); // **** ia role
        snake_iterator->moveAllSnakes();
        snake_iterator->checkCollision();
        // lastSnakeTimer = snakeTimer;
        if (snake_iterator->state==SnakeGame::DEAD) {
            this->deadSnakes++;
            snake_iterator->changeAllStates();
        }

        snake_iterator++;
    }   
}


// main loop for one round
void Game::mainLoop() {
    //loop variables
    int drawTimer = 0;
    int snakeTimer = 0, lastSnakeTimer = 0;
    int first = 1;

    while(running) {
        if (this->deadSnakes == n_snakes) { 
            std::cout << this->deadSnakes << " dead";
            break;
        }
        snakeTimer++;
        int fps = this->calculateFps();


        this->input();
        // this->update();
        if (snakeTimer - lastSnakeTimer >= fps/6 && snakeTimer > FPS + 5) {
            this->updateSnakes();

            lastSnakeTimer = snakeTimer;
        }
        this->draw();
    }
}

int Game::calculateFps() {
    lastFrame = SDL_GetTicks();
        if (lastFrame >= lastTime+1000) {
            // a second has passed
            lastTime=lastFrame;
            fps=frameCount;
            frameCount = 0;
        }

        frameCount++;
        int timerFPS = SDL_GetTicks() - lastFrame;
        if(timerFPS<1000/FPS) {
            SDL_Delay(1000/FPS - timerFPS);
        }
        return fps;
}



void Game::draw() {
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);

    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = width;
    rect.h = height;
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
 
    // it automates the square distribution based on the settings specified on the define area
    // trust me it works
    int step = (int)(6*universal_s)/5 ;

    rect.w = rect.h = (int)universal_s;

    for ( int i = 0; i <= w_squares; i++) {
        
        for (int j = 0 ; j <= h_squares; j++ ){
            rect.x = step*j + universal_s/5; 
            rect.y = step*i + universal_s/5;
        
            SDL_RenderDrawRect(renderer, &rect);
        }
    }

    // drawing each snake

    std::vector<SnakeGame::Snake>::iterator snake_iterator = snakes.begin();

    while(snake_iterator != snakes.end()) {
        drawSnakes(step,*snake_iterator, 0);
        // if snake not dead, draw its food
        if (snake_iterator->state != SnakeGame::DEAD) drawFood(step, snake_iterator->getFoodPtr());
        snake_iterator++;
    }

    // puts everything into screen
    SDL_RenderPresent(renderer);
}


void Game::drawFood(int step, SnakeGame::Food *food) {
    SDL_SetRenderDrawColor(renderer, 230, 0, 50, 255);
    SDL_Rect food_r;
    food_r.w = food_r.h = (int)universal_s;
    food_r.x = food->x * step + universal_s/5;
    food_r.y = food->y * step + universal_s/5;
    SDL_RenderFillRect(renderer, &food_r);
}

// draw snakes recursively
void Game::drawSnakes(int step, SnakeGame::Snake &snake, int i) {
        if (i > 100) i = 100;
    
        if(snake.state==SnakeGame::ALIVE)
            SDL_SetRenderDrawColor(renderer, 0 + i*0.7, 255 - snake.isHead*30 - i*1.5, 0 + snake.isHead*70, 255);
    
        else if (snake.state==SnakeGame::DEAD)
            SDL_SetRenderDrawColor(renderer, 255 - i*0.7, 0, 0 + snake.isHead*70, 255);

        SDL_Rect snake_r;
        snake_r.w = snake_r.h = (int)universal_s;
        snake_r.x = snake.getX() * step + universal_s/5;
        snake_r.y = snake.getY() * step + universal_s/5;
        SDL_RenderFillRect(renderer, &snake_r);

        if (snake.nxtSnake == NULL) return;

        drawSnakes(step, *(snake.nxtSnake), ++i);

}