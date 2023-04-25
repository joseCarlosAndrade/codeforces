#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define SCREEN_WIDTH 70
#define SCREEN_HEIGHT 35
#define BOORDER_WIDTH 35

typedef struct Piece
{
    int x, y;
    
    int form_one[8];
} Piece;


typedef struct Screen
{
    int width, height;
    char output[SCREEN_WIDTH][SCREEN_HEIGHT];

    int cur_piece, next_piece;

    Piece * cur_piece_struct;
} Screen;


void render(Screen * screen);
void init_blank_screen(Screen * screen);
Piece * create_piece(Screen * screen);
void fall_piece(Screen * screen);

void clear_lines(Screen * screen);

int main(void)
{
    Screen screen;
    Screen * ptrScreen = &screen;
    screen.width = SCREEN_WIDTH-2;
    screen.height = SCREEN_HEIGHT-2;
    screen.next_piece = 0;
    
    Piece * curr = create_piece(ptrScreen);
    screen.cur_piece_struct = curr;
    init_blank_screen(ptrScreen);
    
    render(ptrScreen);
}

void render(Screen * screen)
{
    // resets screen
    printf("\x1b[H");

    for (int j = 0; j < SCREEN_HEIGHT; j++)
    {
        for (int i = 0; i < SCREEN_WIDTH; i++)
        {
            putchar(screen->output[i][j]);
        }
        putchar('\n');
    }
}

void init_blank_screen(Screen * screen)
{
    // initializes the screen with empy spaces
    memset(screen->output, '.', sizeof(char)*SCREEN_HEIGHT*SCREEN_WIDTH);

    for (int j = 0; j < SCREEN_HEIGHT; j++)
    {
       
       if (j == 0 || j == SCREEN_HEIGHT-1) 
       { 
        for (int i = 0; i < BOORDER_WIDTH; i++)
            {
                screen->output[i][j] = '#';
            }
            }
        else 
        {
            screen->output[0][j] = '#';
            screen->output[BOORDER_WIDTH-1][j] = '#';

        }
    }
    // int index = 0;
    // while (1)
    // {
    //     // ERRO AQUIIII
    //     int x = screen->cur_piece_struct->x;
    //     // screen->output[index++][index++] = '@';
        
    //     // index++;
    // }
}

Piece * create_piece(Screen * screen)
{
    switch (screen->next_piece)
    {
    case 0:
        {Piece square;
        Piece * ptrSquare = &square;
        square.x = screen->width/2 + 1;
        square.y = 2;
        square.form_one[0] = square.x;
        square.form_one[1] = square.y;
        square.form_one[2] = square.x+1;
        square.form_one[3] = square.y;
        square.form_one[4] = square.x;
        square.form_one[5] = square.y+1;
        square.form_one[6] = square.x+1;
        square.form_one[7] = square.y+1;

        screen->cur_piece = 0;

        return ptrSquare;
        break;}
    
    default:
        break;
    }
    return 0;
}
