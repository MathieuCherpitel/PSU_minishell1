##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	src/main_functions/main.c				\
		src/main_functions/minishell.c 			\
		src/command_prompt/command_prompt.c 	\
		src/command_prompt/clean_string.c 		\
		src/command_prompt/get_command_path.c 	\
		src/command_prompt/exec_command.c 		\
		src/command_prompt/exit_shell.c 		\
		src/command_prompt/catch_signal.c 		\
		src/command_prompt/access_tests.c 		\
		src/command_prompt/dire_command.c 		\
		src/command_prompt/list_to_tab.c 		\
		src/main_functions/env_to_list.c 		\
		src/built_in/built_in_command.c 		\
		src/built_in/setenv.c 					\
		src/built_in/remove_var.c 				\
		src/built_in/env.c 						\
		src/built_in/get_env_values.c 			\
		src/built_in/unsetenv.c					\
		src/built_in/error_change_dir.c 		\
		src/built_in/change_dir_options.c 		\
		src/built_in/change_dir.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy
clean:
	make -C lib/my clean
	rm -f $(OBJ)
fclean:	clean

re:	fclean all

.PHONY:	clean
