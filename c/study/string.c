#include<stdio.h>

unsigned int string_length(char * string);

int main(void)
{
    char *string = "constant string!";
    char *string_copy = string;

    while (*string != 0)
    {
        putchar(*string++);
    }

    putchar('\n');

    printf("length of the string '%s': %d. \nThe string will turn to: %s.\n", string_copy, string_length(string_copy), string_copy);
}

unsigned int string_length(char * string)
{
    int i = 0;
    while (*string++ != 0) i++;


    return i;
}