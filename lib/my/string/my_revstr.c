/*
** my_revstr.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:58:22 2016 Matthis Le Texier
** Last update Mon Apr  4 09:58:24 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_revstr(char *str)
{
  int		strlen;
  int		i;
  char		tmp;

  if (str == NULL)
    return (RET_FAILURE);
  strlen = my_strlen(str);
  i = 0;
  while (i < strlen / 2)
    {
      tmp = str[i];
      str[i] = str[strlen - i];
      str[strlen - i] = tmp;
      i++;
    }
  return (RET_SUCCESS);
}
