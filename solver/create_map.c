/*
** EPITECH PROJECT, 2022
** solver
** File description:
** create map
*/

#include "solver.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static int sizmap(char *map)
{
    char *line = NULL;
    size_t len = 50;
    FILE *fp = fopen(map, "r");
    int size = 0;
    while (getline(&line, &len, fp) != -1) {
        size++;
    }
    if (line)
        free(line);
    fclose(fp);
    return (size);
}

static int malloc_tab(struct alll *all, char *line)
{
    all->end_x = strlen(line);
    all->grille = malloc(sizeof(char*) * (all->end_y + 1));
    all->path = malloc(sizeof(int*) * (all->end_y + 1));
    for (int i = 0; i < all->end_y; i++) {
        all->grille[i] = malloc(sizeof(char) * (all->end_x + 1));
        all->path[i] = malloc(sizeof(int) * (all->end_x + 1));
    }
    all->grille[all->end_y] = NULL;
    all->path[all->end_y] = NULL;
    strcpy(all->grille[0], line);
    all->grille[0][all->end_x - 1] = '\0';
    for (int i = 0; all->path[i]; i++) {
        all->path[i][all->end_x - 1] = 0;
        for (int y = 0; y < all->end_x; y++)
            all->path[i][y] = 0;
    }
    return (0);
}

int create_lab(struct alll *all, char *pmap)
{
    char *line = NULL;
    size_t len = 50;
    FILE *fp = fopen(pmap, "r");
    all->end_y = sizmap(pmap);
    if (getline(&line, &len, fp) < 0)
        return (84);
    malloc_tab(all, line);
    for (int i = 1; i < all->end_y; i++) {
        if (getline(&line, &len, fp) < 0)
            return (12);
        strcpy(all->grille[i], line);
        all->grille[i][all->end_x - 1] = '\0';
    }
    if (line)
        free(line);
    fclose(fp);
    return (0);
}
