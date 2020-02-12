/*
** EPITECH PROJECT, 2019
** getnum
** File description:
** oui
*/

#include "../include/ls.h"

char **delete_bad_stick(int line, int avble_remove, square_t *sq)
{
    int size_l = (line * 2) + 1;
    int i = 0;
    int b = 0;
    int compt = 0;
    for (i = 0; i < line - 2; i++) {
        for (b = 0; b <= size_l - 2; b++) {
            if (sq->stick[i][b] == '*') {
                sq->stick[i][b] = '*';
                b++;
            }
            else if (sq->stick[i][b] == ' ')
                compt++;
            if (compt == 0 || compt == 2)
                sq->stick[i][b] = ' ';
        }
        compt = 0;
    }
}

void print_pyra(int line, int avble_remove, square_t *sq)
{
    int i = 0;
    int pos = 2;
    int yes = 1;
    int no = yes + line * 2 - 3;
    for (i = 0; i < line - 1; i++, pos++, yes++, no = no - 2) {
        sq->stick[line - pos][yes] = ' ';
        sq->stick[line - pos][yes + no] = ' ';
    }
    delete_bad_stick(line, avble_remove, sq);
}

char **print_stick(int line, int avble_remove, square_t *sq)
{
    int size_l = (line * 2) + 1;
    int b = 0;
    int i = 0;
    sq->stick = malloc(sizeof(char *) * (line + 1));
    for (i = 0; i < line; i++) {
        sq->stick[i] = malloc(sizeof(char) * ((line * 2 + 1) + 1));
        for (b = 0; b <= size_l - 1; b++) {
            if (b == 0 || b == size_l - 1)
                sq->stick[i][b] = '*';
            else
                sq->stick[i][b] = '|';
        }
        sq->stick[i][b] = '\0';
    }
    print_pyra(line, avble_remove, sq);
    sq->stick[i] = NULL;
    return sq->stick;
}

char **print_square(int line, int avble_remove, square_t *sq)
{
    int compt = 0;
    int size_t_b = 2 * line + 1;
    char *top = malloc(sizeof(char) * (size_t_b + 1));
    for (; compt != size_t_b; compt++) {
        top[compt] = '*';
    }
    top[compt] = '\0';
    my_printf("%s\n", top);
    sq->stick = print_stick(line, avble_remove, sq);
    for (int compt = 0; sq->stick[compt]; compt++)
        my_printf("%s\n", sq->stick[compt]);
    my_printf("%s\n", top);
    return sq->stick;
}

int main(int ac, char **av)
{
    square_t *sq = malloc(sizeof(square_t));
    int numb = 1;
    int error;
    sq->stick = NULL;
    char *test = NULL;
    if (ac <= 2)
        return (84);
    if (my_getnbr(av[1]) >= 100)
        return 84;
    sq->stick = print_square(my_getnbr(av[1]), my_getnbr(av[2]), sq);
    numb = check_pipe_map(sq, my_getnbr(av[1]));
    while (numb != 0) {
        my_printf("\nYour turn:\n");
        error = ask_player(sq, my_getnbr(av[1]), my_getnbr(av[2]));
        if (error == -2)
            return 0;
        if ((numb = check_pipe_map(sq, my_getnbr(av[1]))) == 0) {
            my_printf("You lost, too bad\n");
            return (2);
        }
        ask_ia(sq, my_getnbr(av[1]), my_getnbr(av[2]), numb);
        numb = check_pipe_map(sq, my_getnbr(av[1]));
    }
    my_printf("I lost... snif... but I'll get you next time!!\n");
    return (1);
}