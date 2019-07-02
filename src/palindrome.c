/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** algorythme of the program
*/

#include "my.h"

int check_palindrome(char *str)
{
    int a;

    a = strlen(str) - 1;
    for (int i = 0; i < a; i++, a--){
        if (str[i] != str[a])
            return (1);
    }
    return (0);
}

int check_ret(char nb, char rev, int ret, int base)
{
    if ((((nb - 48) + (rev - 48) + ret) / base) != 0)
        return (1);
    return (0);
}

char *add_base(char *number, char *rev, int base)
{
    char *result = malloc(sizeof(char) * (strlen(number) + 1));
    int a = strlen(number) - 1;
    int i = 0;
    int ret = 0;

    for (; number[i] != '\0'; i++, a--) {
        result[i] = (((number[i] - 48) + (rev[a] - 48) + ret) % base) + 48;
        ret = check_ret(number[i], rev[a], ret, base);
    }
    if (ret != 0) {
        result[i] = ret + 48;
        result = realloc(result, sizeof(char) * (i + 2));
        i++;
    } result[i] = '\0';
    return (result);
}

int iteration(default_t *settings)
{
    int i = 0;
    char *number = trans_base(atoi(strdup(settings->nb)), settings->base);

    for (;i <= settings->imax; i++) {
        if (check_palindrome(number) == 0 &&
        i >= settings->imin)
            break;
        number = add_base(number, number, settings->base);
    }
    if (i > settings->imax || i < settings->imin) {
        if (settings->a == 0)
            display_sol();
        return (-1);
    } settings->result = strdup(number);
    if (settings->base != 10)
        settings->result = transe_in_decimal(settings->result, settings->base);
    settings->iteration = i;
    free(number);
    return (0);
}