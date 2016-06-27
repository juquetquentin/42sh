/*
** pop_it.c for pop in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Wed Apr 20 12:13:37 2016 lacorr_f
** Last update Sat Jun 04 22:20:59 2016 lacorr_f
*/

#include "shell.h"

int     len_stack(t_linked_list **stack)
{
  t_linked_list       *tamp;
  int           i;

  i = 0;
  tamp = *stack;
  while (tamp != NULL)
    {
      tamp = tamp->next;
      i++;
    }
  return (i);
}

char  *pop_it(t_linked_list **stack)
{
  int   len;
  int   i;
  char 	*str;
  t_linked_list *tamp;

  i = -1;
  tamp = *stack;
  len = len_stack(stack);
  if (len == 1)
    {
      str = tamp->token.str;
      free(*stack);
      *stack = NULL;
      return (str);
    }
  while (++i < len - 2)
    tamp = tamp->next;
  if ((str = malloc(my_strlen(tamp->token.str) + 1)) == NULL)
    exit(EXIT_FAILURE);
  str = memset(str, 0, my_strlen(tamp->token.str) + 1);
  str = strcpy(tamp->token.str, str);
  free(tamp->next);
  tamp->next = NULL;
  return (str);
}
