/*
** EPITECH PROJECT, 2022
** solver
** File description:
** main
*/

#include "solver.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int solver(struct alll *all)
{
    all->end_x -= 2;
    all->end_y -= 1;
    all->grille[all->end_y][all->end_x] = '*';
    all->path[all->end_y][all->end_x] = 1;
    all->grille[0][0] = '*';
    solver_maze(all);
    return (0);
}

int main(int argc, char **argv)
{
    struct alll all;
    char *strr = "USAGE\n    ./solver path_file/name_map\n";
    if (argc == 2)
        if (argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            write(1, strr, strlen(strr));
            return (1);
        }
    if (argc != 2)
        return (84);
    if (create_lab(&all, argv[1]) == 84)
        return (84);
    if (solver(&all) == 84)
        return (84);
    print_map(&all);
}
