/*
** env_add.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 14:33:43 2016 Gabriel de Blois
** Last update Sun Jun  5 15:05:23 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include "shell.h"

t_env	*env_new_add(t_env *list, const char *data)
{
  t_env	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (list);
  tmp->info = (char *)data;
  tmp->next = NULL;
  return (env_add(list, tmp));
}

t_env	*env_add(t_env *list, t_env *to_add)
{
  t_env	*tmp;

  if ((tmp = list) == NULL)
    return (to_add);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = to_add;
  return (list);
}
