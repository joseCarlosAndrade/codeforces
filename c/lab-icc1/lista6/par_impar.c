#include<stdio.h>

int main(void)
{
    char jogador1[10];
    char jogador2[10];
    int rodadas, a , b, paridade, i =0;

    scanf("%s %s", jogador1, jogador2);
    scanf("%d", &paridade);
    scanf("%d", &rodadas);

    while(i < rodadas)    
    {
        scanf("%d %d", &a, &b);
        // caso a == b == 0, refaz a rodada
        if (a+b) {
            if( (a+b)%2){
                if (paridade){
                    printf("%s venceu!\n", jogador1);
                }
                else{
                printf("%s venceu!\n", jogador2);
                }
            }
            else{
                if (paridade==0){
                    printf("%s venceu!\n", jogador1);
                }
                else{
                printf("%s venceu!\n", jogador2);
                }
            }
        }
        else{
        printf("Refazendo a rodada\n");
        continue;
        }

        i++;
    }
}