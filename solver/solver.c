/*
** EPITECH PROJECT, 2022
** solver
** File description:
** solver
*/

#include "solver.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int show_path2(struct alll *all)
{
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int next_X = all->i + directions[i][0];
        int next_Y = all->y + directions[i][1];
        if ((next_X >= 0 && next_X <= all->end_x)
        && (next_Y >= 0 && next_Y <= all->end_y)
        && all->path[next_Y][next_X] != 0
        && all->path[next_Y][next_X] < (all->path[all->y][all->i])) {
            all->i = next_X;
            all->y = next_Y;
            all->grille[next_Y][next_X] = 'o';
            count++;
            return (0);
        }
    }
    if (count == 0)
        return (1);
    return (0);
}

int show_path(struct alll *all)
{
    int end = 0;
    for (all->i = 0, all->y = 0; end != 1;) {
        end = show_path2(all);
        if (all->i == all->end_x && all->y == all->end_y)
            end = 1;
    }
    all->grille[0][0] = 'o';
    all->grille[all->end_y][all->end_x] = 'o';
    for (int i = 0, y = 0; all->grille[i]; y++) {
        if (all->grille[i][y] == '.')
            all->grille[i][y] = '*';
        if (all->grille[i][y] == '\0') {
            i++;
            y = - 1;
        }
    }
    return (0);
}

int gestion_deplacement(struct alll *all)
{
    if (all->count == 0) {
            all->nbr_cellule--;
            all->cellule[all->actu_cellule][0] =
            all->cellule[all->nbr_cellule][0];
            all->cellule[all->actu_cellule][1] =
            all->cellule[all->nbr_cellule][1];
    }
    if (all->cellule[all->actu_cellule][0] == 0 &&
    all->cellule[all->actu_cellule][1] == 0) {
        return (1);
    }
    return (0);
}

int deplacement(struct alll *all)
{
    int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i = 0; i < 4; i++) {
        int next_celluleX =
        all->cellule[all->actu_cellule][0] + directions[i][0];
        int next_celluleY =
        all->cellule[all->actu_cellule][1] + directions[i][1];
        if ((next_celluleX >= 0 && next_celluleX <= all->end_x)
        && (next_celluleY >= 0 && next_celluleY <= all->end_y)
        && all->grille[next_celluleY][next_celluleX] == '*') {
            all->grille[next_celluleY][next_celluleX] = '.';
            all->path[next_celluleY][next_celluleX] =
            ((all->path[all->cellule[all->actu_cellule][1]]
            [all->cellule[all->actu_cellule][0]] ) + 1);
            all->cellule[all->nbr_cellule][0] = next_celluleX;
            all->cellule[all->nbr_cellule][1] = next_celluleY;
            all->nbr_cellule++;
            all->count++;
        }
    }
    return (0);
}

int solver_maze(struct alll *all)
{
    srand(time(NULL));
    all->cellule = malloc(sizeof(int*) * ((all->end_x * all->end_y) + 1));
    all->cellule[(all->end_x * all->end_y)] = NULL;
    for (int i = 0; i < (all->end_x * all->end_y); i++)
        all->cellule[i] = malloc(sizeof(int) * 2);
    all->nbr_cellule = 1;
    all->cellule[0][0] = all->end_x;
    all->cellule[0][1] = all->end_y;
    while (all->nbr_cellule > 0) {
        all->actu_cellule = rand() % all->nbr_cellule;
        all->count = 0;
        deplacement(all);
        if (gestion_deplacement(all) == 1)
            break;
    }
    show_path(all);
    return (0);
}
