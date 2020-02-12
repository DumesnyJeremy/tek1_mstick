/*
** EPITECH PROJECT, 2019
** get
** File description:
** D.Jeremy
*/

#include "../include/ls.h"

int check_nb_pipe(square_t *sq, int arg, int max)
{
    int ch = 1;
    int numb = 0;
    while (ch != arg * 2) {
        if (sq->stick[sq->line][ch] == '|')
            numb++;
        ch++;
    }
    if (numb >= sq->matches)
        return 1;
    else {
        return - 1;
    }
}

void print_new_map(int arg, square_t *sq)
{
    for (int f = 1;sq->matches != 0; sq->matches--, f++) {
        while (sq->stick[sq->line][arg * 2 - f] != '|')
            f++;
        if (sq->stick[sq->line][arg * 2 - f] == '|')
            sq->stick[sq->line][arg * 2 - f] = ' ';
    }
    print_top_bot(arg);
    for (int compt = 0; sq->stick[compt]; compt++)
        my_printf("%s\n", sq->stick[compt]);
    print_top_bot(arg);
}

int pipe_line(square_t *sq, int arg, int max)
{
    int ch = 1;
    int numb = 0;
    while (ch != arg * 2) {
        if (sq->stick[sq->line][ch] == '|')
            numb++;
        ch++;
    }
    if (numb != 0)
        return 1;
    else {
        return - 1;
    }
}

int ask_ia(square_t *sq, int arg, int max, int nbr_stk)
{
    int error;
    my_printf("\nAI's turn...\n");
    sq->line = rand() % arg;
    error = pipe_line(sq, arg, max);
    while (error == - 1) {
        sq->line = rand() % arg;
        error = pipe_line(sq, arg, max);
    }
    sq->matches = rand() % max + 1;
    error = check_nb_pipe(sq, arg, max);
    while (error == - 1) {
        sq->matches = rand() % max + 1;
        error = check_nb_pipe(sq, arg, max);
    }
    my_printf("AI removed %d match(es) from "
    "line %d\n", sq->matches, sq->line + 1);
    print_new_map(arg, sq);
}