/*
** env_disp_list.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Tue May  3 17:55:41 2016 Gabriel de Blois
** Last update Tue May  3 17:57:36 2016 Gabriel de Blois
*/

#include <stdio.h>
#include "shell.h"

void	env_disp_list(t_env *list)
{
  t_env	*tmp;

  if ((tmp = list) == NULL)
    return ;
  while (tmp)
    {
      printf("%s\n", tmp->info);
      tmp = tmp->next;
    }
}
