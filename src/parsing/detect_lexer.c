/*
** detect_lexer.c for detect in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Wed May 04 14:12:37 2016 lacorr_f
** Last update Sat Jun 04 22:18:41 2016 lacorr_f
*/

#include "shell.h"

int		commande_detect(t_lexer *lex, char **tab, int i)
{
  t_token 	token;

  if ((token.str = malloc(strlen(tab[i]) + 1)) == NULL)
    exit(EXIT_FAILURE);
  memset(token.str, 0, strlen(tab[i] + 1));
  token.str = strcpy(token.str, tab[i]);
  token.id = 0;
  token.id = lex->id;
  push_it(&lex->commande, token);
  return (1);
}

void		operateur_detect(char **tab, t_lexer *lex, int i)
{
  t_token 	token;

  if ((token.str = malloc(my_strlen(tab[i]) + 1)) == NULL)
    exit(EXIT_FAILURE);
  memset(token.str, 0, my_strlen(tab[i] + 1));
  token.str = strcpy(token.str, tab[i]);
  token.id = lex->id;
  push_it(&lex->operateur, token);
}

void		option_detect(char **tab, t_lexer *lex, int i)
{
  t_token 	token;

  if ((token.str = malloc(my_strlen(tab[i]) + 1)) == NULL)
    exit(EXIT_FAILURE);
  memset(token.str, 0, my_strlen(tab[i] + 1));
  token.str = strcpy(token.str, tab[i]);
  token.id = lex->id;
  push_it(&lex->option, token);
}
