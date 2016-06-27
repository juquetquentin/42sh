/*
** my_strncmp.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:59:58 2016 Matthis Le Texier
** Last update Mon Apr  4 10:00:00 2016 Matthis Le Texier
*/

#include	<stdlib.h>

int		my_strncmp(const char *str1, const char *str2, int n)
{
  int		i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
    i++;
  return (str1[i] - str2[i]);
}
