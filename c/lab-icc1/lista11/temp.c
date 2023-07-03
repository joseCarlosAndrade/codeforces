#include<stdio.h>
#include<string.h>

int main(void)
{
	char * p = "12345";
	printf("%d", strlen(p));
	char * a = (char*) calloc(5, sizeof(char));
	printf("\n%s %d", a, strlen(a));
}
