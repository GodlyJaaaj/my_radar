/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** my_radar.h
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_
    #define WIDTH 1920
    #define HEIGHT 1080
    #define FRAMERATE 60
    #define PLANE_WIDTH 200
    #define PLANE_HEIGHT 200
    #define PLANE_WIDTH_S 20
    #define PLANE_HEIGHT_S 20
    #include <math.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/Network.h>
    #include <time.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include "plane_tower.h"
    int check_file(char const *argv[]);
    int check_a_line(char *line);
    int check_t_line(char *line);
    int check_line(char *line);
    int check_files(char const *filename);
    void check_if_intersect(win_t *win, int i, int k, int j);
    void second_loop(win_t *win, int i, int j);
    void first_loop(win_t *win, int i);
    void check_collisions(win_t *win);
    void set_towers(win_t *win);
    void display_towers(win_t *win);
    void display_tower_radius(win_t *win);
    int show_grid(win_t *win);
    plane_t *create_plane(char *line, win_t *win);
    void create_plane2(plane_t *plane);
    void create_plane3(plane_t *plane);
    int fill_arrays2(const char *filename, win_t *win);
    tower_t *create_tower(char *line, win_t *win);
    int create_tower2(tower_t *tower);
    int create_tower3(tower_t *tower);
    int fill_arrays(const char *filename, win_t *win);
    void init_framerate(win_t *win);
    void print_framerate(win_t *win);
    void free_clocks(win_t *win);
    void free_colors(win_t *win);
    void free_grids(win_t *win);
    void destroy_sprite_t(win_t *win);
    void free_all(win_t *win);
    void free_menu(win_t *win);
    int mem_alloc_to_grid(win_t *win);
    int set_grid(win_t *win);
    int init_grid_rect(win_t *win);
    void fill_grid2(win_t *win, int i, int *current_index);
    void fill_grid(win_t *win);
    sfRenderWindow *init_window(void);
    int init_tower_texture(win_t *win);
    int init_plane_texture(win_t *win);
    int init_background(win_t *win);
    int check_arg(int argc, char const *argv[]);
    int usage2(int argc, char const *argv[]);
    int main(int argc, char const *argv[]);
    void handle_input(win_t *win);
    void pull_event(win_t *win);
    void render_hitboxes(win_t *win);
    void render_sprites(win_t *win);
    int main_loop(win_t *win);
    void init_menu_text(win_t *win);
    void init_menu_title(win_t *win);
    void init_menu_togglesprite(win_t *win);
    void init_menu_togglehitboxe(win_t *win);
    void init_menu_quit(win_t *win);
    void init_menu_author(win_t *win);
    void render_texts(win_t *win);
    void handle_input_menu(win_t *win);
    void pull_event_menu(win_t *win);
    void init_menu(win_t *win);
    void menu(win_t *win);
    int is_num(char *str);
    char *int_to_string(int nb);
    char *my_str_cat(char *str1, char *str2);
    char *my_revstr(char *str);
    char **my_str_to_word_array(char *str, char separator);
    void update_plane3(tower_t *current_tower, plane_t *current_plane);
    void render_planes(win_t *win);
    void render_plane_hitboxe(win_t *win);
    void render_plane_hitboxe2(win_t *win, int i);
    int end_simu(win_t *win);
    void update_plane2(win_t *win, plane_t *current_plane);
    void update_plane(win_t *win);
    int set_rotation(win_t *win);
    void move_plane2(plane_t *current_plane);
    void move_plane(win_t *win);
    void get_time(win_t *win);
    void init_time(win_t *win);
    void show_time(win_t *win);
    void usage(void);
    void my_putstr(char const *str);
    void my_put_nbr(int a);
    int my_atoi(char *string);
    int my_strlen(char const *str);
#endif /*MY_RADAR_H_*/
