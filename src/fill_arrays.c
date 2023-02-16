/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** Create tower / plane / background. Init window
*/

#include "../include/my_radar.h"

int fill_arrays2(const char *filename, win_t *win)
{
    FILE *file = fopen(filename, "r");
    char *line = NULL;
    size_t len = 0;
    int i = 0;
    int j = 0;
    while (getline(&line, &len, file) != -1) {
        if (line[0] == 'A') {
            win->plane[i] = create_plane(line, win);
            i++;
        }
        if (line[0] == 'T') {
            win->tower[j] = create_tower(line, win);
            j++;
        }
    }
    fclose(file);
    if (line)
        free(line);
    return 0;
}

tower_t *create_tower(char *line, win_t *win)
{
    tower_t *tower = malloc(sizeof(tower_t));
    tower->model = malloc(sizeof(sprite_t));
    char **array = my_str_to_word_array(line, ' ');
    tower->pos.x = (float) my_atoi(array[1]);
    tower->pos.y = (float) my_atoi(array[2]);
    tower->radius = my_atoi(array[3]);
    free(array);
    tower->model->radius = sfCircleShape_create();
    create_tower2(tower);
    tower->hitboxe = tower->model->radius;
    tower->model->texture = win->tower_s->texture;
    create_tower3(tower);
    return tower;
}

int create_tower2(tower_t *tower)
{
    sfCircleShape_setRadius(tower->model->radius, (float)tower->radius);
    sfCircleShape_setPosition(tower->model->radius,
        (sfVector2f){tower->pos.x - (tower->radius),
            tower->pos.y - (tower->radius)});
    sfColor temp = sfColor_fromRGB(0, 255, 0);
    temp.a = 50;
    sfCircleShape_setFillColor(tower->model->radius, temp);
    sfCircleShape_setOutlineColor(tower->model->radius, sfGreen);
    sfCircleShape_setOutlineThickness(tower->model->radius, 1);
    return 0;
}

int create_tower3(tower_t *tower)
{
    tower->model->sprite = sfSprite_create();
    sfSprite_setScale(tower->model->sprite, (sfVector2f){0.1, 0.1});
    sfSprite_setTexture(tower->model->sprite, tower->model->texture, sfTrue);
    tower->model->radius = sfCircleShape_create();
    tower->land_area.height = 512 * 0.1;
    tower->land_area.width = 512 * 0.07;
    tower->land_area.left = tower->pos.x - 256 * 0.07;
    tower->land_area.top = tower->pos.y - 256 * 0.1;
    tower->land_area_shape = sfRectangleShape_create();
    sfRectangleShape_setSize(tower->land_area_shape,
        (sfVector2f){tower->land_area.width, tower->land_area.height});
    sfRectangleShape_setPosition(tower->land_area_shape,
        (sfVector2f){tower->land_area.left, tower->land_area.top});
    sfRectangleShape_setFillColor(tower->land_area_shape, sfTransparent);
    sfRectangleShape_setOutlineColor(tower->land_area_shape, sfGreen);
    sfRectangleShape_setOutlineThickness(tower->land_area_shape, 2);
    return 0;
}

int fill_arrays(const char *filename, win_t *win)
{
    size_t len = 0;
    char *line = NULL;
    FILE *fp = fopen(filename, "r");
    while (getline(&line, &len, fp) != -1) {
        if (line[0] == 'T') {
            win->nb_tower++;
        }
        if (line[0] == 'A') {
            win->nb_plane++;
        }
    }
    fclose(fp);
    win->plane = malloc(sizeof(plane_t *) * win->nb_plane);
    win->tower = malloc(sizeof(tower_t *) * win->nb_tower);
    win->is_hitboxe = 0; win->is_sprite = 1;
    fill_arrays2(filename, win);
    set_rotation(win);
    return 0;
}
