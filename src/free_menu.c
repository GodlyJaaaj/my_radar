/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** free_menu.c
*/

#include "../include/my_radar.h"

void free_menu(win_t *win)
{
    sfTexture_destroy(win->menu->background_texture);
    sfSprite_destroy(win->menu->background);
    sfText_destroy(win->menu->start_simu_text);
    sfText_destroy(win->menu->toggle_sprite);
    sfText_destroy(win->menu->toggle_hitboxe);
    sfText_destroy(win->menu->title);
    sfText_destroy(win->menu->author);
    sfText_destroy(win->menu->leave_text);
    free(win->menu);
}
