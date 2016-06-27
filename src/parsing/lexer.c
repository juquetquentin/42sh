/*
** lexer.c for lex in /home/lacorr_f/rendu/PSU_2015_42sh/src/parsing
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Tue May 31 16:49:40 2016 lacorr_f
** Last update Sun Jun 05 13:35:52 2016 lacorr_f
*/

#include "shell.h"

t_lexer 	*malloc_lexer(void)
{
  t_lexer 	*lex;

  if ((lex = malloc(sizeof(*lex))) == NULL)
    exit(-1);
  if ((lex->commande = malloc(sizeof(*lex->commande))) == NULL)
    exit(-1);
  if ((lex->option = malloc(sizeof(*lex->option))) == NULL)
    exit(-1);
  if ((lex->operateur = malloc(sizeof(*lex->operateur))) == NULL)
    exit(-1);
  lex->commande = NULL;
  lex->option = NULL;
  lex->operateur = NULL;
  return (lex);
}

t_lexer 	*boucle_lexer(t_lexer *lex, char **paths_sep,
			      char **tab, int i)
{
  static int 	commande = 0;

  (void)paths_sep;
  if (i == 0)
    commande = 0;
  if (commande == 0 && tab[i][0] != '<' && tab[i][0] != '>' &&
      tab[i][0] != '|' && tab[i][0] != '&' &&
      tab[i][0] != ';')
    {
      if (((commande = commande_detect(lex, tab, i))) == -1)
	return (NULL);
    }
  else if (tab[i][0] == '|' || tab[i][0] == '&' || tab[i][0] == ';')
      operateur_detect(tab, lex, i);
  else
    option_detect(tab, lex, i);
  if (tab[i][0] == '|' || tab[i][0] == ';' || tab[i][0] == '&')
    {
      lex->id++;
      commande = 0;
    }
  return (lex);
}

t_lexer		*lexer(char **tab, char **env)
{
  int 		i;
  char 		**paths_sep;
  t_lexer 	*lex;

  i = 0;
  (void)env;
  lex = malloc_lexer();
  paths_sep = NULL;
  lex->id = 0;
  while (tab[i] != 0)
    {
      if (boucle_lexer(lex, paths_sep, tab, i) == NULL)
	return (free_double_tab(paths_sep), NULL);
      i++;
    }
  free_double_tab(paths_sep);
  return (lex);
}
