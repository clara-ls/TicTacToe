#include <stdio.h>
#include <stdlib.h>
#include "morpion.h"


void play_X(int loc, int *board)
{
    board[loc] = 1;
}

void play_O(int loc, int *board)
{
    board[loc] = 2;
}

int place(int *board, int player) // interactive with human player
{
    int loc;
    if (player == 1)
        printf("Où voulez-vous placer votre X ? ");
    else if (player == 2)
        printf("Où voulez-vous placer votre rond ? ");
    scanf("%d", &loc);
    while (loc < 1 || loc > 9 || board[loc-1] != 0)
    {
        printf("Cela n'est pas possible.\nOù voulez-vous vous placer ? ");
        scanf("%d", &loc);
    }
    return --loc;
}

int victory(int *board, int nb_turns)
{
    if (nb_turns < 3)
        return 0;
    for (int j = 1; j <= 2; j++)
    {
        if ((board[0] == j && board[1] == j && board[2] == j) ||
            (board[3] == j && board[4] == j && board[5] == j) ||
            (board[6] == j && board[7] == j && board[8] == j))
        {
            printf("Victoire pour joueur %d par ligne !\n", j);
            return j;
        }
        else if ((board[0] == j && board[3] == j && board[6] == j) ||
            (board[1] == j && board[4] == j && board[7] == j) ||
            (board[2] == j && board[5] == j && board[8] == j))
        {
            printf("Victoire pour joueur %d par colonne !\n", j);
            return j;
        }
        else if ((board[0] == j && board[4] == j && board[8] == j) ||
            (board[2] == j && board[4] == j && board[6] == j))
        {
            printf("Victoire pour joueur %d par diagonale !\n", j);
            return j;
        }
    }
    return 0;
}

void pvp(int *board) //player vs player
{
    int nb_turns = 0;

    show_board(board);    
    while (nb_turns < 9 && victory(board, nb_turns) == 0)
    {        
        play_X(place(board, 1), board);
        show_board(board);
        if (victory(board, nb_turns) == 1)
            return;
        nb_turns++;
        if (nb_turns < 8 && victory(board, nb_turns) == 0)
        {
            play_O(place(board, 2), board);
            nb_turns++;
        } 
        show_board(board);
        if (victory(board, nb_turns) == 1)
            return;   
        
    }
    return;  
}

int check_line(int* board) // checks if there is a winning line
{
    int i = 0;

    while (i < 7)
    {
        if (board[i] == 1 && board[i+1] == 1 && board[i+2] == 0)
        {
            play_O(i+2, board);
            return 1;
        }
        else if (board[i] == 1 && board[i+2] == 1 && board[i+1] == 0)
        {
            play_O(i+1, board);
            return 1;
        }
        else if (board[i+1] == 1 && board[i+2] == 1 && board[i] == 0)
        {
            play_O(i, board);
            return 1;
        }
        i+=3;
    }
    return 0;
}

int check_column(int* board) // checks if there is a winning columns
{
    int i = 0;

    while (i < 3)
    {
        if (board[i] == 1 && board[i+3] == 1 && board[i+6] == 0)
        {
            play_O(i+6, board);
            return 1;
        }
        else if (board[i] == 1 && board[i+6] == 1 && board[i+3] == 0)
        {
            play_O(i+3, board);
            return 1;
        }
        else if (board[i+3] == 1 && board[i+6] == 1 && board[i] == 0)
        {
            play_O(i, board);
            return 1;
        }
        i++;
    }
    return 0;
}

int check_diagonal(int* board) // checks if there is a winning diagonal
{
    int i = 0;
    int j = 8;

    while (i < 3)
    {
        if (board[i] == 1 && board[4] == 1 && board[j] == 0)
        {
            play_O(j, board);
            return 1;
        }
        else if (board[i] == 1 && board[j] == 1 && board[4] == 0)
        {
            play_O(4, board);
            return 1;
        }
        else if (board[4] == 1 && board[j] == 1 && board[i] == 0)
        {
            play_O(i, board);
            return 1;
        }
        i += 2;
        j = 6;
    }
    return 0;
}

