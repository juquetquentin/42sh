/*
** my_strlen.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:59:45 2016 Matthis Le Texier
** Last update Mon Apr  4 09:59:46 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_strlen(const char *str)
{
  int		len;

  if (str == NULL)
    return (RET_ERROR);
  len = 0;
  while (str[len])
    len++;
  return (len);
}
