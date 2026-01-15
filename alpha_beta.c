#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

int alpha_beta(int *board, int depth, int alpha, int beta, int is_maxiplayer, int *nb_operations)
{
    int score;
    int score_tile;
    int *free_tiles;
    free_tiles = list_free_tiles(board);

    if (evaluate_state(board, depth) != 0 || is_full(board))
        return evaluate_state(board, depth);
    
    else if (is_maxiplayer)
    {
        score = -1000;
        for (int i = 0; i < 9; i++)
        {
            if (free_tiles[i] != -1)
            {
                board[free_tiles[i]] = 2;
                (*nb_operations)++;
                score_tile = alpha_beta(board, depth-1, alpha, beta, 0, nb_operations);
                board[free_tiles[i]] = 0;
                if (score_tile > score)
                    score = score_tile;
                if (alpha < score)
                    alpha = score;
                if (beta < alpha)
                    break;
            }
        }
    }
    
    else
    {
        score = 1000;
        for (int i = 0; i < 9; i++)
        {
            if (free_tiles[i] != -1)
            {
                board[free_tiles[i]] = 1;
                (*nb_operations)++;
                score_tile = alpha_beta(board, depth-1, alpha, beta, 1, nb_operations);
                board[free_tiles[i]] = 0;
                if (score_tile < score)
                    score = score_tile;
                if (beta > score)
                    beta = score;
                if (beta < alpha)
                    break;
            }
        }
    }
    free(free_tiles);
    return score;
}