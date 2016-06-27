/*
** get_retour.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Thu Jun 02 15:49:29 2016 juquet_q
** Last update Fri Jun 03 14:21:10 2016 juquet_q
*/

#include <stdlib.h>
#include "bashrc.h"

char	*get_retour(char *str)
{
  int	i;
  int	j;
  char	*retour;

  j = i = 0;
  while (str[i] != '\0' && str[i] != '=')
    i++;
  if (str[i] == '=')
    i++;
  else
    return (NULL);
  if ((retour = malloc(sizeof(char) * (my_strlen(&str[i]) + 1))) == NULL)
    return (NULL);
  retour = my_memset(retour, '\0', (my_strlen(&str[i]) + 1));
  while (str[i] != '\0')
    {
      retour[j] = str[i];
      j++;
      i++;
    }
  return (retour);
}
