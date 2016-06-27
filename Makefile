##
## Makefile for wolf in /home/gaby/rendu/gfx_wolf3d/
##
## Made by Gabriel de Blois
## Login   <de-blo_g@epitech.eu>
##
## Started on  Wed Dec  9 00:56:53 2015 Gabriel de Blois
## Last update Sun Jun  5 18:10:05 2016 lacorr_f
##

NAME			=	42sh

CC			=	gcc

NOW 			:=	$(shell date +"%d %h %g:%R")

DEFAULT			=	"\033[00m"
GREEN			=	"\033[0;32m"
HIGHLIGHTED		=	"\033[2;102m"
DELETION 		=	"\033[2;103m"
TEAL			=	"\033[1;34m"
RED			=	"\033[1;31m"
ECHO			=	/bin/echo -e

## DEV
PRELOAD_PATH		=	./src/preload/
PARSING_PATH		=	./src/parsing/
ENV_PATH		=	./src/environment/
ENGINE_PATH		=	./src/engine/
BUILTIN_PATH		=	./src/built_in/
EXEC_PATH		=	./src/exec/

## BUILT IN'S Declaration
BUILT_INS_SRC 		= 	$(BUILTIN_PATH)echo/built_in_echo.c \
				$(BUILTIN_PATH)is_builtin.c \
				$(BUILTIN_PATH)exit/built_in_exit.c \
				$(BUILTIN_PATH)setenv/built_in_setenv.c \
				$(BUILTIN_PATH)unsetenv/built_in_unsetenv.c \
				$(BUILTIN_PATH)built_in_additional.c \
				$(BUILTIN_PATH)built_in_tablen.c \
				$(BUILTIN_PATH)cd/built_in_cd.c \
				$(BUILTIN_PATH)cd/built_in_cd_change_pwd.c

ENVIRONMENT_SRC		=	$(ENV_PATH)env_add.c \
				$(ENV_PATH)env_search_keyword.c \
				$(ENV_PATH)get_pwd.c \
				$(ENV_PATH)free_env_list.c \
				$(ENV_PATH)free_env.c \
				$(ENV_PATH)env_disp_list.c \
				$(ENV_PATH)env_delete_by_keyword.c \
				$(ENV_PATH)env_transform_tag.c \
				$(ENV_PATH)env_get_env.c

PARSING_SRC		=	$(PARSING_PATH)detect_lexer.c \
				$(PARSING_PATH)free_fonction_lexer.c \
				$(PARSING_PATH)gestion_tab_string.c \
				$(PARSING_PATH)is_empty.c \
				$(PARSING_PATH)parsing.c \
				$(PARSING_PATH)pop_it.c \
				$(PARSING_PATH)print_fonction_lexer.c \
				$(PARSING_PATH)push_it.c \
				$(PARSING_PATH)sep_str_to_word_tab.c \
				$(PARSING_PATH)str_to_wordtab.c \
				$(PARSING_PATH)tree.c \
				$(PARSING_PATH)free_parsing.c \
				$(PARSING_PATH)lexer.c \
				$(PARSING_PATH)push_pop_cmd.c \
				$(PARSING_PATH)create_list_order.c \
				$(PARSING_PATH)list_env_to_tab.c \
				$(PARSING_PATH)little_function.c \
				$(PARSING_PATH)little_function_2.c

ENGINE_SRC		=	$(ENGINE_PATH)aff_prompt.c \
				$(ENGINE_PATH)clean_buffer.c \
				$(ENGINE_PATH)launch.c \
				$(ENGINE_PATH)my_perror.c

EXEC_SRC		=	$(EXEC_PATH)exec.c \
				$(EXEC_PATH)spe_str_to_wordtab.c \
				$(EXEC_PATH)exec_get_path.c \
				$(EXEC_PATH)exec_or_and_semicolon.c \
				$(EXEC_PATH)exec_pipe.c \
				$(EXEC_PATH)exec_execve.c \
				$(EXEC_PATH)check_redir_right.c \
				$(EXEC_PATH)parent_side.c

SRC			=	src/main.c \
				$(BUILT_INS_SRC) \
				$(ENVIRONMENT_SRC) \
				$(ENGINE_SRC) \
				$(PRELOAD_PATH)preload.c \
				$(PRELOAD_PATH)free_data.c \
				$(EXEC_SRC) \
				$(PARSING_SRC)

LIBMY			=	libmy.a

LIBMYPATH		=	./lib

LIB			=	-lmy -L./lib

CFLAGS			+=	-W -Wall -Wextra \
				-I./include

OBJ			=	$(SRC:.c=.o)

RM			=	rm -f

all:		$(NAME)

makelib:
		@$(ECHO) $(GREEN) "\n > COMPILING LIBMY: Done\n" $(DEFAULT)
		@make -C $(LIBMYPATH) > /dev/null

makelibre:
		@make re -C $(LIBMYPATH)


$(NAME):	makelib $(OBJ)
		@$(CC) $(OBJ) -o $(NAME)  $(LIB)
		@$(ECHO) $(HIGHLIGHTED)"COMPILATION SUCCEEDED ON "$(NOW)$(DEFAULT)

clean:
		@make clean -C $(LIBMYPATH)
		@$(ECHO) $(RED)"\n > REMOVING LIBMY OBJECTS: Done\n" $(DEFAULT)
		@$(RM) $(OBJ)
		@$(ECHO) $(DELETION)"OBJs PROPERLY DELETED"$(DEFAULT)

fclean:		clean
		@make fclean -C $(LIBMYPATH)
		@$(ECHO) $(RED) "\n > REMOVING LIBMY.A: Done" $(DEFAULT)
		@$(RM) $(NAME)
		@$(ECHO) $(DELETION)"BINARY PROPERLY DELETED"$(DEFAULT)

re:		fclean makelibre all

.PHONY:		all clean fclean re

.c.o:
		@$(CC) $(LIB) $(CFLAGS) -c $< -o $@  && \
		$(ECHO) $(GREEN) " [OK] " $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) " [XX] " $(TEAL) $< $(DEFAULT)
