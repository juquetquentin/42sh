/*
** my_memset.c for libmy in /home/flipper/rendu/template/lib/my/memory/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:55:07 2016 Matthis Le Texier
** Last update Mon Apr 25 08:51:09 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_memset(void *ptr, int c, int size)
{
  int		i;
  char		*tmp;

  if (ptr == NULL)
    return (RET_FAILURE);
  tmp = (char *)ptr;
  i = -1;
  while (++i < size)
    tmp[i] = c;
  return (RET_SUCCESS);
}
