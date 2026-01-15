#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

void clear_screen()
{
    printf("\033[H\033[J");
}

void show_board(int *board)
{
    int n;
    n = 0;
    //clear_screen();
    printf("##################\n");
    while (n < 10)
    {
        printf("| ");
        if (board[n] == 1)
            printf("X ");
        else if (board[n] == 2)
            printf("O ");
        else
            printf("  ");
        if (n == 2 || n == 5)
        {
            printf("| ");
            printf("\n");
            printf("-------------\n");
            
        }
            
        n++;

    }
    printf("\n");
    printf("##################\n");
}