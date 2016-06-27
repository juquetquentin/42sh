/*
** free_env.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 15:59:02 2016 Gabriel de Blois
** Last update Mon May  2 16:00:43 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include "shell.h"

t_env	*free_env(t_env *tmp)
{
  if (tmp == NULL)
    return (NULL);
  if (tmp->info != NULL)
    free((char*)tmp->info);
  return (free(tmp), NULL);
}
