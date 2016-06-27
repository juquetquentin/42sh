##
## Makefile for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
##
## Made by juquet_q
## Login   <juquet_q@epitech.net>
##
## Started on  Tue May 31 11:26:57 2016 juquet_q
## Last update Tue May 31 16:04:38 2016 juquet_q
##

NAME			=	bashrc

CC			=	gcc -g3

SRC			= main.c \
					my_str_intro.c \
					get_bash_rc.c \
					get_type.c \
					my_strcmp.c \
					alias.c \
					get_next_line.c \
					add_bashrc.c \
					get_enter.c \
					get_retour.c \
					my_strlen.c \
					find_cmd.c \
					my_memset.c

OBJ			= $(SRC:.c=.o)

CFLAGS	= -I./

RM			= rm -f

all: $(OBJ) $(NAME)

$(NAME):
				$(CC) $(OBJ) -o $(NAME)

clean:
			$(RM) $(OBJ)

fclean: clean
			$(RM) $(NAME)

re: fclean all
