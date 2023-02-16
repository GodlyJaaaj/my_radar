/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** planes2.c
*/

#include "../include/my_radar.h"

void update_plane3(tower_t *current_tower, plane_t *current_plane)
{
    for (int j = 0; j < 8; j++) {
        if (sqrtf(powf(current_tower->pos.x -
        current_plane->collision_points[j].x,2) +
                powf(current_tower->pos.y -
                        current_plane->collision_points[j].y,2)) <=
            current_tower->radius) {
            current_plane->is_controlled = 1;
            return;
        }
    }
}

void render_planes(win_t *win)
{
    for (int i = 0; i < win->nb_plane; i++) {
        if ((unsigned) win->plane[i]->delay_s < win->seconds) {
            win->plane[i]->is_flying = 1;
        }
        if (win->plane[i]->is_flying == 1 && win->plane[i]->as_landed == 0) {
            sfRenderWindow_drawSprite(win->window,
                win->plane[i]->model->sprite,
                NULL);
        }
    }
}

void render_plane_hitboxe(win_t *win)
{
    for (int i = 0; i < win->nb_plane; i++) {
        if (win->plane[i]->is_flying && !win->plane[i]->is_controlled
            && !win->plane[i]->as_landed) {
            sfRectangleShape_setOutlineColor(win->plane[i]->hitboxe,
                sfRed);
            sfRenderWindow_drawRectangleShape(win->window,
                win->plane[i]->hitboxe, NULL);
        }
        render_plane_hitboxe2(win, i);
    }
}

void render_plane_hitboxe2(win_t *win, int i)
{
    if (win->plane[i]->is_flying && win->plane[i]->is_controlled
        && !win->plane[i]->as_landed) {
        sfRectangleShape_setOutlineColor(win->plane[i]->hitboxe,
            sfGreen);
        sfRenderWindow_drawRectangleShape(win->window,
            win->plane[i]->hitboxe, NULL);
    }
    if (win->plane[i]->is_flying && win->plane[i]->is_crashed) {
        sfRectangleShape_setOutlineColor(win->plane[i]->hitboxe,
            sfBlack);
        sfRenderWindow_drawRectangleShape(win->window,
            win->plane[i]->hitboxe, NULL);
    }
}

int end_simu(win_t *win)
{
    for (int i = 0; i < win->nb_plane; i++) {
        if (win->plane[i]->as_landed == 0)
            return 0;
    }
    return 1;
}
