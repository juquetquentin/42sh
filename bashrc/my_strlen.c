/*
** my_strlen.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Tue May 31 11:36:18 2016 juquet_q
** Last update Fri Jun 03 14:10:54 2016 juquet_q
*/

#include <stdlib.h>

int	my_strlen(char *s)
{
  int	i;

  i = 0;
  if (s == NULL)
    return (0);
  while (s[i])
    i++;
  return (i);
}

int	my_strlen_alias(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] && str[i] != '=')
    i++;
  return (i);
}
