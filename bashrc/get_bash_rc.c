/*
** get_bash_rc.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Thu Jun 02 14:07:40 2016 juquet_q
** Last update Fri Jun 03 14:35:13 2016 juquet_q
*/

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "bashrc.h"

t_bashrc	*get_bash_rc(char *path, t_bashrc *bashrc)
{
  int	fd;
  char	*buff;

  if ((fd = open(path, O_RDONLY)) < 0)
    return (NULL);
  while ((buff = get_next_line(fd)) != NULL)
    {
      if ((bashrc->type = get_type(buff)) == BAD_TYPE)
	return (NULL);
      if ((bashrc->enter = get_enter(buff, bashrc)) == NULL)
	return (NULL);
      if ((bashrc->retour = get_retour(buff)) == NULL)
	return (NULL);
      if ((bashrc = add_bashrc(bashrc)) == NULL)
	return (NULL);
    }
  while (bashrc->prev != NULL)
    bashrc = bashrc->prev;
  return (bashrc);
}
