/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** collisions.c
*/

#include "../include/my_radar.h"

void check_if_intersect(win_t *win, int i, int k, int j)
{
    if (sfFloatRect_intersects(&win->grid[i]->planes[j]->rect,
            &win->grid[i]->planes[k]->rect, NULL) == sfTrue) {
        win->grid[i]->planes[j]->is_flying = 0;
        win->grid[i]->planes[k]->is_flying = 0;
        win->grid[i]->planes[j]->as_landed = 1;
        win->grid[i]->planes[k]->as_landed = 1;
        win->grid[i]->planes[j]->is_crashed = 1;
        win->grid[i]->planes[k]->is_crashed = 1;
    }
}

void second_loop(win_t *win, int i, int j)
{
    for (int k = j + 1; win->grid[i]->planes[k] != NULL; k++) {
        if (win->grid[i]->planes[k]->is_flying == 1 &&
            win->grid[i]->planes[k]->is_controlled == 0 &&
            win->grid[i]->planes[k]->as_landed == 0) {
            check_if_intersect(win, i, k, j);
        }
    }
}

void first_loop(win_t *win, int i)
{
    for (int j = 0; win->grid[i]->planes[j] != NULL; j++) {
        if (win->grid[i]->planes[j]->is_flying == 1 &&
            win->grid[i]->planes[j]->is_controlled == 0 &&
            win->grid[i]->planes[j]->as_landed == 0) {
            second_loop(win, i, j);
        }
    }
}

void check_collisions(win_t *win)
{
    for (int i = 0; i < win->nb_grid; i++) {
        first_loop(win, i);
    }
}
