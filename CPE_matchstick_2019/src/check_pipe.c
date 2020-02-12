/*
** EPITECH PROJECT, 2019
** getnum
** File description:
** oui
*/

#include "../include/ls.h"

int check_pipe_line(square_t *sq, int arg, int max)
{
    int ch = 1;
    int numb = 0;
    while (ch != arg * 2) {
        if (sq->stick[sq->line - 1][ch] == '|')
            numb++;
        ch++;
    }
    if (numb != 0)
        return 1;
    else {
        my_printf("Error: empty line (line with matches expected)\n");
        return ask_player(sq, arg, max);;
    }
}

int check_nb_pipe_line(square_t *sq, int arg, int max)
{
    int ch = 1;
    int numb = 0;
    while (ch != arg * 2) {
        if (sq->stick[sq->line - 1][ch] == '|')
            numb++;
        ch++;
    }
    if (numb >= sq->matches)
        return 1;
    else {
        my_printf("Error: not enough matches on this line\n");
        return ask_player(sq, arg, max);;
    }
}

int check_pipe_map(square_t *sq, int arg)
{
    int i = 0;
    int b = 0;
    int numb = 0;
    for (i = 0; i < arg; i++) {
        for (b = 0; b <= arg * 2; b++)
            if (sq->stick[i][b] == '|')
            numb++;
    }
    return numb;
}