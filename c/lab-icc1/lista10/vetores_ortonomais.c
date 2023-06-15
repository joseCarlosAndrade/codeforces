#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void preencher_vetor(int N, int *u, int *v);
int verificar_ortonomalidade(int N, int *u, int *v);

int main(void)
{
    int N;
    scanf("%d", &N);
    int *u = (int *)calloc(N, sizeof(int));
    int *v = (int *)calloc(N, sizeof(int));

    preencher_vetor(N, u, v);

    if (verificar_ortonomalidade(N, u, v)) printf("sao ortonormais\n");
    else printf("nao sao ortonormais\n");
}

void preencher_vetor(int N, int *u, int *v)
{
    for (int i = 0; i < N; i++) scanf("%d", (u+i));
    for (int i = 0; i < N; i++) scanf("%d", (v+i));
}

int verificar_ortonomalidade(int N, int *u, int *v)
{
    int soma = 0;

    for (int i = 0 ; i < N; i++) soma += *(u+i)* *(v+i);
    if (soma != 0) return 0;

    double mod_u = 0;
    double mod_v = 0;

    for (int i = 0; i < N; i++)
    {
        mod_u += (*(u+i))*(*(u+i));
        mod_v += (*(v+i))*(*(v+i));
        
    }

    mod_u = sqrt(mod_u);
    mod_v = sqrt(mod_v);

    if (mod_u == mod_v && mod_u == 1) return 1;
    
    return 0;
}
