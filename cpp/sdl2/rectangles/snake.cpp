#include"snake.hpp"
#include<ctime>
#include<cstdlib>

int SnakeGame::GameObject::getX() {
    return this->x;
}

int SnakeGame::GameObject::getY() {
    return this->y;
}

void SnakeGame::GameObject::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
    
}

SnakeGame::Snake::Snake(int x, int y, int maxW, int maxH, bool isHead) {
    // sets initial position
    Snake::setPosition(x, y);
    this->maxH = maxH;
    this->maxW = maxW;
    this->snakeDirection = RIGHT;
    this->isHead = isHead;
    this->state = SnakeGame::ALIVE;

    if (isHead)
        this->nxtSnake = new SnakeGame::Snake(x-1, y, maxW, maxH, false);

    else 
        this->nxtSnake = NULL;

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
        if (this->x == this->maxW-1)  {this->state = DEAD ;return;};
            this->x++;
        break;
    
    case UP:
        if (this->y ==0) {this->state = DEAD ;return;};
            this->y--;
        break;
    
    case LEFT:
        if (this->x ==0) {this->state = DEAD ;return;};
        this->x--;
        break;

    case DOWN:
        if (this->y == this->maxH-1) {this->state = DEAD ;return;};
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

SnakeGame::SnakeState SnakeGame::Snake::checkCollision(SnakeGame::Food* food) {
    // checks collision between its body
    // checks collision between food and snake    

    if (this->isHead && this->x == food->x && this->y == food->y) {
        this->addSnake();
        std::srand(std::time(nullptr));
        int x, y;
        do {  
            x = std::rand() % this->maxW;
            y = std::rand() % this->maxH;
        } while (isCollidingBody(x, y));
        food->setPosition(x, y);
    }
    SnakeGame::Snake* t_snake = this;
    do {
        t_snake = t_snake->nxtSnake;
        if (this->isHead&& this->x == t_snake->x && this->y== t_snake->y) {
            this->state = DEAD;
            return SnakeGame::DEAD;
        }
        
    } while (t_snake->nxtSnake != NULL);

    return SnakeGame::ALIVE;
}

bool SnakeGame::Snake::isCollidingBody(int x, int y) {
    if (this->x == x && this->y==y) return true;
    if (this->nxtSnake == NULL) return false;
    return this->nxtSnake->isCollidingBody(x, y);
    // std::cout << "false " ;
    
}

void SnakeGame::Snake::changeAllStates() {
    this->state = SnakeGame::DEAD;
    if (this->nxtSnake != NULL) this->nxtSnake->changeAllStates();
}

// implement my own queue 

SnakeGame::Food::Food(int x, int y) {
    

    this->x = x;
    this->y = y;
}

