#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>

namespace SnakeGame 
{
    typedef enum e_snake_direction {UP, DOWN, LEFT, RIGHT} Direction;

    class GameObject {
        std::string name;
    };

    class Snake : GameObject {
        private:
            int x, y, maxW, maxH;
            Direction snakeDirection;
            
            bool isHead;

            void moveSnake();

        public:
            Snake * nxtSnake;

            Snake(int x, int y, int maxW, int maxH, bool isHead);

            int getX();
            int getY(); 
            void setSnakePosition(int x, int y);
            void setSnakeDirection(Direction direction);
            Direction getSnakeDir();
            void moveAllSnakes();
            void addSnake();

            void checkCollision();
    };

    class Food : GameObject {

    };

}
#endif