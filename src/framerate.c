/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** Framerate management
*/

#include "../include/my_radar.h"

void init_framerate(win_t *win)
{
    win->fps_clock = sfClock_create();
    win->fps_text = sfText_create();
    sfText_setCharacterSize(win->fps_text, 50);
    sfText_setFont(win->fps_text, sfFont_createFromFile("ASSETS/clock.ttf"));
    sfText_setPosition(win->fps_text, (sfVector2f){0, 1020});
    sfText_setColor(win->fps_text, sfGreen);
}

void print_framerate(win_t *win)
{
    static int fps = 0;
    sfTime elapsed = sfClock_getElapsedTime(win->fps_clock);
    if (sfTime_asSeconds(elapsed) >= 1) {

        sfText_setString(win->fps_text, my_str_cat("FPS: ",
                                            int_to_string(fps)));
        fps = 0;
        sfClock_restart(win->fps_clock);
    } else
        fps ++;
    sfRenderWindow_drawText(win->window, win->fps_text, NULL);
}
