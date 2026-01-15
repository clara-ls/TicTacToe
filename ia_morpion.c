#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"

int evaluate_state(int *board, int nb_turns) // returns score of ending state (positive if winning, negative if loosing, else 0)
{
    for (int j = 1; j <= 2; j++)
    {
        if ((board[0] == j && board[1] == j && board[2] == j) ||
            (board[3] == j && board[4] == j && board[5] == j) ||
            (board[6] == j && board[7] == j && board[8] == j))
        {
            if (j == 1)
                return nb_turns - 10;
            else
                return 10 - nb_turns;
        }
        else if ((board[0] == j && board[3] == j && board[6] == j) ||
            (board[1] == j && board[4] == j && board[7] == j) ||
            (board[2] == j && board[5] == j && board[8] == j))
        {
            if (j == 1)
                return nb_turns - 10;
            else
                return 10 - nb_turns;
        }
        else if ((board[0] == j && board[4] == j && board[8] == j) ||
            (board[2] == j && board[4] == j && board[6] == j))
        {
            if (j == 1)
                return nb_turns - 10;
            else
                return 10 - nb_turns;
        }
    }
    return 0;
}

int *list_free_tiles(int *board) // list the remaining free tiles of the board
{
    int *list_free_tiles;
    int j = 0;

    list_free_tiles = malloc(sizeof(int) * 9);
    for (int index = 0; index < 9; index++)
        list_free_tiles[index] = -1;

    for (int i = 0; i < 9; i++)
        if (board[i] == 0)
        {
            list_free_tiles[j] = i;
            j++;
        }
    return list_free_tiles;
}

int is_full(int *board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == 0)
            return 0;
    }
    return 1;
}


int miniMax(int *board, int depth, int is_maxiplayer)
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
                score_tile = miniMax(board, depth-1, 0);
                board[free_tiles[i]] = 0;
                if (score_tile > score)
                    score = score_tile;
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
                score_tile = miniMax(board, depth-1, 1);
                board[free_tiles[i]] = 0;
                if (score_tile < score)
                    score = score_tile;
            }
        }
    }
    free(free_tiles);
    return score;
}

int best_move(int *board, int depth, int *nb_operations) // selects best option according to minimax
{
    int alpha = -1000;
    int beta = 1000;
    int move = -1;
    int score = -1000;
    int score_tile;
    int *free_tiles;
    free_tiles = list_free_tiles(board);

    for (int i = 0; i < 9; i++)
        {
            if (free_tiles[i] != -1)
            {
                board[free_tiles[i]] = 2;
                //score_tile = miniMax(board, depth-1, 0);
                score_tile = alpha_beta(board, depth-1, alpha, beta, 0, nb_operations);
                board[free_tiles[i]] = 0;
                if (score_tile > score)
                {
                    score = score_tile;
                    move = free_tiles[i];
                }
                //printf("tile %d, score = %d\n", free_tiles[i], score_tile);
            }
        }
    //free(free_tiles);
    return move;
}

void pvminiMax(int* board) // player versus minimax (impossible-to-beat computer)
{
    int nb_turns = 0;
    int nb_operations = 0;

    show_board(board);
    
    while (nb_turns < 9 && victory(board, nb_turns) == 0)
    {
        
        play_X(place(board, 1), board);
        nb_turns++;
        show_board(board);
        if (victory(board, nb_turns) >= 1)
        {
            game_over(board, nb_turns);
            return;
        }
        
        play_O(best_move(board, 9-nb_turns, &nb_operations), board);
        nb_turns++;

        if (victory(board, nb_turns) >= 1)
        {
            game_over(board, nb_turns);
            return;
        }
        
        show_board(board);
        printf("%d\n", nb_operations);
    }
}