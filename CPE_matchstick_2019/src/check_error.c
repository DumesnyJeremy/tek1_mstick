/*
** EPITECH PROJECT, 2019
** get
** File description:
** D.Jeremy
*/

#include "../include/ls.h"

int check_error(square_t *sq, int arg, int max)
{
    if (sq->matches == 0) {
        my_printf("Error: you have to remove at least one match\n");
        return ask_player(sq, arg, max);;
    }
    if (sq->matches == 84) {
        my_printf("Error: invalid input (positive number expected)\n");
        return ask_player(sq, arg, max);
    }
    if (sq->matches > max) {
        my_printf("Error: you cannot remove more "
        "than %d matches per turn\n", max);
        return ask_player(sq, arg, max);;
    }
}

int check_error2(square_t *sq, int arg, int max)
{
    if (sq->line == 84) {
        my_printf("Error: invalid input (positive number expected)\n");
        return ask_player(sq, arg, max);
    }
    if (sq->line == 0 || sq->line > arg) {
        my_printf("Error: this line is out of range\n");
        return ask_player(sq, arg, max);
    }
}

int ask_player(square_t *sq, int arg, int max)
{
    int error;
    my_printf("Line: ");
    char *str = get_next_line(0);
    if (str == NULL)
        return -2;
    sq->line = my_getnbr2(str);
    error = check_error2(sq, arg, max);
    if (error == -2)
        return -2;
    if (error == 0)
        return 0;
    error = check_pipe_line(sq, arg, max);
    if (error == -2)
        return -2;
    my_printf("Matches: ");
    str = get_next_line(0);
    if (str == NULL)
        return -2;
    sq->matches = my_getnbr2(str);
    error = check_error(sq, arg, max);
    if (error == -2)
        return -2;
    if (error == 0)
        return 0;
    error = check_nb_pipe_line(sq, arg, max);
    if (error == -2)
        return -2;
    my_printf("Player removed %d match(es)"
    " from line %d\n", sq->matches, sq->line);
    print_map(arg, sq);
    return 2;
}