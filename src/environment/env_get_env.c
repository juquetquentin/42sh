/*
** env_get_env.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/environment
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Fri Jun 03 16:09:28 2016 moutou_m
** Last update Fri Jun 03 16:13:20 2016 moutou_m
*/

#include <stdlib.h>
#include "shell.h"

static void	replace_char_by_char(char *str, const char init, const char new)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == init)
	str[i] = new;
      i = i + 1;
    }
}

t_env	*env_get_env(t_env *env, const char *keyword)
{
  char		*tmp;

  while (env != NULL && env->info != NULL)
    {
      if ((tmp = strdup(env->info)) == NULL)
	exit(EXIT_FAILURE);
      replace_char_by_char(tmp, '=', '\0');
      if (strcmp(tmp, keyword) == 0)
	return (free(tmp), env);
      env = env->next;
    }
  return (NULL);
}
