/*
** get_enter.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Thu Jun 02 14:48:57 2016 juquet_q
** Last update Fri Jun 03 14:21:27 2016 juquet_q
*/

#include <stdio.h>
#include <stdlib.h>
#include "bashrc.h"

char	*get_enter(char *str, t_bashrc *bashrc)
{
  char	*enter;
  int	i;
  int	j;

  j = 0;
  i = (bashrc->type == ALIAS) ? ALIAS_LEN : 0;
  i = (bashrc->type == EXPORT) ? EXPORT_LEN : i;
  if (i == 0)
    return (NULL);
  if ((enter = malloc(sizeof(char) * (my_strlen_alias(&str[i]) + 1))) == NULL)
    return (NULL);
  if (str[i + my_strlen_alias(&str[i])] == '\0')
    return (NULL);
  enter = my_memset(enter, '\0', (my_strlen_alias(&str[i]) + 1));
  while (my_strlen_alias(&str[i]) > 0)
    enter[j++] = str[i++];
  return (enter);
}
