/*
** my_printf.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:57:14 2016 Matthis Le Texier
** Last update Mon Apr  4 09:57:16 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	<stdarg.h>
#include	"my.h"

int		my_printf(const char *format, ...)
{
  int		ret;
  va_list	vl;

  if (format == NULL)
    return (RET_ERROR);
  va_start(vl, format);
  ret = my_vfprintf(STD_OUTPUT, format, &vl);
  va_end(vl);
  return (ret);
}
