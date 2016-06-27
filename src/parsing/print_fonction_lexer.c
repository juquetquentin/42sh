/*
** print_fonction_lexer.c for lexer print in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Wed May 04 13:49:32 2016 lacorr_f
** Last update Sat Jun 04 22:21:16 2016 lacorr_f
*/

#include "shell.h"

void	print_double_tab(char **tab)

{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      printf("%s\n", tab[i]);
      i++;
    }
}

void		print_linked_list(t_linked_list **stack, char *name)
{
  t_linked_list *tamp;

  tamp = *stack;
  my_printf("%s\n", name);
  while (tamp != NULL)
    {
      my_printf("%s %d\n", tamp->token.str, tamp->token.id);
      tamp = tamp->next;
    }
}

void	print_all_stack(t_lexer *lex)
{
  print_linked_list(&lex->commande, "\n    COMMANDE\n");
  print_linked_list(&lex->option, "\n    OPTION\n");
  print_linked_list(&lex->operateur, "\n    OPERATEUR\n");
}
