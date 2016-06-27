/*
** my_strchr.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:58:48 2016 Matthis Le Texier
** Last update Mon Apr  4 09:58:49 2016 Matthis Le Texier
*/

#include	<stdlib.h>

const char	*my_strchr(const char *str, int c)
{
  int		i;

  if (str == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (str + i * sizeof(char));
      i++;
    }
  return (NULL);
}
