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

        public:
            Snake(int x, int y, int maxW, int maxH);

            int getX();
            int getY(); 
            void setSnakePosition(int x, int y);
            void setSnakeDirection(Direction direction);
            void moveSnake();
    };

    class Food : GameObject {

    };

}
#endif