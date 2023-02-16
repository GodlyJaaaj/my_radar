/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** meu.c
*/

#include "../include/my_radar.h"

void render_texts(win_t *win)
{
    sfRenderWindow_drawText(win->window,
        win->menu->start_simu_text, NULL);
    sfRenderWindow_drawText(win->window,
        win->menu->title, NULL);
    sfRenderWindow_drawText(win->window,
        win->menu->toggle_sprite, NULL);
    sfRenderWindow_drawText(win->window,
        win->menu->toggle_hitboxe, NULL);
    sfRenderWindow_drawText(win->window,
        win->menu->leave_text, NULL);
    sfRenderWindow_drawText(win->window,
        win->menu->author, NULL);
}

void handle_input_menu(win_t *win)
{
    switch (win->event->type) {
        case sfEvtKeyPressed:
            switch (win->event->key.code) {
                    case sfKeyEnter: win->menu->is_open = 0; break;
                default: break;
            }
            break;
        default: break;
    }
}

void pull_event_menu(win_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, win->event)) {
        if (win->event->type == sfEvtClosed
            || sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
        handle_input_menu(win);
    }
}

void init_menu(win_t *win)
{
    win->menu = malloc(sizeof(menu_t));
    win->menu->is_open = 1;
    win->menu->background_texture = sfTexture_createFromFile
        ("ASSETS/menu.jpg", NULL);
    win->menu->background = sfSprite_create();
    sfSprite_setTexture(win->menu->background,
        win->menu->background_texture, sfTrue);
    init_menu_text(win);
}

void menu(win_t *win)
{
    while (sfRenderWindow_isOpen(win->window) &&
        (win->menu->is_open == 1)) {
        pull_event_menu(win);
        sfRenderWindow_clear(win->window, sfBlack);
        sfRenderWindow_drawSprite(win->window,
            win->menu->background, NULL);
        render_texts(win);
        sfRenderWindow_display(win->window);
    }
    free_menu(win);
}
