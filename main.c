#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

int main(void)
{
    int *board;
    board = calloc(9, sizeof(int));

    if (board == 0)
    {
        printf("Calloc failed\n");
        return 1;
    }

    char game_type = select_type();
    
    if (game_type == 1)
        pvc(board);
    else if (game_type == 2)
        pvp(board);
    else if (game_type == 3)
        pvminiMax(board);
    
    free(board);
    
    printf("Fin de la partie.\n");
}