/*
** push_pop_cmd.c for pus in /home/lacorr_f/rendu/PSU_2015_42sh/src/parsing
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Tue May 31 16:51:31 2016 lacorr_f
** Last update Sat Jun 04 22:21:53 2016 lacorr_f
*/

#include "shell.h"

void		push_commande(t_order **commande, char *str, int prio)
{
  t_order 	*tamp;
  t_order 	*new;
  char 		*test;

  test = strdup(str);
  tamp = *commande;
  if (tamp == NULL)
    {
      if ((tamp = malloc(sizeof(*tamp))) == NULL)
	exit(EXIT_FAILURE);
      tamp->instruction = test;
      tamp->priority = prio;
      tamp->next = NULL;
      *commande = tamp;
      return ;
    }
  while (tamp->next != NULL)
    tamp = tamp->next;
  if ((new = malloc(sizeof(*tamp))) == NULL)
    exit(EXIT_FAILURE);
  new->instruction = test;
  new->priority = prio;
  new->next = NULL;
  tamp->next = new;
}

char		*pop_commande(t_linked_list **stack)
{
  char 		*str;
  t_linked_list *tamp;
  t_linked_list *save;

  tamp = *stack;
  if (tamp != NULL)
    {
      str = tamp->token.str;
      save = tamp;
      tamp = tamp->next;
      *stack = tamp;
      free(save);
      return (str);
    }
  else
    return (NULL);
}
