/*
** list_env_to_tab.c for list_env to tab in /home/lacorr_f/rendu/PSU_2015_42sh/src/parsing
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Tue May 31 16:54:45 2016 lacorr_f
** Last update Sat Jun 04 22:20:28 2016 lacorr_f
*/

#include <string.h>
#include "shell.h"

static char	**allocation_tab(t_env *env)
{
  size_t	env_size;
  char		**out;

  env_size = 0;
  while (env != NULL)
    {
      env_size = env_size + 1;
      env = env->next;
    }
  if ((out = calloc((env_size + 1) * sizeof(char *),
		    (env_size + 1) * sizeof(char *))) == NULL)
    exit(EXIT_FAILURE);
  return (out);
}

static void	env_copy_in_tab(char **out, t_env *env)
{
  size_t	tab_pos;
  char		*tmp;

  tab_pos = 0;
  while (env != NULL && env->info != NULL)
    {
      tmp = strdup(env->info);
      if (tmp != NULL)
	out[tab_pos] = tmp;
      else
	exit(EXIT_FAILURE);
      tab_pos = tab_pos + 1;
      env = env->next;
    }
}

char	**list_env_to_tab(t_env **env)
{
  char	**out;

  out = allocation_tab(*env);
  env_copy_in_tab(out, *env);
  return (out);
}
