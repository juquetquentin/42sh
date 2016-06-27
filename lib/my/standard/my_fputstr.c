/*
** my_fputstr.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:56:53 2016 Matthis Le Texier
** Last update Mon Apr  4 09:56:54 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"my.h"

int		my_fputstr(const int fd, const char *str)
{
  int		ret;

  if (str == NULL)
    return (RET_ERROR);
  if ((ret = write(fd, str, my_strlen(str))) == RET_ERROR)
    if (write(ERR_OUTPUT, "my_fputstr: cannot write.\n", 26) == RET_ERROR)
      return (RET_ERROR);
  return (ret);
}
