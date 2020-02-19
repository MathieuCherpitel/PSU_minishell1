/*
** EPITECH PROJECT, 2020
** include special command
** File description:
** include file for minishell
*/

#ifndef _SPECIAL_COMMAND_H_
#define _SPECIAL_COMMAND_H_

// functions includes

// functions includes from built in commands
command_t built_in_command(linked_list_t *list, char *input, command_t command);
int print_env(char *input, linked_list_t *list);

// functions includes from change dir
int change_dir(char *input, linked_list_t *list);
int check_word_count(char *input, linked_list_t *list);
char *get_dir(char *input);
int call_options(char *directory, linked_list_t *list);

// functions incudes from change dir options
int change_dir_normal(linked_list_t *list, char *directory, char *PWD);
int change_dir_old(linked_list_t *list, char *OLDPWD, char *PWD);
int change_dir_home(linked_list_t *list, char *HOME, char *PWD);
void set_env_data(linked_list_t *list, char *variable, char *value);

// functions includes from setenv
int my_setenv(char *input, linked_list_t *list);
int exec_simple_setenv(linked_list_t *list);
int set_env_value(char *input, linked_list_t *list);
int add_env_var(char *input, linked_list_t *list);
int check_setenv(char *command);

// functions from error change
void error_change_dir(int correct_dir, char *directory);
int check_dir(char *directory);

// functions from get env values
char *get_env_value(linked_list_t *list, char *value);
char *get_pwd(linked_list_t *list);
char *get_home(linked_list_t *list);
char *get_oldpwd(linked_list_t *list);
void check_oldpwd(linked_list_t *list);

// functions from my unsetenv
int my_unsetenv(char *input, linked_list_t *list);
int check_exist_var(char *variable, linked_list_t *list);

// functions from remove var
node_t *remove_node_at_end(node_t *begin_node, node_t *last_node,
                                                        linked_list_t *list);
node_t *remove_node_at_begin(node_t *begin_node, linked_list_t *list);
node_t *remove_node_at_middle(node_t *begin_node, char *variable);
void remove_node(char *variable, linked_list_t *list);

// functions from env
void print_list(linked_list_t *list);

#endif /* !_SPECIAL_COMMAND_H_ */
