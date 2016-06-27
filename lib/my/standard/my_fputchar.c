/*
** my_fputchar.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:56:17 2016 Matthis Le Texier
** Last update Mon Apr  4 09:56:19 2016 Matthis Le Texier
*/

#include	<unistd.h>
#include	"my.h"

int		my_fputchar(const int fd, int c)
{
  int		ret;

  if ((ret = write(fd, &c, 1)) == RET_ERROR)
    if (write(ERR_OUTPUT, "my_fputchar: cannot write.\n", 27) == RET_ERROR)
      return (RET_ERROR);
  return (ret);
}
