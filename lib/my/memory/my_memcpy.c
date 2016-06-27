/*
** my_memcpy.c for libmy in /home/flipper/rendu/template/lib/my/memory/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:51:42 2016 Matthis Le Texier
** Last update Mon Apr 25 08:50:52 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_memcpy(void *dest, const void *src, int size)
{
  int		i;
  char		*dest_tmp;
  const char	*src_tmp;

  if (dest == NULL || src == NULL)
    return (RET_FAILURE);
  dest_tmp = (char *)dest;
  src_tmp = (char *)src;
  i = -1;
  while (++i < size)
    dest_tmp[i] = src_tmp[i];
  return (RET_SUCCESS);
}
