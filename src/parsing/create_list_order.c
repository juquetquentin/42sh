/*
** create_list_order.c for list order in /home/lacorr_f/rendu/PSU_2015_42sh/src/parsing
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Tue May 31 16:52:58 2016 lacorr_f
** Last update Sat Jun 04 22:27:23 2016 juquet_q
*/

#include "shell.h"

t_order		*create_order_operateur(t_order *commande, t_lexer *lex)
{
  char 		*operateur;

  operateur = pop_commande(&lex->operateur);
  if (operateur[0] == '|' && operateur[1] == '\0')
    push_commande(&commande, operateur, 1);
  else if (operateur[0] == ';')
    push_commande(&commande, operateur, 3);
  else
    push_commande(&commande, operateur, 2);
  return (commande);
}

t_order *create_list_order(t_lexer *lex)
{
  t_order *commande;
  char *option;
  char *tamp_c;
  int index;
  int len_max;

  index = 0;
  commande = NULL;
  len_max = len_list(&lex->commande);
  while (index < len_max)
    {
      tamp_c = pop_commande(&lex->commande);
      while (lex->option != NULL && lex->option->token.id == index)
	{
	  option = pop_commande(&lex->option);
	  tamp_c = str_conc(tamp_c, " ");
	  tamp_c = str_conc(tamp_c, option);
	}
      push_commande(&commande, tamp_c, 0);
      if (lex->operateur != NULL)
	commande = create_order_operateur(commande, lex);
      index++;
    }
  return (commande);
}
