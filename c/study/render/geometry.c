#include<stdio.h>
#include<math.h>
#include<string.h>


typedef struct Projection
{
    float theta_spacing, phi_spacing;

    int screen_width, screen_height;

    float R1, R2, K1, K2;
} Projection;

void render(float theta, float phi, Projection * ptrProj);


int main(void)
{
    Projection projection;
    projection.screen_width = 100;
    projection.screen_height = 30;

    projection.theta_spacing = 0.07;
    projection.phi_spacing = 0.07;

    
    // printf("%s", projection.output);
    projection.R1 = 1; // raio
    projection.R2 = 2; // centro do circulo partindo do eixo x

    projection.K2 = 100;
    // calcular K1 , o desenvolvimento e razao da conta estao no meu caderno
    projection.K1 = ((projection.screen_height*0.4 * projection.K2) / (projection.R1 + projection.R2));
    Projection * ptrProj = &projection;

    render(10.0, 10.0, ptrProj);
}   

void render(float A, float B, Projection * ptrProj)
{

    char output[100][30];
    memset(output, ' ', sizeof(char)*ptrProj->screen_height*ptrProj->screen_width);
//     char output[71][21];

    // for (int j = 0; j < ptrProj->screen_height; j++)
    // {
        // for (int i = 0; j < ptrProj->screen_width; i++)
        // {
            // output[i][j] = '#';
    //     // }
    // }

    // char z_buffer[200][100] = {0};

    for (float theta = 0; theta < 2*3.14; theta+= ptrProj->theta_spacing)
    {
        float cos_t = cos(theta);
        float sin_t = sin(theta);
    
        float circlex = (ptrProj->R2 + ptrProj->R1*cos_t);
        float circley = (ptrProj->R1*sin_t);
        float circlez = ptrProj->K2;

        // Projecao
        float z_inverso = 1/circlez;
        // printf("%f", z_inverso);

        // e preciso adicionar metade da tela pois o circulo foi definido a partir da metade
        // e o sistema de coordenadas comeca no canto
        // alem disso, y deve ser invertido pois no nosso sistema y+ para cima
        // porem o buffer que definimos toma y+ para baixo
        int x = (int) (ptrProj->screen_width/2 + ( ptrProj->K1 * circlex * z_inverso));
        int y = (int) (ptrProj->screen_height/2 - (ptrProj->K1 * circley * z_inverso));
        // printf("%d %d ;" , x, y);
        
        // if ()
        // {
            output[x][y] = 'O';
        // }
        // for (float phi = 0; phi < 2*3.14; phi += ptrProj->phi_spacing)
        // {
        //     float cos_p = cos(phi);
        //     float sin_p = sin(phi);

        //     //  coordenadas na frame absoluta do mundo 
        //     float circleX = (ptrProj->R2 + ptrProj->R1*cos_t)*cos_p;
        //     float circleY = (ptrProj->R1*sin_t);    
        // }
    }

    // printf("\x1b[H");
    for (int j = 0; j < ptrProj->screen_height; j++)
    {
        for (int i = 0 ; i <ptrProj->screen_width; i++)
        {
            putchar(output[i][j]);
        }
        putchar('\n');
    }
    
    
}