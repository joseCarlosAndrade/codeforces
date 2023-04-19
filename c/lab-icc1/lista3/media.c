#include<stdio.h>
#include<math.h>

int main(void)
{
    float media_a, media_g, media_h;
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c); 

    media_a = (a + b + c) /3;
    media_g = cbrt(a * b * c);
    media_h = 3 / ( 1/a + 1/b + 1/c );

    printf("Media aritimetica: %.4f \nMedia harmonica: %.4f \nMedia geometrica: %.4f\n", media_a, media_h, media_g);
    
}
