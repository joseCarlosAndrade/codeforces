#include <stdio.h>

int main(void)
{
    int a1, b1 ,c1, a2, b2, c2;
    float m1, m2;

    scanf("%d %d %d", &a1, &b1, &c1);
    scanf("%d %d %d", &a2, &b2, &c2);

    // calula coeficientes angulares de cada reta
    m1 = (a1/b1) * -1;
    m2 = (a2/b2) * -1;

    if (m1 == m2) 
    {
        printf("As retas sao paralelas.\n");
    }
    else {
        /*
        Calculo do cruzamento: igualar y = -a1*x/b1 - c1/b1 com y = -a2*x/b2 - c2/b2 
        Nos leva a :
        x = (-c2*b1 + c1*b2)/(a2*b1 - a1*b2)
        Colocando o x encontrado em qualquer das equacoes, podemos encontrar o y do cruzamento. 
        Desse modo temos x e y do cruzamento, nos permitindo saber o quadrante
        */
       float x = (-c2*b1 + c1*b2)/(a2*b1 - a1*b2);
       float y = -a1*x/b1 - c1/b1;

       

        
        
        // Caso o cruzamento nao aconteca em nenhum dos eixos 
        if (x && y)
        {
            int quadrante =  (x >0) ? ((y>0) ? 1 : 4) : ((y>0) ? 2 : 3);
            printf("As retas se cruzam no %d° quadrante.\n", quadrante);
        }
        else if (x==0 && y)
        {
            printf("As retas se cruzam no eixo y.\n");
        }
        else if (y==0 && x)
        {
            printf("As retas se cruzam no eixo y.\n");
        }
        else {
            printf("As retas se cruzam na origem.\n");
        }
       
    }
    

}
