/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** contain functions that manage flag -p
*/

#include "my.h"

int iteration_p(default_t *settings)
{
    int i = 0;
    char *number = trans_base(atoi(strdup(settings->nb)), settings->base);

    for (;i <= settings->imax; i++) {
        if (check_palindrome(number) == 0 &&
        strcmp(number, settings->trans) == 0 && i >= settings->imin)
            break;
        if (atoi(number) > atoi(settings->trans)) {
            free(number);
            return (-1);
        } number = add_base(number, number, settings->base);
    } if (i > settings->imax || i < settings->imin)
        return (-1);
    settings->result = strdup(number);
    if (settings->base != 10)
        settings->result = transe_in_decimal(settings->result, settings->base);
    settings->iteration = i;
    free(number);
    return (0);
}

int flag_p(default_t *settings)
{
    int i = 1;

    settings->iteration = 0;
    settings->trans = trans_base(atoi(settings->p), settings->base);
    settings->a = 1;

    for (; i <= atoi(settings->p); i++) {
        settings->nb = int_to_str(i);
        if (iteration_p(settings) == 0) {
            display(settings);
            settings->a++;
        }
    }
    if (settings->a == 1)
        display_sol();
    return (0);
}