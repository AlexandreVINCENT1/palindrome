/*
** EPITECH PROJECT, 2019
** SYN_palindrome
** File description:
** header
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>


typedef struct default_s
{
    char *nb;
    int base;
    int imin;
    int imax;
    int iteration;
    char *p;
    char *trans;
    int a;
    int test;
    char *result;
} default_t;

// -->base.c
char *trans_base(int number, int base);
char *rev_str(char *str);
char *int_to_str(int nb);
int rev_int(int number);
char *transe_in_decimal(char *number, int base);

// -->usefull_functions.c
int find_in_array(char **str, char *word);
int check_number(char *str);
int power(int nb, int pow);

// -->palindrome.c
int check_palindrome(char *str);
int check_ret(char nb, char rev, int ret, int base);
char *add_base(char *number, char *rev, int base);
int iteration(default_t *settings);

// -->error.c
int errors(int ac, char **av);
int errors_bis(char **av);
int ck_base(char **av);
int double_params(int ac, char **av);
int bad_arg(int ac, char **av);

// -->main.c
void display_sol(void);
void display(default_t *settings);

// -->flag_p.c
int iteration_p(default_t *settings);
int flag_p(default_t *settings);

#endif