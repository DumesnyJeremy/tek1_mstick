/*
** EPITECH PROJECT, 2019
** get
** File description:
** D.Jeremy
*/

#include "../include/ls.h"

static char file[READ_SIZE];

int my_strlen2(char const *str, int i, int a)
{
    int count = 0;

    if (!str)
        return (0);
    if (i == 1) {
        while (str[count] != '\0')
            count++;
        return (count);
    } else if (i == 0) {
        while (str[count] != '\n' && count < a)
            count++;
        }
    return (count);
}

char *my_strcat(char *dest, char *st, int *a)
{
    int b = 0;
    int l = my_strlen2(dest, 1, *a);
    l += my_strlen2(file, 0, *a);
    char *tempo = NULL;
    if (l != 0)
        tempo = malloc(sizeof(char) * (l + 1));
    if (dest != NULL) {
        for (; dest[b] != '\0'; b++)
            tempo[b] = dest[b];
        free(dest);
    }
    for (int j = 0; j < *a; j++, b++) {
        if (file[j] == '\n') {
            *st = 1;
            tempo[b] = '\0';
            for (int k = 0; k < (*a - j - 1); k++)
                file[k] = file[k + j + 1];
            *a = *a - j - 1;
            return (tempo);
        }
        tempo[b] = file[j];
    }
    *st = 0;
    if (l != 0) {
        tempo[b] = '\0';
    }
    return (tempo);
}

char *get_next_line(int fd)
{
    static int a = 0;
    int b;
    char st = 0;
    char *result = NULL;
    char *soraia = NULL;

    if (fd == -1 || file == NULL)
        return NULL;
    soraia = my_strcat(soraia, &st, &a);
    if (st == 1)
        return soraia;
    while ((a = read(fd, file, READ_SIZE)) && a != -1 && a != 0 ) {
        soraia = my_strcat(soraia, &st, &a);
        if (st == 1)
            return soraia;
    }
    if (a == 0)
        return soraia;
    return NULL;
}