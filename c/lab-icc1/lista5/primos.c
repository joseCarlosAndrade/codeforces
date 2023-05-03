#include<stdio.h>

int main(void)
{
    int numero, contador = 1, ultimo_primo = -1, not_primo = 0;


    scanf("%d", &numero);

    while(numero >1)
    {
        // if (numero == 1) {break;};

        for (int num = 2; num <= numero; num++) 
        {
            // printf("numero: %d, num: %d\n", numero, num);

            // encontrar numeros primos

            for (int i = 2; i < num; i++)
            {
                if (num%i ==0){
                    not_primo++;
                }
            }
            
            if (not_primo){
                not_primo = 0;
                continue;
                
            }
            else {
                // printf("primo: %d\n", num);
                if (numero%num==0) {
                    // printf("Numero %d é divisivel por %d\n", numero, num);

                    // açoes vao aqui

                    if (ultimo_primo == -1)
                    {
                        ultimo_primo = num;
                    }
                    else if (num == ultimo_primo)
                    {
                        contador++;
                        
                    }
                    else {
                        
                        printf("%d %d\n", ultimo_primo, contador);
                        ultimo_primo = num;
                        contador = 1;
                        
                    }

                    numero = numero / num;
                    break;
                            // printf("numero: %d %d\n", numero, num);
                }
            }
            // not_primo = 0;
        }
    }
    printf("%d %d\n", ultimo_primo, contador);
}