/*
** str_to_wordtab.c for strtowrod in /home/lacorr_f/rendu/minishell_2/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Mon Apr 04 00:43:21 2016 lacorr_f
** Last update Thu Jun 02 15:20:39 2016 lacorr_f
*/

#include "shell.h"

int     nb_word(char *str)
{
  int   i;
  int   nb;

  i = 0;
  nb = 1;
  while (str[i] != 0)
    {
      if (str[i] == ' ' && str[i + 1] != 0)
        nb++;
      i++;
    }
  return (nb);
}

char	**malloc_double_tab(char **tab, int nbword, int len)
{
  int	i;

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

char 	**fill_tab(char **tab, char *line, int nbword)
{
  int	count;
  int	i;
  int	j;

  i = 0;
  count = 0;
  while (count < nbword)
    {
      j = 0;
      while (line[i] != ' ' && line[i] != 0)
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

char	**my_str_to_wordtab(char *line)
{
  int	nbword;
  char 	**tab;

  nbword = nb_word(line);
  if ((tab = malloc((nbword + 1) * sizeof(char*))) == NULL)
    exit(EXIT_FAILURE);
  tab = init_all(tab, 0, nbword + 1);
  if ((tab = malloc_double_tab(tab, nbword, my_strlen(line))) == NULL)
    exit(EXIT_FAILURE);
  tab = fill_tab(tab, line, nbword);
  tab[nbword] = NULL;
  return (tab);
}
