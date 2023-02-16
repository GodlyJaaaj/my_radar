/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** time.c
*/

#include "../include/my_radar.h"

void get_time(win_t *win)
{
    win->seconds = sfTime_asSeconds(sfClock_getElapsedTime(win->main_time));
    win->seconds_plane = sfTime_asMilliseconds(sfClock_getElapsedTime(
        win->clock_plane));
    if (win->seconds_plane > 10) {
        sfClock_restart(win->clock_plane);
        move_plane(win);
        fill_grid(win);
        update_plane(win);
        check_collisions(win);
        win->seconds_plane = 0;
    }
}

void init_time(win_t *win)
{
    win->time_text = sfText_create();
    sfText_setCharacterSize(win->time_text, 100);
    sfText_setFont(win->time_text, sfFont_createFromFile("ASSETS/clock.ttf"));
    sfText_setPosition(win->time_text, (sfVector2f){1650, 0});
    sfText_setColor(win->time_text, sfWhite);
    sfText_setString(win->time_text, "00");
    win->time_rect = sfRectangleShape_create();
    sfRectangleShape_setSize(win->time_rect, (sfVector2f){320, 125});
    sfRectangleShape_setFillColor(win->time_rect, sfBlack);
    sfRectangleShape_setPosition(win->time_rect, (sfVector2f){1600, 0});

}

void show_time(win_t *win)
{
    char *str = int_to_string(win->seconds % 60);
    char *str2 = int_to_string(floor(win->seconds / 60));
    if (floor(win->seconds / 60) == 0)
        str2 = my_str_cat("00", str2);
    if (floor(win->seconds / 60))
        str2 = my_str_cat("0", str2);
    if (win->seconds % 60 < 10)
        str = my_str_cat("0", str);
    if (win->seconds % 60 == 0)
        str = my_str_cat(str, "0");
    str2 = my_str_cat(str2, ":");
    str2 = my_str_cat(str2, str);
    sfText_setString(win->time_text, str2);
    free(str); free(str2);
    if (win->seconds == 0 && win->minutes == 0) {
        sfText_setString(win->time_text, "00:00");
    }
    sfRenderWindow_drawRectangleShape(win->window, win->time_rect, NULL);
    sfRenderWindow_drawText(win->window, win->time_text, NULL);
    sfText_setString(win->time_text, "");
}
