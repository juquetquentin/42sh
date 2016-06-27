/*
** gestion_tab_string.c for gestion in /home/lacorr_f/rendu/parceur_42/src
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Wed May 04 14:14:21 2016 lacorr_f
** Last update Sat Jun 04 22:19:29 2016 lacorr_f
*/

#include "shell.h"

int 	len_double_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i] != NULL)
    i++;
  return (i);
}

void    *init_all(void *dest, int c, int size)
{
  char  *tamp;
  int   i;

  tamp = dest;
  i = 0;
  while (i < size)
    {
      tamp[i] = c;
      i++;
    }
  return (dest);
}

char    *str_conc(char *str_1, char *str_2)
{
  char  *new;
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str_1[i] != 0)
    i++;
  while (str_2[j] != 0)
    j++;
  if ((new = malloc((i + j + 1) * sizeof (char))) == NULL)
    exit(-1);
  memset(new, 0, i + j + 1);
  i = -1;
  j = -1;
  while (str_1[++i] != 0)
    new[i] = str_1[i];
  while (str_2[++j] != 0)
    {
      new[i] = str_2[j];
      i++;
    }
  return (new);
}
