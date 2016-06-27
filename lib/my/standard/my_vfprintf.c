/*
** my_vfprintf.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:56:07 2016 Matthis Le Texier
** Last update Mon Apr 25 08:52:29 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	<stdarg.h>
#include	"my.h"

static int	fmt_foo(char, const int, va_list *vl);

int		my_vfprintf(const int fd, const char *format, va_list *vl)
{
  int		i;
  int		len;
  int		fmt_ret;
  
  if (format == NULL)
    return (RET_ERROR);
  len = 0;
  i = -1;
  while (format[++i])
    {
      if (format[i] == '%' && format[i + 1])
	{
	  if ((fmt_ret = fmt_foo(format[i + 1], fd, vl)) == RET_ERROR)
	    return (RET_ERROR);
	  len += fmt_ret;
	  i++;
	}
      else
	{
	  if (my_fputchar(fd, format[i]) == RET_ERROR)
	    return (RET_ERROR);
	  len++;
	}
    }
  return (len);
}

static int	fmt_foo(char fmt, const int fd, va_list *vl)
{
  if (fmt == '%')
    return (my_fputchar(fd, '%'));
  else if (fmt == 'c')
    return (my_fputchar(fd, va_arg(*vl, int)));
  else if (fmt == 's')
    return (my_fputstr(fd, va_arg(*vl, char *)));
  else if (fmt == 'b')
    return (my_fputnbr_base(fd, va_arg(*vl, int), BASE_BIN));
  else if (fmt == 'o')
    return (my_fputnbr_base(fd, va_arg(*vl, int), BASE_OCT));
  else if (fmt == 'd')
    return (my_fputnbr(fd, va_arg(*vl, int)));
  else if (fmt == 'x')
    return (my_fputnbr_base(fd, va_arg(*vl, int), BASE_HEX));
  return (RET_ERROR);
}
