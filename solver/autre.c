/*
** EPITECH PROJECT, 2022
** solver
** File description:
** autre
*/

#include "solver.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int free_tab(char **tab)
{
    if (tab) {
        for (int i = 0; tab[i]; i++)
            free(tab[i]);
        free(tab);
    }
    return (0);
}

int free_int(int **tab)
{
    if (tab) {
        for (int i = 0; tab[i] != NULL; i++) {
            free(tab[i]);
        }
        free(tab);
    }
    return (0);
}

int print_map(struct alll *all)
{
    for (int i = 0; all->grille[i] != NULL; i++) {
        printf("%s", all->grille[i]);
        if (all->grille[i + 1] != NULL)
            printf("\n");
    }
    free_tab(all->grille);
    free_int(all->path);
    free_int(all->cellule);
    return (0);
}
