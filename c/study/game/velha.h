#include<assert.h>
#include<stdlib.h>

#ifndef _VELHA_H
#define _VELHA_H

#define P_1 1 // X
#define P_2 -1 // O

enum _game_status{ON, TIE, VICTORY};

typedef struct _game Game;

typedef enum _game_status GameStatus;

struct _game {
    int board[9];
    int player;
    GameStatus game_status;
};


/* Initializes the game, returning a pointer to the `Game` type and 
setting the `player` to player 1 and the board to 0 */
Game * initialize_game();

/* Puts the current players piece on the `pos` position on the board and, if sucessfull, changes the player

@param[in] game Game board
@param[in] pos Piece position
@return int `1` if successfull, `0` (false) if not (position already occupied)
*/
int put_piece(Game * game, int pos);

void check_game_state(Game* game);

void print_board(Game *game);

#endif
