#include<SDL2/SDL.h>
#include<iostream>

#define WIDTH 500
#define HEIGHT 500

bool running, fullscreen;

int frameCount, timerFPS, lastFrame, fps;

void update(SDL_Window*window);
void input();
void draw(SDL_Renderer * renderer, SDL_Window *window);

int main () {
    running = 1;
    fullscreen = 0;
    static int lastTime = 0;
    SDL_Renderer * renderer;
    SDL_Window *window;


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed to initialize sdl2" << std::endl;
    // sdl renderer accelerated 
    if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_RENDERER_ACCELERATED, &window, &renderer) < 0) std::cout << "Failed to create window and renderer" << std::endl;

    SDL_SetWindowTitle(window, "my little window");
    SDL_ShowCursor(SDL_TRUE);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
    

    while(running) {
        lastFrame = SDL_GetTicks();
        if (lastFrame >= lastTime+1000) {
            // a second has passed
            lastTime=lastFrame;
            fps=frameCount;
            frameCount = 0;
        }
        // std::cout << fps << std::endl;

        update(window);
        input();
        draw(renderer, window);
    }

    // closing all
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void update(SDL_Window*window) {
    if(fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if(!fullscreen) SDL_SetWindowFullscreen(window, 0);
}

void input() {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
       if (e.type == SDL_QUIT) running= false;

       const Uint8*keystates = SDL_GetKeyboardState(NULL);
       if (keystates[SDL_SCANCODE_ESCAPE]) running =false;
       
       if(keystates[SDL_SCANCODE_F11]) fullscreen = !fullscreen;

        if (e.type == SDL_KEYDOWN)
        std::cout << SDL_GetKeyName(e.key.keysym.sym) << std::endl ;

    }
}
void draw(SDL_Renderer*renderer, SDL_Window*window) {
    SDL_SetRenderDrawColor(renderer, 255, 0 ,0, 255);
    SDL_Rect rect;
    rect.x = rect.y = 0;
    rect.w = 100;
    rect.h = 100;

    SDL_RenderFillRect(renderer, &rect);

    frameCount++;
    int timerFPS = SDL_GetTicks() - lastFrame;
    if(timerFPS<1000/60) {
        SDL_Delay(1000/60 - timerFPS);
    }

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