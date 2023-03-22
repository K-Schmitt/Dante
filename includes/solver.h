/*
** EPITECH PROJECT, 2022
** solver.h
** File description:
** solver
*/

#pragma once

struct alll {
    char **grille;
    int **path;
    int **cellule;
    int nbr_cellule;
    int actu_cellule;
    int count;
    int end_x;
    int end_y;
    int i;
    int y;
};

int free_tab(char **tab);
char *my_strcpy(char *dest, char const *src);
int print_map(struct alll *all);
int create_lab(struct alll *all, char *pmap);
int solver(struct alll *all);
int solver_maze(struct alll *all);
