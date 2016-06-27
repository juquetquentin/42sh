/*
** free_data.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/preload/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 15:59:58 2016 Gabriel de Blois
** Last update Mon May  2 16:00:18 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include "shell.h"

t_data	*free_data(t_data *data)
{
  if (data == NULL)
    return (NULL);
  if (data->env != NULL)
    data->env = free_env_list(data->env);
  if (data->plist != NULL)
    data->plist = free_env_list(data->plist);
  return (free(data), NULL);
}
