/*
** EPITECH PROJECT, 2020
** error change dir
** File description:
** check errors for cd built in
*/

#include <dirent.h>
#include <pwd.h>
#include "minishell.h"

int check_dir(char *directory)
{
    struct stat dire_stat;

    if (access(directory, F_OK) != 0)
        return (1);
    stat(directory, &dire_stat);
    if (S_ISDIR(dire_stat.st_mode) != 1)
        return (2);
    if (access(directory, R_OK) != 0)
        return (3);
    return (SUCCESS);
}

void error_change_dir(int correct_dir, char *directory)
{
    if (correct_dir == 1) {
        my_putstr(directory);
        my_putstr(": No such file or directory.\n");
    }
    if (correct_dir == 2) {
        my_putstr(directory);
        my_putstr(": Not a directory.\n");
    }
    else if (correct_dir == 3) {
        my_putstr(directory);
        my_putstr(": Permission denied.\n");
    }
}