#include <stdio.h>

int main(void)
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
        printf("\n");
        while (game_type != 1 && game_type != 3)
        {
            printf("Je n'ai pas bien compris. (1) ou (3) ?\n");
            scanf("%d", &game_type);
        }
    }
    printf("%d\n", game_type);
    return game_type;
}