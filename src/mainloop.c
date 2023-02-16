/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** This file contains the main loop of the program
*/

#include "../include/my_radar.h"

void handle_input(win_t *win)
{
    switch (win->event->type) {
        case sfEvtKeyPressed:
            switch (win->event->key.code) {
                case sfKeyL: win->is_hitboxe = !win->is_hitboxe; break;
                case sfKeyS: win->is_sprite = !win->is_sprite; break;
                default: break;
            }
            break;
        default: break;
    }
}

void pull_event(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, win->event)) {
        if (win->event->type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        handle_input(win);
    }
}

void render_hitboxes(win_t *win)
{
    if (win->is_hitboxe == 1) {
        display_tower_radius(win);
        show_grid(win);
        render_plane_hitboxe(win);
    }
}

void render_sprites(win_t *win)
{
    if (win->is_sprite == 1) {
        display_towers(win);
        render_planes(win);
    }
}

int main_loop(win_t *win)
{
    win->main_time = sfClock_create(); win->seconds = 0; win->minutes = 0;
    win->clock_plane = sfClock_create(); win->seconds_plane = 0;
    fill_grid(win);
    init_framerate(win);
    while (sfRenderWindow_isOpen(win->window) && end_simu(win) == 0) {
        get_time(win);
        sfRenderWindow_clear(win->window, sfBlack);
        sfRenderWindow_drawSprite(win->window, win->background->sprite, NULL);
        render_hitboxes(win);
        render_sprites(win);
        show_time(win);
        print_framerate(win);
        sfRenderWindow_display(win->window);
        pull_event(win);
    }
    return 0;
}
