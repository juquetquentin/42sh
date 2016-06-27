/*
** env_delete_by_keyword.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Tue May  3 18:41:24 2016 Gabriel de Blois
** Last update Tue May  3 18:46:43 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"

/*
** find and delete a node in the environment list thankks to the keyword
** return the new env without the selected node if it exist
*/

t_env	*env_delete_by_keyword(t_env *env, const char *keyword)
{
  t_env	*tmp;
  t_env	*tmprev;

  tmprev = NULL;
  if ((tmp = env) == NULL)
    return (NULL);
  while (tmp)
    {
      if (strncmp(tmp->info, keyword, strlen(keyword) - 1) == 0)
	{
	  if (tmprev == NULL)
	    return (free(tmp), tmp->next);
	  return (tmprev->next = tmp->next, free(tmp), env);
	}
      tmprev = tmp;
      tmp = tmp->next;
    }
  return (env);
}
