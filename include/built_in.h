/*
** built_in.h for t in /home/gaby/rendu/PSU/PSU_2015_42sh/include/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 13:19:50 2016 Gabriel de Blois
** Last update Sat Jun 04 20:35:53 2016 moutou_m
*/

#include "typedef.h"

#ifndef BUILT_IN_H_
# define BUILT_IN_H_

# include <stdbool.h>

# define NB_BUILT_IN	(5)
# define BUILT_IN(name) { # name, built_in_ ## name }

typedef	struct	s_built_template
{
  const	char	*name;
  bool		(*func)(const char **cmd, t_data *data);
}               t_built_template;

/*
** TYPEDEF_STRUCTS
*/

bool	is_builtin(char **cmd, t_data *data);
size_t	built_in_tab_len(const char **tab);
bool	is_charalpha(const char c);
bool	is_charnumber(const char c);
bool	is_number(const char *str);
bool	built_in_echo(const char **cmd, t_data *data);
bool	built_in_exit(const char **cmd, t_data *data);
bool	built_in_setenv(const char **cmd, t_data *data);
bool	built_in_unsetenv(const char **cmd, t_data *data);
bool	built_in_cd(const char **cmd, t_data *data);
void	change_pwd(t_data *data, char *pwd_prev);

#endif

/*
** BUILT_IN_H_
*/
