/*
** my_strncpy.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 10:00:04 2016 Matthis Le Texier
** Last update Mon Apr  4 10:00:05 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strncpy(char *dest, const char *src, int n)
{
  int		i;

  if (dest == NULL || src == NULL)
    return (RET_FAILURE);
  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (RET_SUCCESS);
}
