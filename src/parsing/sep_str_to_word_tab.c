/*
** sep_str_to_word_tab.c for sep in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Sat Apr 30 21:08:01 2016 lacorr_f
** Last update Thu Jun 02 15:20:09 2016 lacorr_f
*/

#include "shell.h"

int     sep_nb_word(char *str, char sep)
{
  int   i;
  int   nb;

  i = 0;
  nb = 1;
  while (str[i] != 0)
    {
      if (str[i] == sep && str[i + 1] != 0)
        nb++;
      i++;
    }
  return (nb);
}

char    **sep_malloc_double_tab(char **tab, int nbword, int len)
{
  int   i;

  i = 0;
  while (i < nbword)
    {
      if ((tab[i] = malloc((len + 2) * sizeof(char))) == NULL)
	exit(EXIT_FAILURE);
      tab[i] = memset(tab[i], 0, len + 2);
      i++;
    }
  return (tab);
}

char    **sep_fill_tab(char **tab, char *line, int nbword, char sep)
{
  int   count;
  int   i;
  int   j;

  i = 0;
  count = 0;
  while (count < nbword)
    {
      j = 0;
      while (line[i] != sep && line[i] != 0)
	{
	  tab[count][j] = line[i];
	  j++;
	  i++;
	}
      i++;
      count++;
    }
  return (tab);
}

char    **sep_str_to_wordtab(char *line, char sep)
{
  int   nbword;
  char  **tab;

  nbword = sep_nb_word(line, sep);
  if ((tab = malloc((nbword + 1) * sizeof(char*))) == NULL)
    exit(EXIT_FAILURE);
  tab = init_all(tab, 0, nbword + 1);
  if ((tab = sep_malloc_double_tab(tab, nbword, my_strlen(line))) == NULL)
    exit(EXIT_FAILURE);
  tab = sep_fill_tab(tab, line, nbword, sep);
  tab[nbword] = NULL;
  return (tab);
}
