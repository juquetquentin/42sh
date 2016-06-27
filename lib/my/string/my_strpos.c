/*
** my_strpos.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 10:00:16 2016 Matthis Le Texier
** Last update Mon Apr  4 10:00:18 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strpos(const char *str, int c)
{
  int		i;

  if (str == NULL)
    return (RET_ERROR);
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (RET_ERROR);
}
