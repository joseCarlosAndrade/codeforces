#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>

namespace SnakeGame 
{
    typedef enum e_snake_direction {UP, DOWN, LEFT, RIGHT} Direction;
    typedef enum e_snake_state {ALIVE, DEAD, VICTORY} SnakeState;

    // parent class that is inherited by all game objects. It provides general pourpose functions and vars
    class GameObject {
        private:
        
            std::string name;

        public:
            int x, y;
            int getX();
            int getY(); 
            void setPosition(int x, int y);
            
    };

    class Food : public GameObject {
        public:
            Food(int x, int y);
            
    };

    class Snake : public GameObject {
        private:
            int maxW, maxH;
            Direction snakeDirection;
            void moveSnake();

        public:
            Snake * nxtSnake;
            bool isHead;
            SnakeState state;

            Snake(int x, int y, int maxW, int maxH, bool isHead);

            void setSnakePosition(int x, int y);
            void setSnakeDirection(Direction direction);
            Direction getSnakeDir();
            void moveAllSnakes();
            void addSnake();
            void changeAllStates();
            bool isCollidingBody(int x, int y) ;
            SnakeState checkCollision(SnakeGame::Food *food);
            
    };

}
#endif