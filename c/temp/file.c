#include<stdio.h>
#include<stdlib.h>


int main(){
	FILE * f = fopen("arquivo.txt", "w");

	char t = '$';
	fwrite(&t, sizeof(char), 4, f);
	fclose(f);
}
