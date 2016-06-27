/*
** launch.c for 42sh in /home/flipper/rendu/42sh/PSU_2015_42sh/src/engine/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon May  2 13:29:03 2016 Matthis Le Texier
** Last update Wed Jun  1 19:37:39 2016 juquet_q
*/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

static int	engine(t_data *data, char *buffer)
{
  int		infd[2];
  int		outfd[2];
  t_tree	*tree;

  infd[0] = 0;
  infd[1] = 1;
  outfd[0] = 0;
  outfd[1] = 1;
  clean_buffer(buffer);
  if ((tree = parsing(buffer, data)) == NULL)
    return (RET_SUCCESS);
  launch_exec(tree, data, infd, outfd);
  free_tree(&tree);
  return (RET_SUCCESS);
}

int		launch_42(t_data *data)
{
  char		buffer[READ_SIZE];
  int		oct;

  aff_prompt();
  while ((oct = read(STD_INPUT, buffer, READ_SIZE)) > 0)
    {
      buffer[oct - 1] = '\0';
      if (oct == 1)
	{
	  aff_prompt();
	  continue;
	}
      if (engine(data, buffer) == RET_FAILURE)
	return (RET_FAILURE);
      aff_prompt();
    }
  if (oct == RET_ERROR)
    fprintf(stderr, "read: %s\n", strerror(errno));
  return ((oct < 0) ? RET_FAILURE : RET_SUCCESS);
}
