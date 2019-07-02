/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** file with basic functions
*/

#include "my.h"

int find_in_array(char **str, char *word)
{
    for (int i = 0; str[i] != NULL; i++)
        if (strstr(str[i], word) != NULL)
            return (i);
    return (-1);
}

int check_number(char *str)
{
    if (str[0] == '-')
        return (84);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] > '9' || str[i] < '0')
            return (84);
    return (0);
}

int power(int nb, int pow)
{
    int p = nb;

    if (pow == 0)
        return (1);
    for (int i = 1; i < pow; i++)
        nb = nb * p;
    return (nb);
}