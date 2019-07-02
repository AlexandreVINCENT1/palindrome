/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** error handling file
*/

#include "my.h"

int ck_base(char **av)
{
    int nb = atoi(av[find_in_array(av, "-b") + 1]);

    if (nb > 10 || nb < 2)
        return (84);
    return (0);
}

int errors_bis(char **av)
{
    if (find_in_array(av, "-imin") != -1 &&
    check_number(av[find_in_array(av, "-imin") + 1]) == 84)
        return (84);
    if (find_in_array(av, "-b") != -1 &&
    (check_number(av[find_in_array(av, "-b") + 1]) == 84 || ck_base(av) == 84))
        return (84);
    if (find_in_array(av, "-imax") != -1 &&
    check_number(av[find_in_array(av, "-imax") + 1]) == 84)
        return (84);
    if (find_in_array(av, "-imax") != -1 && find_in_array(av, "-imin") != -1 &&
    atoi(av[find_in_array(av, "-imax") + 1]) <
    atoi(av[find_in_array(av, "-imin") + 1]))
        return (84);
    return (0);
}

int errors(int ac, char **av)
{
    if (ac < 3 || ac > 11 || ac % 2 == 0)
        return (84);
    if (ac >= 3) {
        if (find_in_array(av, "-n") != -1 && find_in_array(av, "-p") != -1)
            return (84);
        else if (find_in_array(av, "-n") == -1 && find_in_array(av, "-p") == -1)
            return (84);
    } if (find_in_array(av, "-n") != -1 &&
    check_number(av[find_in_array(av, "-n") + 1]) == 84)
        return (84);
    if (find_in_array(av, "-p") != -1 &&
    check_number(av[find_in_array(av, "-p") + 1]) == 84)
        return (84);
    if (errors_bis(av) == 84)
        return (84);
    return (0);
}

int double_params(int ac, char **av)
{
    int i = 0;
    int count = 0;
    char *str_flag[6] = {"-p", "-n", "-b", "-imin", "-imax"};

    for (int j = 0; str_flag[j] != NULL; j++) {
        for (i = 0, count = 0; i < ac; i++)
            (strstr(av[i], str_flag[j]) != NULL) ? (count++) : (count = count);
        if (count > 1)
            return (84);
    }
    return (0);
}

int bad_arg(int ac, char **av)
{
    int j = 0;
    int a = 0;
    char *str_flag[6] = {"-p", "-n", "-b", "-imin", "-imax"};

    for (int i = 1; i < ac; i = i + 2) {
        for (a = 0, j = 0; str_flag[j] != NULL; j++)
            a = (strcmp(av[i], str_flag[j]) != 0) ? (a + 1) : (a);
        if (a > 4)
            return (84);
    }
    return (0);
}