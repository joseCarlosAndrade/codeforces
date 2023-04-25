#include <stdio.h>

typedef struct NextStruct {
    int x, y, z;
    char * output;
} NextStruct;

typedef struct Struct
{
    NextStruct * nextPtr;
} Struct;

void changeValue(Struct * ptr);
void displayValue(Struct * ptr);

int main(void)

{
    NextStruct next;
    next.x = 10;
    next.y = 100;

    Struct stru, * ptrStru = &stru;
    stru.nextPtr = &next;



    printf("%d\n", stru.nextPtr->x);

    changeValue(ptrStru);
    displayValue(ptrStru);
}

void changeValue(Struct * ptr)
{
    ptr->nextPtr->x = 0;
    ptr->nextPtr->output = "aaaa";
}

void displayValue(Struct * ptr)
{
    printf("%d %s\n", ptr->nextPtr->x, ptr->nextPtr->output);
}