/*
** parent_side.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/exec/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Fri Jun  3 20:10:43 2016 Gabriel de Blois
** Last update Sun Jun 05 18:42:35 2016 moutou_m
*/

#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "shell.h"
#include "built_in.h"

/*
** check the return value of the last launched program and
** catch / display the right sentence if any segfaults or crash happened.
*/

static void	check_status(int status, t_data *data)
{
  if (WIFEXITED(status))
    {
      if (status == 65280 || status == 256)
	data->lastreturn = -1;
      else
	data->lastreturn = status;
    }
  else
    data->lastreturn = -1;
  if (WIFSIGNALED(status))
    {
      if (WCOREDUMP(status))
	fprintf(stderr, "Segmentation Fault (core dump)\n");
      else
	fprintf(stderr, "Killed by signal %d\n", WTERMSIG(status));
    }
  else if (WIFSTOPPED(status))
    fprintf(stderr, "Stopped by signal %d\n", WSTOPSIG(status));
}

/*
** close the non-null pipes in the parent side
*/

static void	exec_parent_close_pipe(int infd[2], int outfd[2])
{
  if (outfd[1] > 1)
    {
      if (close(outfd[1]) < 0)
	my_perror("close");
      outfd[1] = -1;
    }
  if (infd[0] > 1)
    {
      if (close(infd[0]) < 0)
	my_perror("close");
      infd[0] = -1;
    }
}

/*
** exec_ all the parent's duty while forking
*/

void	exec_parent_side(int infd[2], int outfd[2], pid_t pid, t_data *data)
{
  int	status;

  exec_parent_close_pipe(infd, outfd);
  if (waitpid(pid, &status, 0) != pid)
    fprintf(stderr, "waitpid: %s\n", strerror(errno));
  else
    check_status(status, data);
}
