/*
** little_function.c for little in /home/lacorr_f/rendu/PSU_2015_42sh/src/parsing
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Tue May 31 16:56:53 2016 lacorr_f
** Last update Sun Jun 05 18:11:55 2016 lacorr_f
*/

#include "shell.h"

int     nb_path(char *str)
{
  int   i;
  int   nb_path;

  i = 0;
  nb_path = 0;
  while (str[i] != 0)
    {
      if (str[i] == ':')
        nb_path++;
      i++;
    }
  return (nb_path + 1);
}

int		len_list(t_linked_list **stack)
{
  int 		i;
  t_linked_list *tamp;

  i = 0;
  tamp = *stack;
  while (tamp != NULL)
    {
      tamp = tamp->next;
      i++;
    }
  return (i);
}

void 		aff_list(t_linked_list **list)
{
  t_linked_list *tamp;

  tamp = *list;
  while (tamp != NULL)
    {
      printf(">> %s\n", tamp->token.str);
      tamp = tamp->next;
    }
}

int		search_opp(t_order *commande)
{
  t_order 	*tamp;
  int 		opp;

  opp = 0;
  tamp = commande;
  while (tamp != NULL)
    {
      if (tamp->priority >= opp)
	opp = tamp->priority;
      tamp = tamp->next;
    }
  return (opp);
}

void	print_command_list(t_order *commande)
{
  while (commande)
    {
      printf("com = %s :: priority = %d\n", commande->instruction,
	     commande->priority);
      commande = commande->next;
    }
}
