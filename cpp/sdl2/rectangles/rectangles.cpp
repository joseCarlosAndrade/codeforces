#include<SDL2/SDL.h>
#include<iostream>

#include"snake.hpp"

#define WIDTH 500
#define HEIGHT 500

#define W_SQUARES 25
#define H_SQUARES 25

#define UNIVERSAL_W 5*WIDTH/(6*W_SQUARES-1)


#define FPS 30

bool running, fullscreen;

int frameCount, timerFPS, lastFrame, fps;
int lastTime;

int calculateFps();
void update(SDL_Window*window);
void input(SnakeGame::Snake &snake);
void draw(SDL_Renderer * renderer, SDL_Window *window, SnakeGame::Snake * snake);

int main () {
    running = 1;
    fullscreen = 0;
    lastTime = 0;
    
    SDL_Renderer * renderer;
    SDL_Window *window;


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed to initialize sdl2" << std::endl;
    // to let it resizable SDL_WINDOW_RESIZABLE ord
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT,  SDL_RENDERER_ACCELERATED, &window, &renderer) < 0) std::cout << "Failed to create window and renderer" << std::endl;

    SDL_SetWindowTitle(window, "my little window");
    SDL_ShowCursor(SDL_TRUE);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
    
    // draw_background(renderer, window);
    // draw_rec_background(renderer);

    SnakeGame::Snake* snake =  new SnakeGame::Snake(10, 10, W_SQUARES, H_SQUARES);

    while(running) {
        
        int fps = calculateFps();
        std::cout << fps << std::endl;

        // draw(renderer, window);
        input(*snake);
        update(window);
        draw(renderer, window, snake);
        snake->moveSnake();
        
    }

    // closing all
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

int calculateFps() {
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

void update(SDL_Window*window) {
    if(fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if(!fullscreen) SDL_SetWindowFullscreen(window, 0);
}

void input(SnakeGame::Snake &snake) {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
       if (e.type == SDL_QUIT) running= false;

       const Uint8*keystates = SDL_GetKeyboardState(NULL);
       if (keystates[SDL_SCANCODE_ESCAPE]) running =false;
       
    //    if(keystates[SDL_SCANCODE_F11]) fullscreen = !fullscreen;
        if (keystates[SDL_SCANCODE_UP]) snake.setSnakeDirection(SnakeGame::UP);
        if (keystates[SDL_SCANCODE_RIGHT]) snake.setSnakeDirection(SnakeGame::RIGHT);
        if (keystates[SDL_SCANCODE_LEFT]) snake.setSnakeDirection(SnakeGame::LEFT);
        if (keystates[SDL_SCANCODE_DOWN]) snake.setSnakeDirection(SnakeGame::DOWN);

        if (e.type == SDL_KEYDOWN)
        std::cout << SDL_GetKeyName(e.key.keysym.sym) << std::endl ;

    }
}



void draw(SDL_Renderer*renderer, SDL_Window*window, SnakeGame::Snake *snake) {
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);

    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = WIDTH;
    rect.h = HEIGHT;
    SDL_RenderFillRect(renderer, &rect);

    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
 
    // SDL_Rect rect;

    int step = (int)(6*UNIVERSAL_W)/5 ;

    // rect.x = rect.y = step;
    rect.w = rect.h = (int)UNIVERSAL_W;

    for ( int i = 0; i <= W_SQUARES; i++) {
        
        for (int j = 0 ; j <= H_SQUARES; j++ ){
            rect.x = step*j + UNIVERSAL_W/5; 
            rect.y = step*i + UNIVERSAL_W/5;
        
            SDL_RenderDrawRect(renderer, &rect);
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_Rect snake_r;
    snake_r.w = snake_r.h = (int)UNIVERSAL_W;
    snake_r.x = snake->getX() * step + UNIVERSAL_W/5;
    snake_r.y = snake->getY() * step + UNIVERSAL_W/5;
    SDL_RenderFillRect(renderer, &snake_r);

    SDL_RenderPresent(renderer);
}




/*
while (SDL_PollEvent(&event)) {
    switch (event.type) {
        // Handle non-input stuff here like SDL_QUIT
        // Since you're using the other API, ignore keyboard events
    }
}

const Uint8* kb = SDL_GetKeyboardState(NULL);

shootDirectionY = -kb[SDL_SCANCODE_UP] + kb[SDL_SCANCODE_DOWN];
shootDirectionX = -kb[SDL_SCANCODE_LEFT] + kb[SDL_SCANCODE_RIGHT]

moveDirectionY = -kb[SDL_SCANCODE_W] + kb[SDL_SCANCODE_S];
moveDirectionX = -kb[SDL_SCANCODE_A] + kb[SDL_SCANCODE_D];
*/



/* 
array of rects , spaced by some pixels to fill the backgound
*/