/*
** my_strcpy.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:59:30 2016 Matthis Le Texier
** Last update Mon Apr  4 09:59:31 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strcpy(char *dest, const char *src)
{
  int		i;

  if (dest == NULL || src == NULL)
    return (RET_FAILURE);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (RET_SUCCESS);
}
