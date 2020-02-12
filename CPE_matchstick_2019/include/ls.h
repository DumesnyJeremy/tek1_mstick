/*
** EPITECH PROJECT, 2019
** h
** File description:
** h
*/

#ifndef READ_SIZE
#define READ_SIZE 1
#endif

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <time.h>

typedef struct square_s
{
    char **stick;
    int line;
    int matches;
} square_t;

int main(int ac, char **av);
char **print_square(int line, int avble_remove, square_t *sq);
char **print_stick(int line, int avble_remove, square_t *sq);
void print_pyra(int line, int avble_remove, square_t *sq);
char **delete_bad_stick(int line, int avble_remove, square_t *sq);
int check_pipe_line(square_t *sq, int arg, int max);
int check_nb_pipe_line(square_t *sq, int arg, int max);
int check_pipe_map(square_t *sq, int arg);
int ask_ia(square_t *sq, int arg, int max, int nbr_stk);

int ask_player(square_t *sq, int arg, int max);
int check_error2(square_t *sq, int arg, int max);
int check_error(square_t *sq, int arg, int max);
void print_map(int arg, square_t *sq);
void print_top_bot(int arg);

char *get_next_line(int fd);
int my_strlen2(char const *str, int i, int a);
char *my_strcat(char *dest, char *st, int *a);

char *my_strcpy(char const *src);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int	my_getnbr2(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);

typedef void (*p_fonct)();

char *my_revstr(char *str);
void my_printf(char const *str, ...);
int my_strncmp(char const *s1, char const *s2, int n);
void my_put_nbr_l(long nb);
void my_put_nbr(int);
void my_put_nbr_o(int);
void my_put_nbr_x(int);
void my_put_nbr_xmaj(int);
void my_put_nbr_b(int nb);
void my_put_nbr_u(unsigned int nb);
void my_put_nbr_lx(long nb);
void my_put_nbr_lxmaj(long nb);
void my_put_nbr_p(long long int nb);
void my_put_p(long long int nb);

#endif