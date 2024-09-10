#include<string.h>
#include<stdlib.h>
#include<stdio.h>

int main() {
	char hella[20] = "hellb";
	char hellb[20] = "hellbdfas";

	int ret = strcmp(hella, hellb);
	printf("%d \n", ret);

}
