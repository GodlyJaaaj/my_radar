/*
** EPITECH PROJECT, 2022
** ----
** File description:
** main.c
*/

#include "../include/my_radar.h"

int check_arg(int argc, char const *argv[])
{
    if (argc != 2) {
        my_putstr(argv[0]);
        my_putstr(": bad arguments: ");
        my_put_nbr(argc - 1);
        my_putstr(" given but 1 is required\n");
        my_putstr("retry with -h\n");
        return 84;
    }
    return 0;
}

int usage2(int argc, char const *argv[])
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        usage();
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if (check_arg(argc, argv) == 84)
        return 84;
    if (usage2(argc, argv) == 1)
        return 0;
    if (check_file(argv) == 84)
        return 84;
    if (check_files(argv[1]) == 84)
        return 84;
    win_t *win = malloc(sizeof(win_t));
    win->nb_tower = 0; win->nb_plane = 0; win->nb_grid = 0;
    win->window = init_window();
    win->event = malloc(sizeof(sfEvent));
    init_menu(win);
    menu(win);
    init_background(win);
    fill_arrays(argv[1], win);
    set_towers(win);
    mem_alloc_to_grid(win); init_time(win);
    set_grid(win); init_grid_rect(win);
    main_loop(win); free_all(win); return 0;
}
