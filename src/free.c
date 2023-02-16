/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** free.c
*/

#include "../include/my_radar.h"

void free_clocks(win_t *win)
{
    sfClock_destroy(win->main_time);
    sfClock_destroy(win->clock_plane);
    sfClock_destroy(win->fps_clock);
}

void free_colors(win_t *win)
{
    free(win->colors);
}

void free_grids(win_t *win)
{
    for (int i = 0; i < win->nb_grid; i++) {
        free(win->grid[i]->planes);
        sfRectangleShape_destroy(win->grid[i]->rect);
    }
    free(win->grid);
}

void destroy_sprite_t(win_t *win)
{
    sfTexture_destroy(win->plane_s->texture);
    sfTexture_destroy(win->tower_s->texture);
    free(win->tower_s); free(win->plane_s);
    sfTexture_destroy(win->background->texture);
    sfSprite_destroy(win->background->sprite);
    free(win->background);
}

void free_all(win_t *win)
{
    sfRenderWindow_destroy(win->window);
    free_clocks(win); destroy_sprite_t(win);
    free(win->event);
    for (int i = 0; i < win->nb_tower; i++) {
        sfSprite_destroy(win->tower[i]->model->sprite);
        sfCircleShape_destroy(win->tower[i]->model->radius);
        sfRectangleShape_destroy(win->tower[i]->land_area_shape);
        free(win->tower[i]->model);
        free(win->tower[i]);
    }
    for (int i = 0; i < win->nb_plane; i++) {
        free(win->plane[i]->collision_points);
        sfSprite_destroy(win->plane[i]->model->sprite);
        sfRectangleShape_destroy(win->plane[i]->hitboxe);
        free(win->plane[i]->model);
        free(win->plane[i]);
    } sfRectangleShape_destroy(win->time_rect);
    free_grids(win); free_colors(win); sfText_destroy(win->time_text);
    free(win->plane); free(win->tower); free(win->xy);
    free(win);
}
