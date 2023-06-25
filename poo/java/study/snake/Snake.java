package poo.java.study.snake;

public class Snake {

    private static final char SNAKE_HEAD = '&';
    private static final char SNAKE_TAIL = '@';

    private int snakeHeadPosX; // Pos of head
    private int snakeHeadPosY; // Pos of head
    
    // necessary?
    private int snakeTailPosX; // Pos of last bit of the tail
    private int snakeTailPosY; // Pos of last bit of the tail

    private int tailLength = 2;

    private enum Direction {UP, DOWN, RIGHT, LEFT};

    Direction SnakeDirection;
    Direction TailDirection;
    
    public Snake(int x, int y)
    {
        setHeadPosition(x, y);
    }

    public Snake(int x, int y, int tailInitialLength)
    {
        setHeadPosition(x, y);
        setSnakeLength(tailInitialLength);
    }

    public void setHeadPosition(int x, int y)
    {
        snakeHeadPosX = x;
        snakeHeadPosY = y;
    }

    public void setSnakeLength(int tailLength)
    {
        this.tailLength = tailLength;
    }

    /**
     * Handles the movement update of snakes body
     * @param direction
     */
    public void updateMovement(Direction direction)
    {
        SnakeDirection = direction;
        
        switch (direction){
            case UP:
                setHeadPosition(snakeHeadPosX, snakeHeadPosY-1);
                break;

            case DOWN:
                setHeadPosition(snakeHeadPosX, snakeHeadPosY+1);
                break;

            case LEFT:
                setHeadPosition(snakeHeadPosX-1, snakeHeadPosY);
                break;

            case RIGHT:
                setHeadPosition(snakeHeadPosX+1, snakeHeadPosY);
                break;
        }

        popTail(direction);
        
    }

    public void popTail(Direction direction)
    {

    }

    // public boolen checkCollision()
}


/* Snake -> updates head position acording to direction
 * Pops last tail every iteration UNLESS -> isTouchingFood
 * 
 * 
 * 
 */
