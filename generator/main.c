/*
** EPITECH PROJECT, 2022
** generator
** File description:
** main
*/

#include "../includes/gen.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int gestion_deplacement(struct alll *all)
{
    if (all->count == 0) {
            all->nbr_cellule--;
            all->cellule[all->actu_cellule][0] =
            all->cellule[all->nbr_cellule][0];
            all->cellule[all->actu_cellule][1] =
            all->cellule[all->nbr_cellule][1];
    }
    if (all->cellule[all->actu_cellule][0] == all->x &&
    all->cellule[all->actu_cellule][1] == all->y) {
        return (1);
    }
    return (0);
}

int deplacement(struct alll *all)
{
    int directions[4][2] = {{-2, 0}, {0, 2}, {2, 0}, {0, -2}};
    for (int i = 0; i < 4; i++) {
        int next_celluleX =
        all->cellule[all->actu_cellule][0] + directions[i][0];
        int next_celluleY =
        all->cellule[all->actu_cellule][1] + directions[i][1];
        if ((next_celluleX >= 0 && next_celluleX < all->x) &&
        (next_celluleY >= 0 && next_celluleY < all->y)
        && all->grille[next_celluleX][next_celluleY] == 'X') {
            all->grille[next_celluleX - (directions[i][0] / 2)]
            [next_celluleY - (directions[i][1] / 2)] = '*';
            all->grille[next_celluleX][next_celluleY] = '*';
            all->cellule[all->nbr_cellule][0] = next_celluleX;
            all->cellule[all->nbr_cellule][1] = next_celluleY;
            all->nbr_cellule++;
            all->count++;
        }
    }
    return (0);
}

void free_all(struct alll *all)
{
    if (all->grille) {
        for (int i = 0; all->grille[i]; i++)
            free(all->grille[i]);
        free(all->grille);
    }
    if (all->cellule) {
        for (int i = 0; i < (all->y * all->x); i++)
            free(all->cellule[i]);
        free(all->cellule);
    }
}

int main(int argc, char **argv)
{
    struct alll all;
    char *strr = "USAGE\n    ./generator size_y size_x\n";
    if (argc == 2)
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            write(1, strr, my_strlen(strr));
            return (1);
        }
    if (verify(argc, argv, &all) == 84)
        return (84);
    generate(&all);
    generate_maze(&all);
    for (int i = 0, y = 0; all.perf != 0 && all.grille[i]; y++) {
        if (all.grille[i][y] == 'X' && rand() % all.x == 1)
            all.grille[i][y] = '*';
        if (all.grille[i][y] == '\0') {
            i++;
            y = - 1;
        }
    }
    print_map(&all);
    free_all(&all);
    return (0);
}
