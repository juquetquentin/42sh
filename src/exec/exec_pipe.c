/*
** handle_pipe.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/exec/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Thu Jun  2 17:15:31 2016 Gabriel de Blois
** Last update Sun Jun 05 18:10:38 2016 lacorr_f
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "shell.h"

static int	handle_pipe(int pipefd[2])
{
  if (pipe(pipefd) < 0)
    return (fprintf(stderr, "error: cannot create pipes\n"),
	    exit(EXIT_FAILURE), -1);
    return (0);
}

bool	exec_pipe(t_tree *node, t_data *data, int infd[2], int outfd[2])
{
  if (outfd[1] != 1)
    infd = memcpy(infd, outfd, sizeof(int) * 2);
  handle_pipe(outfd);
  launch_exec(node->left, data, infd, outfd);
  if (node->right)
    {
      infd[0] = 0;
      infd[1] = 1;
    }
  launch_exec(node->right, data, outfd, infd);
  return (true);
}
