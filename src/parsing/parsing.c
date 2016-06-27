/*
** main.c for  in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Tue Apr 19 16:03:34 2016 lacorr_f
** Last update Thu Jun 02 15:16:47 2016 lacorr_f
*/

#include "shell.h"

t_tree		*parsing(char *str, t_data *data)
{
  char		**tab;
  char 		**tab_env;
  t_tree	*tree;
  t_lexer	*lex;
  t_order	*commande;

  (void)data;
  tab_env = list_env_to_tab(&data->env);
  tab = sep_str_to_wordtab(str, ' ');
  if ((lex = lexer(tab, tab_env)) == NULL)
    return (free_parsing(tab, tab_env, lex), NULL);
  if ((commande = create_list_order(lex)) == NULL)
    return (free_parsing(tab, tab_env, lex), NULL);
  put_prev(commande);
  if ((tree = create_tree(commande, NULL)) == NULL)
    return (free_parsing(tab, tab_env, lex), NULL);
  free_parsing(tab, tab_env, lex);
  return (tree);
}
