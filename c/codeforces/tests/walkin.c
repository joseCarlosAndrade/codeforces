#include<stdio.h>
#include<math.h>
// #include<conio.h>

#define IMPOSSIBLE -1
#define MAX_CASES 10000
#define MAX_INTEGERS 100000000

typedef struct Point {
    long int x;
    long int y;
} Point;

typedef struct Points {
    Point initial;
    Point final;
    unsigned long int count;
    // int xo;
    // int yo;
    // int x;
    // int y;

} Position;

unsigned long int checkMove();
unsigned long int checkMinimumMoves(Position *point);
long double checkDistance(Position *point);
int checkSet(int points[]);

int main(){
    // get the amount of checks that will be made
    int results[MAX_CASES];
    int checks;
    scanf("%d", &checks);

    if (checks <= 0 || checks > MAX_CASES)
    {
        printf("%d", -1);
    }
    else {
        for (int i = 0; i < checks; i++)
            {
                results[i] = checkMove();
            }

        for (int i =0; i < checks; i++) {
            if (i == checks-1){
                printf("%d", results[i]);
            }
            else
            printf("%d\n", results[i]);
        }
    }
}

int checkSet(int points[]) {
    for (int i = 0; i < 4; i++) {
        // printf("\n points [2 ] : %d\n", points[2]);
        if (points[i] < -MAX_INTEGERS || points[i] > MAX_INTEGERS ) {
            // printf("/n entrou";
            return 0;
        }
    }
    return 1;
}

unsigned long int checkMove()
{
    long int a, b, c, d;
    scanf("%ld %ld %ld %ld", &a, &b, &c, &d);

    int pointList [4] = {a, b, c, d};
    if (checkSet(pointList) == 0) {
        printf("impossible by range\n");
        return IMPOSSIBLE;
    }
    // printf("input: %d %d %d %d", a, b, c, d);
    // check if it possible to reach first by geometry
    if ((d < b) || (d - b < c - a)) {
        printf("impossible by geometry\n");
        return IMPOSSIBLE;
    }
    else  {
        // prints the minimum amount of moves 
        Point init;
        Point final;
        init.x = a;
        init.y = b;
        final.x = c;
        final.y = d;

        Position position, *positionPtr;
        positionPtr = &position;
        position.initial = init;
        position.final = final;
        position.count = 0;

        // printf("\nPosition: init: %d %d; final: %d %d", position.initial.x,position.initial.y, position.final.x, position.final.y);

        // printf("\n%d", checkMinimumMoves(positionPtr));
        return checkMinimumMoves(positionPtr);
    }
    
}

unsigned long int checkMinimumMoves(Position *point)
{
    // check if the given point is already at its destination
    if (point->initial.x == point->final.x && point->initial.y == point->final.y)
    {
        // printf("\nSame %d\n", point->count);
        return point->count;
    }
    long double distance = checkDistance(point);
    

    point->count += 1;
    if (distance > 0){
        
        checkMinimumMoves(point);
    }
    else {
        return point->count;
    }
//    return -1;
}

long double checkDistance(Position *point) {
    // calculate the two possible distances
    double distance1;
    double distance2;

    //  INVALID METHOD? SEGMENTATION FAULT
    
    distance1 = sqrt( ( int)pow(point->final.x - (point->initial.x + 1) , 2)  + ( int)pow(point->final.y - (point->initial.y + 1) ,2));
    distance2 = sqrt( ( int)pow(point->final.x - (point->initial.x - 1) , 2)  + ( int)pow(point->final.y - point->initial.y ,2));
    printf("\ndistances 1 and 2: %g %g || %ld", distance1, distance2, point->final.x);
    // distance 1: up right diagonal
    // Point temp1;
    // temp1.x = point.initial.x + 1;
    // temp1.y = point.initial.y + 1;

    // distance 2: left
    if (distance1 < distance2) {
        point->initial.x += 1;
        point->initial.y += 1;
        // printf("s");
        return distance1;
    }
    else {
        point->initial.x -= 1;
        // printf("b");
        return distance2;
    }

}

