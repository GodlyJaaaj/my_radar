/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** menu3.c
*/

#include "../include/my_radar.h"

void init_menu_author(win_t *win)
{
    win->menu->author = sfText_create();
    sfText_setString(win->menu->author, "by Sebastien Lucas");
    sfText_setFont(win->menu->author,
        sfFont_createFromFile("ASSETS/omegle.ttf"));
    sfText_setCharacterSize(win->menu->author, 40);
    sfText_setPosition(win->menu->author, (sfVector2f){45, 210});
    sfText_setColor(win->menu->author, sfBlue);
}
