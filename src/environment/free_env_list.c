/*
** free.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 15:42:05 2016 Gabriel de Blois
** Last update Mon May  2 16:00:27 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include "shell.h"

t_env	*free_env_list(t_env *list)
{
  t_env	*tmp;
  t_env	*prev;

  if ((tmp = list) == NULL)
    return (NULL);
  while (tmp->next)
    {
      prev = tmp;
      tmp = tmp->next;
      prev = free_env(prev);
    }
  if (prev)
    free_env(prev);
  if (tmp)
    free_env(tmp);
  return (NULL);
}
