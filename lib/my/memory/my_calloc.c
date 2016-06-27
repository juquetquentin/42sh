/*
** my_calloc.c for libmy in /home/flipper/rendu/template/lib/my/memory/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:46:37 2016 Matthis Le Texier
** Last update Mon Apr 25 08:50:20 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_calloc(int size)
{
  void		*ptr;

  if ((ptr = my_malloc(size)) == NULL)
    return (NULL);
  if (my_memset(ptr, 0, size) == RET_FAILURE)
    return (NULL);
  return (ptr);
}
