/*
** spe_str_to_wordtab.c for t in /home/gaby/rendu/CPE/CPE_2015_corewar/asm/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon Mar 14 10:48:36 2016 Gabriel de Blois
** Last update Tue May 31 18:22:43 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include "shell.h"

void	special_str_to_wordtab(char tab[STR_WORDTAB_VALUE][STR_WORDTAB_VALUE],
			       const char *str,
			       int incr)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] && (str[i] == ' ' || str[i] == '\t' ||
		    str[i] == SEPARATOR_CHAR))
    i++;
  while (str[i] && str[i] != ' ' && str[i] != '\t' &&
	 str[i] != SEPARATOR_CHAR && j < 18)
    {
      tab[incr][j] = str[i];
      i++;
      j++;
    }
  tab[incr][j] = '\0';
  if (str[i] != '\0' && incr < 18)
    special_str_to_wordtab(tab, &str[i], incr + 1);
  else
    tab[incr + 1][0] = '\0';
}
