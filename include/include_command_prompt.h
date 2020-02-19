/*
** EPITECH PROJECT, 2020
** include command prompt
** File description:
** include file for minishell
*/

#ifndef _COMMAND_PROMPT_H_
#define _COMMAND_PROMPT_H_

// functions includes from clean string
char *remove_spaces(char *string, int count);
char *clean_string(char *string);
char *format_string(char *buffer);

// functions includes from command prompt
command_t command_prompt(linked_list_t *list, command_t command);
int get_return(char *input);
char *get_input(void);

// functions includes from get command path
char *get_command_path(char **args, linked_list_t *list);
int find_command(char *command, char *path);
char **get_paths(linked_list_t *list);
char *get_complete_command(char *input, char *command_path);

// functions includes from catch signal
int print_end_status(int status);
int get_signal(int status);
int correct_status(int status);
void print_signal(int status);
int change_return_value(int return_value);

// functions includes from exec command
int exec_command(linked_list_t *list, char *input);
int fork_command(char *command_path, char **args, linked_list_t *list,
                                                    int is_dire_command);
int exec_bin_command(char *command_path, char **args, char **env,
                                                    int is_dire_command);
int check_dire_command(char *input);
char *check_command(char *input);

// functions includes from exit_shell
command_t exit_shell(command_t command);
int check_exit_arg(char *arg);
int get_tab_size(char **tab);
char *remove_enter(char *arg);

// functions inclues from list to tab
char **list_to_arr(linked_list_t *list);
int get_list_size(linked_list_t *list);
void free_tab(char **tab);
char *concat_strings(char *variable, char *value);

// functions from acces tests
int print_errors(char *input, char *command_path);
int binary_command_access(char *command_path, char *input);
int normal_command_access(char *input);

// functions includes from dire command
command_t check_is_dire_command(linked_list_t *list, char *input,
                                                        command_t command);
command_t simple_dir(linked_list_t *list, char *input, command_t command);

#endif /* !_COMMAND_PROMPT_H_ */
