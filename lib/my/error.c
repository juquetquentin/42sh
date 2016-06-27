/*
** error.c for libmy in /home/flipper/rendu/template/lib/my/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 10:29:55 2016 Matthis Le Texier
** Last update Mon Apr  4 10:29:56 2016 Matthis Le Texier
*/

#include	<stdarg.h>
#include	"my.h"

int		error_int(int code, const char *msg, ...)
{
  va_list	vl;

  va_start(vl, msg);
  my_fputstr(ERR_OUTPUT, "[ERROR] ");
  my_vfprintf(ERR_OUTPUT, msg, &vl);
  my_fputchar(ERR_OUTPUT, '\n');
  va_end(vl);
  return (code);
}

void		*error_ptr(void *ptr, const char *msg, ...)
{
  va_list	vl;

  va_start(vl, msg);
  my_fputstr(ERR_OUTPUT, "[ERROR] ");
  my_vfprintf(ERR_OUTPUT, msg, &vl);
  my_fputchar(ERR_OUTPUT, '\n');
  va_end(vl);
  return (ptr);
}

bool		error_bool(bool val, const char *msg, ...)
{
  va_list	vl;

  va_start(vl, msg);
  my_fputstr(ERR_OUTPUT, "[ERROR] ");
  my_vfprintf(ERR_OUTPUT, msg, &vl);
  my_fputchar(ERR_OUTPUT, '\n');
  va_end(vl);
  return (val);
}
