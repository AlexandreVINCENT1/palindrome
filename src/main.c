/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** main file
*/

#include "my.h"

void display_sol(void)
{
    puts("no solution");
}

void display(default_t *settings)
{
    char *nb = settings->nb;
    char *res = settings->result;
    int i = settings->iteration;
    int bs = settings->base;

    printf("%s leads to %s in %d iteration(s) in base %d\n", nb, res, i, bs);
}

void get_params(default_t *settings, char **av)
{
    if (find_in_array(av, "-n") != -1)
        settings->nb = strdup(av[find_in_array(av, "-n") + 1]);
    else if (find_in_array(av, "-p") != -1)
        settings->p = strdup(av[find_in_array(av, "-p") + 1]);
    if (find_in_array(av, "-b") != -1)
        settings->base = atoi(av[find_in_array(av, "-b") + 1]);
    else
        settings->base = 10;
    if (find_in_array(av, "-imin") != -1)
        settings->imin = atoi(av[find_in_array(av, "-imin") + 1]);
    else
        settings->imin = 0;
    if (find_in_array(av, "-imax") != -1)
        settings->imax = atoi(av[find_in_array(av, "-imax") + 1]);
    else
        settings->imax = 100;
}

int main(int ac, char **av)
{
    default_t settings;

    if (errors(ac, av) == 84)
        return (84);
    if (double_params(ac, av) == 84 || bad_arg(ac, av) == 84)
        return (84);
    get_params(&settings, av);
    if (find_in_array(av, "-p") != -1) {
        settings.test = atoi(av[find_in_array(av, "-p") + 1]);
        if (check_palindrome(trans_base(settings.test, settings.base)) == 1)
            return (84);
    } if (find_in_array(av, "-n") != -1) {
        settings.a = 0;
        if (iteration(&settings) == 0)
            display(&settings);
    } else if (find_in_array(av, "-p") != -1)
        flag_p(&settings);
    return (0);
}