/*
** my_realloc.c for libmy in /home/flipper/rendu/template/lib/my/memory/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:55:18 2016 Matthis Le Texier
** Last update Mon Apr 25 08:51:47 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_realloc(void *ptr, int old_size, int new_size)
{
  void		*new_ptr;

  if ((new_ptr = my_malloc(new_size)) == NULL)
    return (NULL);
  if (ptr == NULL)
    return (new_ptr);
  if (my_memcpy(new_ptr, ptr, MIN(old_size, new_size)) == RET_FAILURE)
    return (NULL);
  free(ptr);
  return (new_ptr);
}
