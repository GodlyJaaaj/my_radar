/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myradar-sebastien.lucas
** File description:
** Used to check parameters and display usage
*/

#include "../include/my_radar.h"

void usage(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n");
    my_putstr("\t./my_radar [OPTIONS] path_to_script\n");
    my_putstr("\tpath_to_script\t\tthe path to the script file\n\n");
    my_putstr("OPTIONS\n");
    my_putstr("\t-h\t\tprint the usage and quit.\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("\t'L' Key \tenable/disable hitboxes an areas.\n");
    my_putstr("\t'S' Key \tenable/disable sprites.\n");
    my_putstr("\t'ESC' Key \tto quit the simulation.\n");
}

void my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i++;
    }
}

void my_put_nbr(int a)
{
    if (a < 0) {
        write(1, "-", 1);
        a = a * -1;
    }
    if (a >= 10) {
        my_put_nbr(a / 10);
        my_put_nbr(a % 10);
    } else {
        a = a + 48;
        write(1, &a, 1);
    }
}

int my_atoi(char *string)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (string[i] == '-' || string[i] == '+') {
        if (string[i] == '-')
            neg = neg * -1;
        i++;
    }
    while (string[i] >= '0' && string[i] <= '9') {
        nb = nb * 10;
        nb = nb + string[i] - 48;
        i++;
    }
    return (nb * neg);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
