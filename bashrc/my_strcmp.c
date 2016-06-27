/*
** my_strcmp.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:59:24 2016 Matthis Le Texier
** Last update Thu Jun 02 17:36:33 2016 juquet_q
*/

#include	<stdlib.h>

int		my_strcmp(const char *str1, const char *str2)
{
  int		i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i])
    i++;
  return ((str1[i] == '\0') ? 1 : 0);
}
