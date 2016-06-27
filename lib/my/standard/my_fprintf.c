/*
** my_fprintf.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:55:45 2016 Matthis Le Texier
** Last update Mon Apr  4 09:55:46 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	<stdarg.h>
#include	"my.h"

int		my_fprintf(const int fd, const char *format, ...)
{
  int		ret;
  va_list	vl;

  if (format == NULL)
    return (RET_ERROR);
  va_start(vl, format);
  ret = my_vfprintf(fd, format, &vl);
  va_end(vl);
  return (ret);
}
