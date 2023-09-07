#include"snake.hpp"

SnakeGame::Snake::Snake(int x, int y, int maxW, int maxH, bool isHead) {
    // sets initial position
    Snake::setSnakePosition(x, y);
    this->maxH = maxH;
    this->maxW = maxW;
    this->snakeDirection = RIGHT;
    this->isHead = isHead;

    if (isHead)
        this->nxtSnake = new SnakeGame::Snake(x-1, y, maxW, maxH, false);

    else 
        this->nxtSnake = NULL;

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

SnakeGame::Direction SnakeGame::Snake::getSnakeDir() {
    return this->snakeDirection;
}

void SnakeGame::Snake::moveAllSnakes() {

    this->moveSnake();

    if (this->nxtSnake == NULL) return;

    this->nxtSnake->moveAllSnakes();
    this->nxtSnake->setSnakeDirection(this->snakeDirection);

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
        // std::cout << this->y << " " << this->maxH-1<< std::endl;
        this->y++;
        break;
    }
}

void SnakeGame::Snake::addSnake() {
    if (this->nxtSnake!=NULL) this->nxtSnake->addSnake();
    if(this->nxtSnake==NULL) {
    int cx, cy;

    switch (this->snakeDirection)
    {
    case SnakeGame::UP:
        cx = this->x;
        cy = this->y+1;
        break;
    
    case SnakeGame::DOWN:
        cx = this->x;
        cy = this->y-1;
        break;
    
    case SnakeGame::LEFT:
        cx = this->x+1;
        cy = this->y;
        break;
    
    case SnakeGame::RIGHT:
        cx = this->x-1;
        cy = this->y;
        break;
    }
    this->nxtSnake = new SnakeGame::Snake(cx, cy,  this->maxW, this->maxH, false);
    this->nxtSnake->snakeDirection = this->snakeDirection;

    // std::cout << "Adding new snake " << std::endl;
    }
}

void SnakeGame::Snake::checkCollision() {

}

// implement my own queue 