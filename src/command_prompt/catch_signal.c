/*
** EPITECH PROJECT, 2020
** catch signal
** File description:
** catch the signals from the kernel and prints the correct message
*/

#include "minishell.h"
#include <sys/wait.h>

int change_return_value(int return_value)
{
    if (return_value == 11 || return_value ==  139)
        return (139);
    else
        return (134);
}

int correct_status(int status)
{
    switch (status)
    {
    case SIGSEGV:
        return (139);
    case SIGFPE:
        return (136);
    case SIGABRT:
        return (134);
    default:
        return (status);
    }
}

void print_signal(int status)
{
    switch (status)
    {
    case 139:
        my_putstr("Segmentation fault");
        break;
    case 136:
        my_putstr("Floating exception");
        break;
    case 134:
        my_putstr("Abort");
        break;
    default:
        break;
    }
}

int get_signal(int status)
{
    int true_status = correct_status(status);
    print_signal(true_status);
    if (__WCOREDUMP(status) != FALSE)
        my_putstr(" (core dumped)");
    my_putchar('\n');
    return (true_status);
}

int print_end_status(int status)
{
    int return_value = 0;

    if (WIFEXITED(status) == TRUE)
        return (0);
    else
        return_value = get_signal(status);
    return (return_value);
}