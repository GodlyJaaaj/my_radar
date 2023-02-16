/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** check_files.c
*/

#include "../include/my_radar.h"

int check_file(char const *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        my_putstr(argv[0]);
        my_putstr(": cannot open file '");
        my_putstr(argv[1]);
        my_putstr("'\n");
        my_putstr("retry with -h\n");
        return 84;
    }
    fclose(file);
    return 0;
}

int check_a_line(char *line)
{
    char **array = my_str_to_word_array(line, ' ');
    for (int i = 1; i < 7; i++) {
        if (array[i] == NULL) {
            write(2, "Error: invalid plane line\n", 26);
            return 84;
        }
        if (is_num(array[i]) == 84) {
            write(2, "Error: invalid plane line\n", 26);
            return 84;
        }
    }
    free(array);
    return 0;
}

int check_t_line(char *line)
{
    char **array = my_str_to_word_array(line, ' ');
    for (int i = 1; i < 4; i++) {
        if (array[i] == NULL) {
            write(2, "Error: invalid tower line\n", 26);
            return 84;
        }
        if (is_num(array[i]) == 84) {
            write(2, "Error: invalid tower line\n", 26);
            return 84;
        }
    }
    free(array);
    return 0;
}

int check_line(char *line)
{
    if (line[0] == 'T') {
        if (check_t_line(line) == 84) {
            return 84;
        }
    }
    if (line[0] == 'A') {
        if (check_a_line(line) == 84) {
            return 84;
        }
    }
    if (line[0] != 'T' && line[0] != 'A') {
        write(2, "Invalid file\n", 13);
        return 84;
    }
    return 0;
}

int check_files(char const *filename)
{
    size_t len = 0; int i = 0;
    char *line = NULL;
    FILE *fp = fopen(filename, "r");
    while (getline(&line, &len, fp) != -1) {
        if (check_line(line) == 84)
            return 84;
        i++;
    }
    fclose(fp);
    return 0;
}
