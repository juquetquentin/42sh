/*
** my_malloc.c for libmy in /home/flipper/rendu/template/lib/my/memory/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:46:14 2016 Matthis Le Texier
** Last update Mon Apr 25 08:50:28 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

void		*my_malloc(unsigned int size)
{
  void		*ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      my_fprintf(ERR_OUTPUT, "Can't perform malloc\n");
      return NULL;
    }
  return (ptr);
}
