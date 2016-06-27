/*
** env_search_keyword.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 14:08:18 2016 Gabriel de Blois
** Last update Mon May  2 15:31:50 2016 Gabriel de Blois
*/

#include <string.h>
#include "shell.h"

const char	*env_search_keyword(const char **env, const char *keyword)
{
  int	i;

  i = -1;
  while (env[++i] != NULL)
    {
      if (strncmp(keyword, env[i], strlen(keyword) - 1) == 0)
	return (env[i]);
    }
  return (NULL);
}
