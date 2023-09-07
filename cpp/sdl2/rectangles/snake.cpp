#include"snake.hpp"

SnakeGame::Snake::Snake(int x, int y, int maxW, int maxH) {
    // sets initial position
    Snake::setSnakePosition(x, y);
    this->maxH = maxH;
    this->maxW = maxW;
    this->snakeDirection = RIGHT;
}

int SnakeGame::Snake::getX() {
    return this->x;
}

int SnakeGame::Snake::getY() {
    return this->y;
}

void SnakeGame::Snake::setSnakePosition(int x, int y) {
    this->x = x;
    this->y = y;
    
}

void SnakeGame::Snake::setSnakeDirection(Direction direction) {
    this->snakeDirection = direction;
}

void SnakeGame::Snake::moveSnake() {
    switch (this->snakeDirection)
    {
    case RIGHT:
        if (this->x == this->maxW-1) return;
        this->x++;
        break;
    
    case UP:
        if (this->y ==0) return;
            this->y--;
        break;
    
    case LEFT:
        if (this->x ==0) return;
        this->x--;
        break;

    case DOWN:
        if (this->y == this->maxH-1) return;
        std::cout << this->y << " " << this->maxH-1<< std::endl;
        this->y++;
        break;
    }
}