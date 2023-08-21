#include "stdlib.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"


void new_print(char*str,...){
 
    va_list args;
    va_start(args, str);
    
    uint param;
    for (int i = 0; i < strlen(str); i++)
    {
        if(i!=strlen(str)-1 && str[i]=='%'){
            if(str[i+1]=='u'){
                param = va_arg(args, uint);
                printf("%u", param);
                i++;
            }else {printf("%c", str[i]);}
        
        }else{printf("%c", str[i]);}
    }
    

}




int main(){

char str[]= "teste %u  askibasgfuisdbga % %u %u%u bla\n";

new_print(str, 1556251, 1626 , 1726, 125);



}