/*
** my_str_intro.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Tue May 31 11:09:36 2016 juquet_q
** Last update Sat Jun 04 19:05:59 2016 juquet_q
*/

#include <stdio.h>
#include <stdlib.h>
#include "bashrc.h"

char	*my_str_intro(char *enter, char *find, char *replace)
{
  char	*output;
  int	i;
  int	len;

  i = 0;
  len = my_strlen(enter) + my_strlen(replace) - my_strlen(find) + 1;
  if ((output = malloc(sizeof(char) * len)) == NULL)
    return (NULL);
  output = my_memset(output, '\0', len);
  while (find_cmd(enter, find) != 0 && *enter != '\0')
    {
      output[i++] = *enter;
      enter++;
    }
  if (find_cmd(enter, find) == 0)
    while (*replace != '\0')
	{
	  output[i++] = *replace;
	  replace++;
	}
  while (*enter != '\0' && output[i])
    {
      output[i++] = *enter;
      enter++;
    }
  return (output);
}
