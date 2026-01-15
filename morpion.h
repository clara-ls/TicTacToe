#ifndef MORPION_H
#define MORPION_H

//select game and set the board
int select_type(void);

//player versus player
void pvp(int *board);

//moves
void play_X(int loc, int *board);
void play_O(int loc, int *board);
int place(int *board, int player);

//check for victory
int victory(int *board, int nb_turns);
void game_over(int* board, int nb_turns);

//player versus computer (easy)
void pvc(int* board);

//defensive
int check_line(int* board);
int check_column(int* board);
int check_diagonal(int* board);

//aggressive
void easy_opponent(int* board);
int win_move(int *board);

//player versus minimax (impossible-to-beat)
int *list_free_tiles(int *board);
int is_full(int *board);
int evaluate_state(int *board, int nb_turns);
int miniMax(int *board, int depths, int is_maxiplayer);
int best_move(int *board, int depths, int *nb_operations);
void pvminiMax(int* board);

// alpha_beta (optimised version of minimax)
int alpha_beta(int *board, int depth, int alpha, int beta, int is_maxiplayer, int *nb_operations);

//affichage
void clear_screen();
void show_board(int *board);

#endif