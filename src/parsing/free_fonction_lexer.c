/*
** free_fontion_lexer.c for free in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Wed May 04 13:51:42 2016 lacorr_f
** Last update Sat Jun 04 22:18:48 2016 lacorr_f
*/

#include "shell.h"

void	free_double_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void			free_list_linked_list(t_linked_list *list)
{
  t_linked_list 	*cursor;

  while ((cursor = list) != NULL)
    {
      list = list->next;
      free(cursor->token.str);
      free(cursor);
    }
}

void	free_lexer(t_lexer *lex)
{
  if (lex == NULL)
    return ;
  free_list_linked_list(lex->commande);
  free_list_linked_list(lex->option);
  free_list_linked_list(lex->operateur);
  free(lex);
}
