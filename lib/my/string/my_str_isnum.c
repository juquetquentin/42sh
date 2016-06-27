/*
** my_str_isnum.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:58:30 2016 Matthis Le Texier
** Last update Mon Apr  4 09:58:31 2016 Matthis Le Texier
*/

#include	"my.h"

bool		my_str_isnum(const char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] == '-' && str[i] == '+')
    i++;
  if (str[i] == '0')
    return (false);
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
        return (false);
      i++;
    }
  return (true);
}
