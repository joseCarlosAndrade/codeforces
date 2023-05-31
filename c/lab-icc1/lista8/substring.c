#include<stdio.h>
#include<string.h>

void replace_substring(char *sub_ptr, char substring[]);
int return_string_length(char string[]);


int main(void)
{
    char string_1[10000], substring[10000];
    int not_found = 1;

    scanf("%[^\n]s", string_1);
    scanf(" %[^\n]s", substring);

    // printf("%s ; %s", string_1, substring);
    while (1)
    {

        char * ptr = strstr(string_1, substring);
        if ( ptr != NULL) {
            not_found = 0;
            int index = ptr - string_1;

            printf("A sub string foi encontrada na posicao = %d\n", index);
            replace_substring(ptr, substring);
            // printf("sub: %s\n", string_1);

        }
        else
         {
            if (not_found) printf("A sub string nao foi encontrada\n");
            break;
         }
    }
}

void replace_substring(char *sub_ptr, char substring[])
{
    int sub_size = return_string_length(substring);

    for (int i = 0; i < sub_size; i++)
    {
        *(sub_ptr+i) = '/';
    }

}

int return_string_length(char string[])
{
    int size = 0;

    while (string[size] != 0) size++;
    
    return size;
}