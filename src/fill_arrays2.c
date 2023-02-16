/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** fill_arrays2.c
*/

#include "../include/my_radar.h"

plane_t *create_plane(char *line, win_t *win)
{
    plane_t *plane = malloc(sizeof(plane_t));
    char **array = my_str_to_word_array(line, ' ');
    plane->start = (sfVector2f){my_atoi(array[1]), my_atoi(array[2])};
    plane->end = (sfVector2f){my_atoi(array[3]),
        my_atoi(array[4])};
    plane->pos.y = plane->start.y + (PLANE_HEIGHT_S / 2);
    plane->pos.x = plane->start.x + (PLANE_WIDTH_S / 2);
    plane->as_landed = 0; plane->is_controlled = 1;
    plane->speed = my_atoi(array[5]);
    plane->delay_s = my_atoi(array[6]);
    plane->is_flying = 0; plane->is_crashed = 0;
    plane->model = malloc(sizeof(sprite_t));
    plane->model->texture = win->plane_s->texture;
    plane->move.x = ((plane->end.x - plane->start.x) / plane->speed) / 100;
    plane->move.y = ((plane->end.y - plane->start.y) / plane->speed) / 100;
    create_plane2(plane);
    plane->rect = (sfFloatRect){plane->start.x, plane->start.y,
        PLANE_WIDTH_S, PLANE_HEIGHT_S};
    free(array);
    return plane;
}

void create_plane2(plane_t *plane)
{
    plane->model->sprite = sfSprite_create();
    sfSprite_setScale(plane->model->sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setTexture(plane->model->sprite, plane->model->texture, sfTrue);
    sfSprite_setOrigin(plane->model->sprite, (sfVector2f){PLANE_WIDTH / 2,
    PLANE_HEIGHT / 2});
    sfSprite_setPosition(plane->model->sprite, plane->pos);
    plane->hitboxe = sfRectangleShape_create();
    sfRectangleShape_setSize(plane->hitboxe,
        (sfVector2f){PLANE_WIDTH_S, PLANE_HEIGHT_S});
    sfRectangleShape_setOrigin(plane->hitboxe,
        (sfVector2f){PLANE_WIDTH_S / 2, PLANE_HEIGHT_S / 2});
    sfRectangleShape_setPosition(plane->hitboxe, plane->pos);
    sfRectangleShape_setFillColor(plane->hitboxe, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->hitboxe, sfRed);
    sfRectangleShape_setOutlineThickness(plane->hitboxe, 1);
    create_plane3(plane);
}

void create_plane3(plane_t *plane)
{
    plane->collision_points = malloc(sizeof(sfVector2f) * 8);
    plane->collision_points[0].x = plane->start.x;
    plane->collision_points[0].y = plane->start.y;
    plane->collision_points[1].x = plane->start.x + (PLANE_WIDTH_S / 2);
    plane->collision_points[1].y = plane->start.y;
    plane->collision_points[2].x = plane->start.x + PLANE_WIDTH_S;
    plane->collision_points[2].y = plane->start.y;
    plane->collision_points[3].x = plane->start.x;
    plane->collision_points[3].y = plane->start.y + (PLANE_HEIGHT_S / 2);
    plane->collision_points[4].x = plane->start.x + PLANE_WIDTH_S;
    plane->collision_points[4].y = plane->start.y + (PLANE_HEIGHT_S / 2);
    plane->collision_points[5].x = plane->start.x;
    plane->collision_points[5].y = plane->start.y + PLANE_HEIGHT_S;
    plane->collision_points[6].x = plane->start.x + (PLANE_WIDTH_S / 2);
    plane->collision_points[6].y = plane->start.y + PLANE_HEIGHT_S;
    plane->collision_points[7].x = plane->start.x + PLANE_WIDTH_S;
    plane->collision_points[7].y = plane->start.y + PLANE_HEIGHT_S;
}
