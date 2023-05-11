#include<stdio.h>

int main(void)
{
    int n, atual, cond = 1;
    scanf("%d", &n);

    for (int i = 0; i <n; i++)
    {
        // printf("a\n");
        scanf("%d", &atual);
        if (atual == 1 || atual == 2) {
                printf("%d eh primo.\n", atual);
                continue;
            }

        int novo = atual;

        int primo_primeiro = 1;
        for (int j = 2; j<novo; j++){
            
            if (novo % j == 0) {
                printf("%d nao eh primo, ", novo);
                cond = 1;
                primo_primeiro = 0;
                while (cond)
                {
                    novo++;

                    int primo = 1;
                    for (int k = 2; k < novo; k++)
                    {
                        if (novo % k == 0) primo = 0;

                        
                    }
                    if (primo){
                        printf("o proximo primo eh %d.\n", novo);
                        cond = 0;
                        primo = 1;
                        break;
                    }
                    
                    
                }
                continue;
            }

        }
        if (primo_primeiro)    printf("%d eh primo.\n", atual);

    }
}