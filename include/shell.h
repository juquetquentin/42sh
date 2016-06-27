/*
** shell.h for t in /home/gaby/rendu/PSU/PSU_2015_42sh/include/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 11:16:56 2016 Gabriel de Blois
** Last update Sun Jun 05 15:03:14 2016 moutou_m
*/

#ifndef SHELL_H_
# define SHELL_H_

# define MAX_ARGS (42)
# define MAX_ARG_LEN (1024)
# define ERROR (-1)

# include "my.h"
# include "stdlib.h"
# include "preload.h"
# include "engine.h"
# include "environment.h"
# include "parsing.h"
# include "exec.h"

# define RET_SUCCESS 0
# define RET_FAILURE 1
# define RET_ERRO -1

# ifndef	TYPEDEF_STRUCTS
#  define	TYPEDEF_STRUCTS
typedef	int			t_incr;
typedef	struct	s_tabincr	t_tabincr;
typedef struct	s_env		t_env;
typedef struct	s_data		t_data;
typedef		t_env		t_path;
typedef		t_path		t_stack;
# endif

/*
** TYPEDEF_STRUCTS
*/

typedef	struct	s_tabincr
{
  int	i;
  int	j;
}		t_tabincr;

typedef	t_stack	t_pwd;

typedef struct	s_read
{
  char	c;
  struct s_read *next;
  struct s_read *prev;
}		t_read;

typedef	struct	s_data
{
  t_read	*char_list;
  t_env		*env;
  t_pwd		*plist;
  int		run;
  int		lastreturn;
  bool		built_in_disp;
}		t_data;

void	my_perror(const char *str);

#endif

/*
** SHELL_H_
*/
