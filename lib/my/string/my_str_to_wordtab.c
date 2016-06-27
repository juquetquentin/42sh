/*
** spe_str_to_wordtab.c for t in /home/gaby/rendu/CPE/CPE_2015_corewar/asm/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon Mar 14 10:48:36 2016 Gabriel de Blois
** Last update Mon May  2 14:44:11 2016 Matthis Le Texier
*/

#include <stdlib.h>
#include "my.h"

static int	len_word(char *str, int index)
{
  int		i;

  i = index;
  while (str[i] && str[i] != ' ')
    i++;
  return (i - index);
}

static int	space_nbr(char *str)
{
  int		i;
  int		ret;

  ret = 0;
  i = -1;
  while (str[++i])
    ret += (str[i] == ' ') ? 1 : 0;
  return ret;
}

char		**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  my_strclean(str);
  if ((tab = my_malloc(sizeof(char *) * (space_nbr(str) + 1))) == NULL)
    return NULL;
  i = -1;
  k = -1;
  while (str[++i])
    {
      if ((tab[++k] = my_malloc(sizeof(char) * len_word(str, i) + 1)) == NULL)
	return NULL;
      j = -1;
      while (str[++i] && str[++i] != ' ')
	tab[k][++j] = str[i];
      tab[k][j] = '\0';
      if (!str[i])
	break;
    }
  return (tab);
}
