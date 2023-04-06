#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// problem: https://codeforces.com/problemset/problem/1807/F

typedef struct Bouncy
{
    /* data */
    int i, i_old, i2;
    int j, j_old, j2;

    char *direction;
    int bounces, moves;
    // direction = malloc(3);

    int n;
    int m;

    int initial_i[2];
    int initial_j[2];
    int corners;
} Bouncy;

#define MAX_ITER 1000

unsigned int check_move(Bouncy * ptrBncy);
int check_loop(Bouncy * ptrBncy);
void move_one(Bouncy * ptrBncy);
void changeDirection(char previous[2], char next[2], Bouncy * ptrBncy);


int main() {
    
    int test_cases;
    unsigned int results[MAX_ITER];
    scanf("%d", &test_cases);
    // test_cases = 1;
    // printf("%d", test_cases);
    int i = 0;
    while (i < test_cases)
    {   
        // printf("antes");
        Bouncy bouncy;
        Bouncy * ptrBncy = &bouncy;
        bouncy.direction = malloc(3);

        bouncy.bounces = 0;
        bouncy.moves = 0;
        bouncy.corners = 0;

        // unsigned int n, m, i1, j1, i2, j2;
        char d[3];
        scanf("%d %d %d %d %d %d %s", &bouncy.n, &bouncy.m, &bouncy.i, &bouncy.j, &bouncy.i2, &bouncy.j2, d);
        strcpy(bouncy.direction, d);
        // n = 5;
        // m = 7;
        // i1 = 1;
        // j1 = 7;
        // i2 = 2;
        // j2 = 4;
        // *d = "DL";
        // printf("Printing : %d %d %d %d %d %d\n\n", n, m, i1,j1, i2, j2);

        if (bouncy.i == bouncy.i2 && bouncy.j == bouncy.j2)
        {
            results[i] = 0;
            i++;
            free(bouncy.direction);
            continue;
        }
        

        bouncy.initial_i[0] = bouncy.i;
        bouncy.initial_j[0] = bouncy.j;
        
        results[i] = check_move(ptrBncy);
        
        free(bouncy.direction);
        i++;    
    }

    for (int i =0; i<test_cases; i++) {
        printf("%d\n", results[i]);
    }

}


unsigned int check_move(Bouncy * ptrBncy)
{
    // first case where it starts a loop
    // printf("N M i j d: %d %d %d %d %s\n", ptrBncy->n, ptrBncy->m, ptrBncy->i, ptrBncy->j, ptrBncy->direction);

    move_one(ptrBncy);
    // ptrBncy->bounces++;
    if (ptrBncy->moves == 1)
    {
        ptrBncy->initial_i[1] = ptrBncy->i;
        ptrBncy->initial_j[1] = ptrBncy->j;
    }

    // checks if the ball reached its destination
    if (ptrBncy->i == ptrBncy->i2 && ptrBncy->j == ptrBncy->j2) return ptrBncy->bounces;

    // checks if it touched the corners at least 2 times || if it started a infinite loop
    if (ptrBncy->corners > 1) return -1;

    else if (!check_loop(ptrBncy)) return -1;

    // if (ptrBncy->bounces > 100) return -1;
    
    
    check_move(ptrBncy);
}

int check_loop(Bouncy * ptrBncy)
{
// checks if this move and the next is equal to the first and second move (loop)
    if (ptrBncy->i == ptrBncy->initial_i[1] && ptrBncy->j == ptrBncy->initial_j[1])
    {
        return (ptrBncy->i_old-ptrBncy->initial_i[0]) + (ptrBncy->j_old-ptrBncy->initial_j[0]);
    }
}

void move_one(Bouncy * ptrBncy)
{   


    // move one based on the position + direction
    // DR -> 1; DL -> 2; UR -> 3; UL -> 4; 
    ptrBncy->moves++;
    // switch (*ptrBncy->direction)
    // {
    // case "DR":
    int count = 0;
    if (strcmp(ptrBncy->direction, "DR") == 0)
      {  
        char next[2] = {'D', 'R'};
        if (ptrBncy->i < ptrBncy->n) ptrBncy->i++; else {ptrBncy->i--; next[0] = 'U'; count++;};
        if (ptrBncy->j < ptrBncy->m) ptrBncy->j++; else {ptrBncy->j--; next[1] = 'L'; count++;};
        // *ptrBncy->("%c%c",next[0], next[0]);
        if (count) ptrBncy->bounces++;
        changeDirection("DR", next, ptrBncy);
        // break;
        }

    else if (strcmp(ptrBncy->direction, "DL")==0)
      {  
        char next[2] = {'D', 'L'};
        if (ptrBncy->i < ptrBncy->n) ptrBncy->i++; else {ptrBncy->i--; next[0] = 'U'; count++;};
        if (ptrBncy->j > 1) ptrBncy->j--; else {ptrBncy->j++; next[1] = 'R'; count++;};
        if (count) ptrBncy->bounces++;
        changeDirection("DL", next, ptrBncy);
        // break;
        }

    else if (strcmp(ptrBncy->direction, "UR")==0)
      {  
        char next[2] = {'U', 'R'};
        if (ptrBncy->i > 1) ptrBncy->i--; else {ptrBncy->i++; next[0] = 'D'; count++;};
        if (ptrBncy->j < ptrBncy->m) ptrBncy->j++; else {ptrBncy->j--; next[1] = 'L'; count++;};
        if (count) ptrBncy->bounces++;
        changeDirection("UR", next, ptrBncy);
        // break;
        }        

    else if (strcmp(ptrBncy->direction, "UL")==0)
      {  
        char next[2] = {'U', 'L'};
        if (ptrBncy->i > 1) ptrBncy->i--; else {ptrBncy->i++; next[0] = 'D'; count++;};
        if (ptrBncy->j > 1) ptrBncy->j--; else {ptrBncy->j++; next[1] = 'R'; count++;};
        if (count) ptrBncy->bounces++;
        changeDirection("UL", next, ptrBncy);
        // break;
        }
    
    // printf("Changed direction to: %s\n", ptrBncy->direction);
    // default:
    //     break;
    // }
}

void changeDirection(char previous[2], char next[2], Bouncy * ptrBncy)
{
    
    ptrBncy->direction[0] = next[0];
    ptrBncy->direction[1] = next[1];

    // if (previous[0] != next[0])
    for (int i =0; i < 2; i++) 
    {
        if (previous[i] == next[i]) return;
    
    }
    ptrBncy->corners++;
}
