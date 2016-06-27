/*
** is_empty.c for is empty in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Wed Apr 20 12:12:44 2016 lacorr_f
** Last update Sun Jun 05 18:11:15 2016 lacorr_f
*/

#include "shell.h"

int     	is_empty_stack(t_linked_list *stack)
{
  t_linked_list *tamp;
  int   	i;

  tamp = stack;
  i = 0;
  if (stack == NULL)
    return (0);
  while (tamp != NULL)
    {
      tamp = tamp->next;
      i++;
    }
  return (i);
}
