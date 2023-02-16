/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** everything related to the planes
*/

#include "../include/my_radar.h"

void update_plane2(win_t *win, plane_t *current_plane)
{
    for (int i = 0; i < win->nb_tower; i++) {
        update_plane3(win->tower[i], current_plane);
    }

}

void update_plane(win_t *win)
{
    for (int i = 0; i < win->nb_plane; i++) {
        win->plane[i]->is_controlled = 0;
    }
    for (int j = 0; j < win->nb_plane; j++) {
        if (win->plane[j]->is_flying && !win->plane[j]->as_landed)
            update_plane2(win, win->plane[j]);
    }
}

int set_rotation(win_t *win)
{
    float rotation = 0;
    for (int i = 0; i < win->nb_plane; i++) {
        if (win->plane[i]->start.x <= win->plane[i]->end.x) {
            rotation = atan((win->plane[i]->end.y - win->plane[i]->start.y)
            / (win->plane[i]->end.x - win->plane[i]->start.x))
                * 180 / M_PI;
        } else {
            rotation = atan((win->plane[i]->end.y - win->plane[i]->start.y)
            / (win->plane[i]->end.x - win->plane[i]->start.x)) * 180 / M_PI
                + 180;
        }
        sfSprite_rotate(win->plane[i]->model->sprite, rotation);
    }
    return 0;
}

void move_plane2(plane_t *current_plane)
{
    for (int i = 0 ; i < 8; i++) {
        current_plane->collision_points[i].x += current_plane->move.x;
        current_plane->collision_points[i].y += current_plane->move.y;
    }

}

void move_plane(win_t *win)
{
    for (int i = 0; i < win->nb_plane; i++) {
        if (win->plane[i]->is_flying == 1 && win->plane[i]->as_landed == 0) {
            sfSprite_move(win->plane[i]->model->sprite,
                (sfVector2f){win->plane[i]->move.x, win->plane[i]->move.y});
            sfRectangleShape_move(win->plane[i]->hitboxe,
                (sfVector2f){win->plane[i]->move.x, win->plane[i]->move.y});
            win->plane[i]->pos.x += win->plane[i]->move.x;
            win->plane[i]->rect.left += (float)win->plane[i]->move.x;
            win->plane[i]->pos.y += win->plane[i]->move.y;
            win->plane[i]->rect.top += (float)win->plane[i]->move.y;
            move_plane2(win->plane[i]);
        }
        if (win->plane[i]->pos.x >= win->plane[i]->end.x - 20 &&
            win->plane[i]->pos.x <= win->plane[i]->end.x + 20 &&
            win->plane[i]->pos.y >= win->plane[i]->end.y - 20 &&
            win->plane[i]->pos.y <= win->plane[i]->end.y + 20) {
            win->plane[i]->is_flying = 0;
            win->plane[i]->as_landed = 1;
        }
    }
}
