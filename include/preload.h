/*
** preload.h for t in /home/gaby/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Tue Apr  5 17:55:50 2016 Gabriel de Blois
** Last update Mon May  2 15:58:14 2016 Gabriel de Blois
*/

#ifndef PRELOAD_H_
# define PRELOAD_H_

# ifndef	TYPEDEF_STRUCTS
#  define	TYPEDEF_STRUCTS
typedef	        int			t_incr;
typedef	struct	s_tabincr	t_tabincr;
typedef struct	s_env		t_env;
typedef struct	s_data		t_data;
typedef	        t_env		t_path;
typedef	        t_env		t_stack;
# endif

/*
** TYPEDEF_STRUCTS
*/

t_data	*preload_shell(const char **env);
t_data	*free_data(t_data *data);

#endif

/*
** PRELOAD_H_
*/
