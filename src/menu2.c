/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** menu2.c
*/

#include "../include/my_radar.h"

void init_menu_text(win_t *win)
{
    win->menu->start_simu_text = sfText_create();
    sfText_setString(win->menu->start_simu_text,
        "<< Press Enter to start the simulation >>");
    sfText_setFont(win->menu->start_simu_text,
        sfFont_createFromFile("ASSETS/menu.ttf"));
    sfText_setCharacterSize(win->menu->start_simu_text, 50);
    sfText_setPosition(win->menu->start_simu_text, (sfVector2f){300, 850});
    sfText_setColor(win->menu->start_simu_text, sfBlack);
    init_menu_title(win);
    init_menu_togglesprite(win);
    init_menu_togglehitboxe(win);
    init_menu_quit(win);
    init_menu_author(win);
}

void init_menu_title(win_t *win)
{
    win->menu->title = sfText_create();
    sfText_setString(win->menu->title, "MY_RADAR");
    sfText_setFont(win->menu->title,
        sfFont_createFromFile("ASSETS/omegle.ttf"));
    sfText_setCharacterSize(win->menu->title, 200);
    sfText_setPosition(win->menu->title, (sfVector2f){30, 10});
    sfText_setColor(win->menu->title, sfBlack);
}

void init_menu_togglesprite(win_t *win)
{
    win->menu->toggle_sprite = sfText_create();
    sfText_setString(win->menu->toggle_sprite,
        "Press S to Enable/Disable sprites");
    sfText_setFont(win->menu->toggle_sprite,
        sfFont_createFromFile("ASSETS/menu.ttf"));
    sfText_setCharacterSize(win->menu->toggle_sprite, 30);
    sfText_setPosition(win->menu->toggle_sprite,
        (sfVector2f){20, 600});
    sfText_setColor(win->menu->toggle_sprite, sfGreen);
}

void init_menu_togglehitboxe(win_t *win)
{
    win->menu->toggle_hitboxe = sfText_create();
    sfText_setString(win->menu->toggle_hitboxe,
        "Press L to Enable/Disable hitboxes and areas");
    sfText_setFont(win->menu->toggle_hitboxe,
        sfFont_createFromFile("ASSETS/menu.ttf"));
    sfText_setCharacterSize(win->menu->toggle_hitboxe, 30);
    sfText_setPosition(win->menu->toggle_hitboxe,
        (sfVector2f){20, 650});
    sfText_setColor(win->menu->toggle_hitboxe, sfGreen);
}

void init_menu_quit(win_t *win)
{
    win->menu->leave_text = sfText_create();
    sfText_setString(win->menu->leave_text, "Press ESC to quit");
    sfText_setFont(win->menu->leave_text,
        sfFont_createFromFile("ASSETS/menu.ttf"));
    sfText_setCharacterSize(win->menu->leave_text, 30);
    sfText_setPosition(win->menu->leave_text,
        (sfVector2f){20, 700});
    sfText_setColor(win->menu->leave_text, sfGreen);
}
