/*
** EPITECH PROJECT, 2022
** gen.h
** File description:
** generator
*/

#pragma once

struct alll {
    char **grille;
    int **cellule;
    int nbr_cellule;
    int actu_cellule;
    int count;
    int x;
    int y;
    int perf;
};

int my_natoi(const char *format, int i);
int my_atoi(const char *format);
int my_strlen(const char *str);
int verify(int argc, char **argv, struct alll* all);
int print_map(struct alll *all);
int generate(struct alll *all);
int generate_maze(struct alll *all);
int gestion_deplacement(struct alll *all);
int deplacement(struct alll *all);
