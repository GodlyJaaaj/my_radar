/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** my_str_to_word_array.c
*/

#include "../include/my_radar.h"

char **my_str_to_word_array(char *str, char separator)
{
    int i = 0; int j = 0; int k = 0;
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));
    array[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    while (str[i] != '\0') {
        if (str[i] == separator) {
            array[j][k] = '\0';
            j++;
            k = 0;
            array[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        } else {
            array[j][k] = str[i]; k++;
        }
        i++;
    }
    array[j][k] = '\0'; array[j + 1] = NULL; return array;
}
