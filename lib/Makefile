##
## Makefile for template in /home/flipper/rendu/template/lib/
##
## Made by Matthis Le Texier
## Login   <le-tex_m@epitech.eu>
##
## Started on  Fri Nov 13 16:39:59 2015 Matthis Le Texier
## Last update Mon May  2 14:24:11 2016 Matthis Le Texier
##

#########
#  LIB  #
#########
LIBNAME	=	libmy.a

##################
#  SRCS FOLDERS  #
##################
MEMORY	=	memory/
STAND	=	standard/
STRING	=	string/

DEFAULT			=	"\033[00m"
GREEN			=	"\033[0;32m"
HIGHLIGHTED		=	"\033[2;102m"
DELETION 		=	"\033[2;103m"
TEAL			=	"\033[1;34m"
RED			=	"\033[1;31m"
ECHO			=	/bin/echo -e

#########
#  SRC  #
#########
LIBSRC	=	$(MEMORY)my_calloc.c \
		$(MEMORY)my_malloc.c \
		$(MEMORY)my_memcpy.c \
		$(MEMORY)my_memset.c \
		$(MEMORY)my_realloc.c \
		$(STAND)my_fprintf.c \
		$(STAND)my_fputchar.c \
		$(STAND)my_fputnbr_base.c \
		$(STAND)my_fputnbr.c \
		$(STAND)my_fputstr.c \
		$(STAND)my_getnbr_base.c \
		$(STAND)my_getnbr.c \
		$(STAND)my_printf.c \
		$(STAND)my_putchar.c \
		$(STAND)my_putnbr_base.c \
		$(STAND)my_putnbr.c \
		$(STAND)my_putstr.c \
		$(STAND)my_vfprintf.c \
	  	$(STRING)my_explode.c \
		$(STRING)my_getline.c \
		$(STRING)my_match.c \
		$(STRING)my_revstr.c \
		$(STRING)my_str_isnum.c \
		$(STRING)my_strcat.c \
		$(STRING)my_strchr.c \
		$(STRING)my_strclean.c \
		$(STRING)my_strcmp.c \
		$(STRING)my_strcpy.c \
		$(STRING)my_strdup.c \
		$(STRING)my_strlen.c \
		$(STRING)my_strncat.c \
		$(STRING)my_strncmp.c \
		$(STRING)my_strncpy.c \
		$(STRING)my_strndup.c \
		$(STRING)my_strpos.c \
		$(STRING)my_strstr.c \
		$(STRING)my_str_to_wordtab.c \
	  	error.c \
	  	get_next_line.c

LIBOBJ	=	$(LIBSRC:%.c=$(LIBPATH)%.o)

LIBPATH	=	./my/

#########
#   H   #
#########
HSUCCES	=	my.h

HNAME   =	$(HSUCCES:%.h=$(LIBPATH)%.h)

HPATH	=	../include/

#############
#  COMPILE  #
#############
CC	=	gcc -g

CFLAGS	=	-I../include -Wall -Wextra

##############
#  COMMANDS  #
##############
ARRC	=	ar rc

RANLIB	=	ranlib

CP	=	cp

WHITE	= \033[0m


all:		$(LIBNAME)

%.o:		%.c
		@$(CC) -o $@ -c $< $(CFLAGS) && \
		$(ECHO) $(GREEN) " [OK] " $(TEAL) $< $(DEFAULT) || \
		$(ECHO) $(RED) " [XX] " $(TEAL) $< $(DEFAULT)

$(LIBNAME):	$(HNAME) $(LIBOBJ)
		@$(ARRC) $(LIBNAME) $(LIBOBJ)
		@$(RANLIB) $(LIBNAME)

$(LIBPATH)%.h:	$(HPATH)%.h
		@$(CP) $< $@


clean:
		@$(RM) $(LIBOBJ)

fclean:		clean
		@$(RM) $(LIBNAME) $(HNAME)

re:		fclean all

.PHONY:		clean fclean all re
