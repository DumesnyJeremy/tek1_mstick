/*
** EPITECH PROJECT, 2019
** get
** File description:
** D.Jeremy
*/

#include "../include/ls.h"

void print_top_bot(int arg)
{
    int compt = 0;
    int size_t_b = 2 * arg + 1;
    char *top = malloc(sizeof(char) * (size_t_b + 1));
    for (; compt != size_t_b; compt++) {
        top[compt] = '*';
    }
    top[compt] = '\0';
    my_printf("%s\n", top);
}

void print_map(int arg, square_t *sq)
{
    for (int f = 1;sq->matches != 0; sq->matches--, f++) {
        while (sq->stick[sq->line - 1][arg * 2 - f] != '|')
            f++;
        if (sq->stick[sq->line - 1][arg * 2 - f] == '|')
            sq->stick[sq->line - 1][arg * 2 - f] = ' ';
    }
    print_top_bot(arg);
    for (int compt = 0; sq->stick[compt]; compt++)
        my_printf("%s\n", sq->stick[compt]);
    print_top_bot(arg);
}