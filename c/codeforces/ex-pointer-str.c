#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void append(char * s, char c);

int main()
{
    char * next;
    char d[7];
    scanf("%s", d);
    next = malloc(8);
    
    strcpy(next, d);
    printf("%s", next);
    append(next, 'D');
    // next[0] = 'F';
    printf("%s", next);

    // printf("%c",*(next+1));
    // printf("%s %c", *next, next[1]);
    // next[0] = "L";
    // *(next+1) = 'P';
    // printf("%s", *next);
}

void append(char * s, char c)
{
    int len = strlen(s);
    printf("%d", len);
    s[len-3] = c;
    s[len+1] = '\0';
}