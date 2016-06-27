/*
** get_type.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Thu Jun 02 14:27:42 2016 juquet_q
** Last update Thu Jun 02 17:24:50 2016 juquet_q
*/

#include <stdlib.h>
#include "bashrc.h"

int	get_type(char *str)
{
  if (str == NULL)
    return (BAD_TYPE);
  else if (my_strcmp("alias ", str) == 1)
    return (ALIAS);
  else if (my_strcmp("export ", str) == 1)
    return (EXPORT);
  return (BAD_TYPE);
}
