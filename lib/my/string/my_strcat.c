/*
** my_strcat.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:58:35 2016 Matthis Le Texier
** Last update Mon Apr  4 09:58:36 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strcat(char *dest, const char *src)
{
  int		i;
  int		dest_len;

  if (dest == NULL || src == NULL)
    return (RET_FAILURE);
  dest_len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[dest_len + i] = src[i];
      i++;
    }
  dest[dest_len + i] = '\0';
  return (RET_SUCCESS);
}
