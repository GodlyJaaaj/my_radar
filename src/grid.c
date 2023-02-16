/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** everything related to the grid (mem alloc, fill...)
*/

#include "../include/my_radar.h"

int mem_alloc_to_grid(win_t *win)
{
    win->grid = malloc(sizeof(grid_t *) * (win->nb_grid));
    for (int i = 0; i < win->nb_grid; i++) {
        win->grid[i] = malloc(sizeof(grid_t));
        win->grid[i]->planes = malloc(sizeof(plane_t *) * win->nb_plane);
        win->grid[i]->planes[0] = NULL;
        win->grid[i]->nb_plane = 0;
    }
    return 0;
}

int set_grid(win_t *win)
{
    srand(time(NULL));
    win->colors = malloc(sizeof(sfColor) * (win->nb_grid));
    win->current_color = 0;
    for (int i = 0; i < win->nb_grid; i++) {
        win->colors[i] =
            sfColor_fromRGB(rand() % 255, rand() % 255, rand() % 255);
        win->grid[i]->area.height = (float)HEIGHT / (float)win->xy[1];
        win->grid[i]->area.width = (float)WIDTH / (float)win->xy[0];
        win->grid[i]->area.left = (float)WIDTH / (float)win->xy[0] * (float)
            (i % win->xy[0]);
        win->grid[i]->area.top = (float)HEIGHT / (float)win->xy[1] * (float)
            (i / win->xy[0]);
        win->grid[i]->nb_plane = 0;
    }
    return 0;
}

int init_grid_rect(win_t *win)
{
    for (int i = 0; i < win->nb_grid; i++) {
        win->grid[i]->rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(win->grid[i]->rect,
            (sfVector2f){win->grid[i]->area.left, win->grid[i]->area.top});
        sfRectangleShape_setSize(win->grid[i]->rect,
            (sfVector2f){win->grid[i]->area.width, win->grid[i]->area.height});
        sfColor temp = win->colors[i];
        temp.a = 50;
        sfRectangleShape_setFillColor(win->grid[i]->rect, temp);
        sfRectangleShape_setOutlineColor(win->grid[i]->rect, sfWhite);
        sfRectangleShape_setOutlineThickness(win->grid[i]->rect, 1);
    }
    return 0;
}

void fill_grid2(win_t *win, int i, int *current_index)
{
    for (int j = 0; j < win->nb_grid; j++) {
        if ((sfFloatRect_intersects(&win->plane[i]->rect,
            &win->grid[j]->area, NULL) == sfTrue)) {
            win->grid[j]->planes[current_index[j]] = win->plane[i];
            current_index[j]++;
            win->grid[j]->nb_plane++;
        }
    }
}

void fill_grid(win_t *win)
{
    int *current_index = malloc(sizeof(int) * win->nb_grid);
    for (int i = 0; i < win->nb_grid; i++) {
        current_index[i] = 0;
        win->grid[i]->nb_plane = 0;
    }
    for (int i = 0; i < win->nb_plane; i++) {
        if (win->plane[i]->is_flying == 1) {
            fill_grid2(win, i, current_index);
        } else {
            continue;
        }
    }
    for (int i = 0; i < win->nb_grid; i++) {
        win->grid[i]->planes[current_index[i]] = NULL;
    }
    free(current_index);
}