void easy_opponent(int* board) // conditions to make an easy opponent
{
    if(board[4] == 0)
        play_O(4, board);
    else if (board[2] == 0)
        play_O(2, board);
    else if (board[8] == 0)
        play_O(8, board);
    else if (board[5] == 0)
        play_O(5, board);
    else if (board[0] == 0)
        play_O(0, board);
    else if (board[6] == 0)
        play_O(6, board);

}

int win_move(int *board) // play the winning move if there is one
{
    int i = 0;
    while (i < 7)
    {
        if (board[i] == 2 && board[i+1] == 2 && board[i+2] == 0)
        {
            play_O(i+2, board);
            return 1;
        }
        else if (board[i] == 2 && board[i+2] == 2 && board[i+1] == 0)
        {
            play_O(i+1, board);
            return 1;
        }
        else if (board[i+1] == 2 && board[i+2] == 2 && board[i] == 0)
        {
            play_O(i, board);
            return 1;
        }
        i+=3;
    }

    i = 0;
    while (i < 3)
    {
        if (board[i] == 2 && board[i+3] == 2 && board[i+6] == 0)
        {
            play_O(i+6, board);
            return 1;
        }
        else if (board[i] == 2 && board[i+6] == 2 && board[i+3] == 0)
        {
            play_O(i+3, board);
            return 1;
        }
        else if (board[i+3] == 2 && board[i+6] == 2 && board[i] == 0)
        {
            play_O(i, board);
            return 1;
        }
        i++;
    }

    i = 0;
    int j = 8;

    while (i < 3)
    {
        if (board[i] == 2 && board[4] == 2 && board[j] == 0)
        {
            play_O(j, board);
            return 1;
        }
        else if (board[i] == 2 && board[j] == 2 && board[4] == 0)
        {
            play_O(4, board);
            return 1;
        }
        else if (board[4] == 2 && board[j] == 2 && board[i] == 0)
        {
            play_O(i, board);
            return 1;
        }
        i += 2;
        j = 6;
    }
    
    return 0;
}

void game_over(int* board, int nb_turns)
{
    show_board(board);
    victory(board, nb_turns);
    return;
}

void pvc(int* board) // player vs computer (easy)
{
    int nb_turns = 0;
    int l = 0;
    int c = 0;
    int d = 0;

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
        win_move(board);
        if (victory(board, nb_turns) >= 1)
        {
            game_over(board, nb_turns);
            return;
        }
        
        c = 0;
        d = 0;
        l = check_line(board);
        if (l == 0)
            c = check_column(board);
        if (l == 0 && c == 0)
            d = check_diagonal(board);
        if (l == 1 || c == 1 || d == 1)
            nb_turns++;
        else if (nb_turns % 2 == 1)
        {
            easy_opponent(board);
            nb_turns++;
        }
        show_board(board);
    }
}

int select_type(void) // 3 options : player vs player - player vs easy computer - player vs hard computer (minimax)
{   
    int game_type = 0;

    printf("### Morpion ###\nBienvenue!\nVoulez-vous jouer contre l'ordinateur (1) ou bien à deux (2) ?\n");
    scanf("%d", &game_type);
    while (game_type != 1 && game_type != 2)
    {
        printf("Je n'ai pas bien compris. (1) ou (2) ?\n");
        scanf("%d", &game_type);
    }
    if (game_type == 1)
    {
        printf("Niveau facile (1) ou difficile (3) ?\n");
        scanf("%d", &game_type);
        while (game_type != 1 && game_type != 3)
        {
            printf("Je n'ai pas bien compris. (1) ou (3) ?\n");
            scanf("%d", &game_type);
        }
    }
    return game_type;
}