/*
** free_parsing.c for 42 in /home/flipper/rendu/42sh/PSU_2015_42sh/src/parsing/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Tue May 31 15:46:26 2016 Matthis Le Texier
** Last update Sat Jun 04 22:18:55 2016 lacorr_f
*/

#include "shell.h"

void		free_tree(t_tree **tree)
{
  t_tree	*cursor;

  cursor = *tree;
  if (cursor == NULL)
    return ;
  if (cursor->right != NULL)
    free_tree(&cursor->right);
  if (cursor->left != NULL)
    free_tree(&cursor->left);
  free(cursor->commande_ptr->instruction);
  free(cursor->commande_ptr);
  free(cursor);
  *tree = NULL;
}

void	free_parsing(char **tab, char **tab_env, t_lexer *lex)
{
  free_double_tab(tab);
  free_double_tab(tab_env);
  free_lexer(lex);
}
