#include<stdio.h>

int main(void)
{
    int corridas, tempo;
    float va, vb, distancia;

    scanf("%d", &corridas);

    for (int i = 0; i < corridas; i++)
    {
        scanf("%f %f %d", &va, &vb, &tempo);

        // casos em que nao ha corrida
        if (tempo == 0) {
            printf("A corrida ainda nao comecou\n");
            continue;
        }
        

        // casos em que há corrida
    


        if (va==0) {

            if (va == vb){
                printf("Os dois pilotos nao querem competir\n");
                continue;  
            }
            printf("O piloto A desistiu inesperadamente\n");
            continue;
        }
        if (vb==0) {
            if(vb == va){
                printf("Os dois pilotos nao querem competir\n");
                continue;  
            }
            printf("O piloto B desistiu inesperadamente\n");
            continue;
        }

        if (tempo < 0)
        {
            printf("De alguma forma os pilotos voltaram no tempo\n");
            continue;
        }   

        if (vb ==va){
             distancia = va * tempo;
                printf("Os karts empataram, percorrendo cada %.2fkm\n", distancia);
                continue;
        }

        if (va > vb)
        {
            distancia = va*tempo - vb*tempo;
            printf("O kart A venceu e percorreu %.2fkm a mais que o kart B\n", distancia);
            continue;
        }
        else{
            distancia = vb*tempo - va*tempo;
            printf("O kart B venceu e percorreu %.2fkm a mais que o kart A\n", distancia);

        }


    }
}