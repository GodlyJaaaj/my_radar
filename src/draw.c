/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** Everything related to display
*/

#include "../include/my_radar.h"

void set_towers(win_t *win)
{
    for (int i = 0; i < win->nb_tower; i++) {
        sfSprite_setPosition(win->tower[i]->model->sprite,
            (sfVector2f){win->tower[i]->pos.x - (51.2 / 2),
                win->tower[i]->pos.y - (51.2 / 2)});
    }
}

void display_towers(win_t *win)
{
    for (int i = 0; i < win->nb_tower; i++) {
        sfRenderWindow_drawSprite(win->window,
            win->tower[i]->model->sprite,
            NULL);
    }
}

void display_tower_radius(win_t *win)
{
    for (int i = 0; i < win->nb_tower; ++i) {
        sfRenderWindow_drawCircleShape(win->window,
            win->tower[i]->hitboxe,
            NULL);
        sfRenderWindow_drawRectangleShape(win->window,
            win->tower[i]->land_area_shape,
            NULL);
    }
}

int show_grid(win_t *win)
{
    for (int i = 0; i < win->nb_grid; i++) {
        sfRenderWindow_drawRectangleShape(win->window,
            win->grid[i]->rect,
            NULL);
    }
    return 0;
}
