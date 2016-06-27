/*
** check_redir_right.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/exec/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Thu Jun  2 17:19:19 2016 Gabriel de Blois
** Last update Sun Jun 05 15:16:43 2016 lacorr_f
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "shell.h"

int 	check_redir_right(char **args)
{
  int	fd;
  int	i;

  i = -1;
  fd = -1;
  while (args[++i] != NULL)
    {
      if (args[i][0] == '>' && args[i][1] != '>')
	{
	  if ((fd = open(args[i + 1], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR |
			 S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
      	    return (-1);
	  args[i] = NULL;
	  break;
      	}
      if (args[i][0] == '>' && args[i][1] == '>')
	{
	  if ((fd = open(args[i + 1], O_WRONLY | O_APPEND | O_CREAT, S_IRUSR |
			 S_IRGRP | S_IWGRP | S_IWUSR)) == -1)
	    return (-1);
	  args[i] = NULL;
	  break;
	}
    }
  return (fd);
}

void	make_double_left(char **args, int i)
{
  char *str;

  if ((str = get_next_line(0)) == NULL)
    exit(EXIT_FAILURE);
  while (strcmp(str, args[i + 1]) != 0)
    {
      free(str);
      if ((str = get_next_line(0)) == NULL)
	exit(EXIT_FAILURE);
    }
}

int 	check_redir_left(char **args)
{
  int	fd;
  int	i;

  i = 0;
  fd = -1;
  while (args[i] != NULL)
    {
      if (args[i][0] == '<' && args[i][1] != '<')
        {
          if ((fd = open(args[i + 1], O_RDONLY)) == -1)
            return (-1);
          break;
	}
      else if (args[i][0] == '<' && args[i][1] == '<')
	{
	  make_double_left(args, i);
	  args[i] = NULL;
	  exit(EXIT_FAILURE);
	}
      i++;
    }
  args[i] = NULL;
  return (fd);
}
