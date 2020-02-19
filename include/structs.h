/*
** EPITECH PROJECT, 2020
** struct.h
** File description:
** includ structs for minishell
*/

#ifndef _STRUCT_H_
#define _STRUCT_H_

#include "minishell.h"

// structs
// linked lists structs
typedef struct node_s {
    char *variable;
    char *value;
    struct node_s *next;
}node_t;

typedef struct linked_list_s {
    node_t *head;
    node_t *tail;
}linked_list_t;

// command struct
typedef struct command_s  {
    int return_value;
    int command_status;
    char *input;
}command_t;

// function pointer
typedef int (*func_ptr_t)(char *, linked_list_t *);

#endif /* !_STRUCT_H_ */