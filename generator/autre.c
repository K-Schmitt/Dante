/*
** EPITECH PROJECT, 2022
** generator
** File description:
** generator
*/

#include "../includes/gen.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int my_strlen(const char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return (i);
}

int verify(int argc, char **argv, struct alll* all)
{
    if (argc < 3 && argc > 4)
        return (84);
    all->perf = -1;
    if (argv[3]) {
        all->perf = strcmp(argv[3], "perfect");
        if (all->perf != 0)
            return (84);
    }
    all->x = my_atoi(argv[1]);
    if (all->x == -1)
        return (84);
    all->y = my_atoi(argv[2]);
    if (all->y == -1)
        return (84);
    return (0);
}

int generate_maze(struct alll *all)
{
    srand(time(NULL));
    all->cellule = malloc(sizeof(int*) * (all->x * all->y));
    for (int i = 0; i < (all->x * all->y); i++)
        all->cellule[i] = malloc(sizeof(int) * 2);
    all->nbr_cellule = 1;
    all->cellule[0][0] = 0;
    all->cellule[0][1] = 0;
    while (all->nbr_cellule > 0) {
        all->actu_cellule = rand() % all->nbr_cellule;
        all->count = 0;
        deplacement(all);
        if (gestion_deplacement(all) == 1)
            break;
    }
    all->grille[all->x - 1][all->y - 1] = '*';
    if (all->x % 2 == 0) {
        all->grille[all->x - 2][all->y - 1] = '*';
    }
    return (0);
}

int generate(struct alll *all)
{
    all->grille = malloc(sizeof(char *) * (all->x + 1));
    int i = 0;
    for (; i < all->x; i++) {
        all->grille[i] = malloc(sizeof(char) * (all->y + 1));
        for (int b = 0; b < all->y; b++)
            all->grille[i][b] = 'X';
        all->grille[i][all->y] = '\0';
    }
    all->grille[all->x] = NULL;
    return (0);
}

int print_map(struct alll *all)
{
    for (int i = 0; all->grille[i] != NULL; i++) {
        printf("%s", all->grille[i]);
        if (all->grille[i + 1] != NULL)
            printf("\n");
    }
    return (0);
}
