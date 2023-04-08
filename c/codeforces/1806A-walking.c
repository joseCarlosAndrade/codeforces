#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define IMPOSSIBLE -1
#define MAX_CASES 10000
#define MAX_INTEGERS 100000000


unsigned long int checkMove();
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
        // printf("impossible by range\n");
        return IMPOSSIBLE;
    }
    // printf("input: %d %d %d %d", a, b, c, d);
    // check if it possible to reach first by geometry
    else if ((d < b) || (d - b < c - a)) {
        // printf("impossible by geometry\n");
        return IMPOSSIBLE;
    }
    else{
        // unsigned int moves;
        int temp = 0;

        if (c > a){
            temp = c-a;
            a = c;
            b += temp;
        }
        return abs(d-b) *2 + abs(c-a) + temp;
       
    } 

    
}

