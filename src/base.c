/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** translate a base to another
*/

#include "my.h"

char *rev_str(char *str)
{
    int j = 0;
    int i = strlen(str) - 1;
    char *rev = malloc(sizeof(char) * (strlen(str) + 1));

    for (; i >= 0; j++, i--)
        rev[j] = str[i];
    rev[j] = '\0';
    return (rev);
}

char *int_to_str(int nb)
{
    char *a = calloc(200, sizeof(char));

    sprintf(a, "%d", nb);
    return (a);
}

int rev_int(int number)
{
    int i = 0;
    int rev = 0;

    for (; number > 0; i++) {
        rev += number % 10;
        rev = rev * 10;
        number = number / 10;
    }
    rev = rev / 10;
    return (rev);
}

char *trans_base(int number, int base)
{
    char *result = malloc(sizeof(char) * 1);
    int i = 1;

    for (;number > 0; i++) {
        result[i - 1] = (number % base) + 48;
        number = number / base;
        result = realloc(result, sizeof(char) * (i + 1));
    } result[i - 1] = '\0';
    result = rev_str(result);
    return (result);
}

char *transe_in_decimal(char *number, int base)
{
    int result = 0;
    int a = strlen(number) - 1;

    for (int i = 0; a >= 0; i++, a--)
        result += (number[a] - 48) * power(base, i);
    return (trans_base(result, 10));
}