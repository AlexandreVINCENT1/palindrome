/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** requirement
*/

#include <stdlib.h>
#include <stdio.h>

int my_factrec_synthesis(int nb)
{
    int result = 0;

    if (nb == 0)
        return (1);
    if (nb >= 1 && nb < 13)
        result = nb * my_factrec_synthesis(nb - 1);
    else if (nb > 12)
        return (0);
    return (result);
}

int my_squareroot_synthesis(int nb)
{
    int i = 0;

    for (; nb > (i * i); i++);
    if ((i * i) != nb)
        return (-1);
    return (i);
}