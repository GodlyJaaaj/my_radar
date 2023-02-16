/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** my_string.c
*/

#include "../include/my_radar.h"

int is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < '0' || str[i] > '9') && (str[i] != '\n'))
            return 84;
    }
    return 0;
}

char *int_to_string(int nb)
{
    char *str = malloc(sizeof(char) * 3);
    int i = 0;
    for (; nb > 0; i++) {
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    str[i] = '\0';
    return (my_revstr(str));
}

char *my_str_cat(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) *
        (my_strlen(str1) + my_strlen(str2) + 1));
    for (; str1[i] != '\0'; i++)
        str[i] = str1[i];
    for (; str2[j] != '\0'; j++) {
        str[i] = str2[j];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char tmp;

    while (str[i] != '\0')
        i++;
    i--;
    while (i > j) {
        tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i--;
        j++;
    }
    return (str);
}
