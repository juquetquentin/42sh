/*
** push_it.c for push it in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Wed Apr 20 12:12:23 2016 lacorr_f
** Last update Thu Jun 02 15:18:38 2016 lacorr_f
*/

#include "shell.h"

void    push_it(t_linked_list **stack, t_token token)
{
  t_linked_list *tamp;
  t_linked_list *new;

  tamp = *stack;
  if (tamp == NULL)
    {
      if ((tamp = malloc(sizeof(*tamp))) == NULL)
	exit(EXIT_FAILURE);
      tamp->next = NULL;
      tamp->token = token;
      *stack = tamp;
    }
  else
    {
      while (tamp->next != NULL)
        tamp = tamp->next;
      if ((new = malloc(sizeof(*tamp))) == NULL)
	exit(EXIT_FAILURE);
      new->next = NULL;
      new->token = token;
      tamp->next = new;
    }
}
