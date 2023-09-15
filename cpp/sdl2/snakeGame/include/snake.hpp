#ifndef SNAKE_H
#define SNAKE_H
#include<iostream>
#include<vector>
#include<map>
#include"neural_network.hpp"

namespace SnakeGame 
{
    typedef enum e_snake_direction {UP, DOWN, LEFT, RIGHT} Direction;
    typedef enum e_snake_state {ALIVE, DEAD, VICTORY} SnakeState;
    typedef unsigned int SNAKE_VIEW_AREA;

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
            SNAKE_VIEW_AREA snakeView;
            Direction snakeDirection;
            Food* thisFood;

            NeuralNetwork::SingleNetwork * snakeBrain;
            std::map<int , SnakeGame::Direction> directionMap;
        

            void moveSnake();
            bool isCollidingBody(int x, int y) ;

        public:
            Snake * nxtSnake;
            bool isHead;
            SnakeState state;

            Snake(int x, int y, int maxW, int maxH, bool isHead, bool own_food=false, int fx = 0, int fy = 0, SNAKE_VIEW_AREA view = 5);

            // snake game functions
            void setSnakePosition(int x, int y);
            void setSnakeDirection(Direction direction);
            Direction getSnakeDir();
            void moveAllSnakes();
            void addSnake();
            void changeAllStates();
            
            SnakeState checkCollision();
            SnakeState checkCollision(SnakeGame::Food *food);

            Food * getFoodPtr();

            // neural network functions
            std::vector<float> getInputs();
            void setThisBrain(NeuralNetwork::SingleNetwork * single);
            void takeDecision();
            
    };

}
#endif