/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** init_struct.c
*/

#include "../include/my_radar.h"

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = sfVideoMode_getDesktopMode();
    window = sfRenderWindow_create(mode, "My_Radar",  sfFullscreen | sfClose,
        NULL);
    sfRenderWindow_setFramerateLimit(window, FRAMERATE);
    return window;
}

int init_tower_texture(win_t *win)
{
    win->tower_s = malloc(sizeof(sprite_t));
    win->tower_s->texture = sfTexture_createFromFile("ASSETS/tower.png", NULL);
    return 0;
}

int init_plane_texture(win_t *win)
{
    win->plane_s = malloc(sizeof(sprite_t));
    win->plane_s->texture = sfTexture_createFromFile("ASSETS/plane.png", NULL);
    return 0;
}

int init_background(win_t *win)
{
    win->xy = malloc(sizeof(int) * 2);
    win->xy[0] = 10; win->xy[1] = 10;
    win->nb_grid = win->xy[0] * win->xy[1];
    win->background = malloc(sizeof(sprite_t));
    init_tower_texture(win);
    init_plane_texture(win);
    win->background->texture =
        sfTexture_createFromFile("./ASSETS/world_map.png", NULL);
    win->background->sprite = sfSprite_create();
    sfSprite_setTexture(win->background->sprite,
        win->background->texture,
        sfTrue);
    return 0;
}
