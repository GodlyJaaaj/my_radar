/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** plane_tower.h
*/

#ifndef PLANE_TOWER_H_
    #define PLANE_TOWER_H_
    #include "my_radar.h"
    typedef struct {
        sfTexture *texture;
        sfSprite *sprite;
        sfCircleShape *radius;
        sfVector2i location;
    } sprite_t;
    typedef struct {
        sfVector2f start;
        sfVector2f end;
        sfVector2f move;
        sfVector2f pos;
        sfVector2f *collision_points;
        int speed;
        int delay_s;
        int is_flying;
        int as_landed;
        int is_controlled;
        int is_crashed;
        sfFloatRect rect;
        sprite_t *model;
        sfRectangleShape *hitboxe;
    } plane_t;
    typedef struct {
        sfVector2f pos;
        int radius;
        sprite_t *model;
        sfCircleShape *hitboxe;
        sfIntRect land_area;
        sfRectangleShape *land_area_shape;
    } tower_t;
    typedef struct grid {
        sfFloatRect area;
        unsigned int nb_plane;
        plane_t **planes;
        sfRectangleShape *rect;
    } grid_t;
    typedef struct {
        sfTexture *background_texture;
        sfSprite *background;
        sfText *title;
        sfText *author;
        sfText *start_simu_text;
        sfText *toggle_sprite;
        sfText *toggle_hitboxe;
        sfText *leave_text;
        int is_open;
    } menu_t;
    typedef struct {
        sfRenderWindow *window;
        sfEvent *event;
        sprite_t *background;
        sprite_t *tower_s;
        sprite_t *plane_s;
        plane_t **plane;
        tower_t **tower;
        grid_t **grid;
        int current_color;
        sfColor *colors;
        int *xy;
        int nb_grid;
        int nb_plane;
        int nb_tower;
        int is_hitboxe;
        int is_sprite;
        sfClock *main_time;
        uint seconds;
        uint minutes;
        sfClock *clock_plane;
        float seconds_plane;
        sfText *time_text;
        sfRectangleShape *time_rect;
        sfClock *fps_clock;
        sfText *fps_text;
        menu_t *menu;
    } win_t;
#endif //PLANE_TOWER_H_
