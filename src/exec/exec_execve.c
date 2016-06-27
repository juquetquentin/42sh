/*
** exec_execve.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/exec/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Thu Jun  2 17:16:42 2016 Gabriel de Blois
** Last update Sun Jun 05 18:47:11 2016 moutou_m
*/

#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "shell.h"
#include "built_in.h"

/*
** set approrpiately the stdin and stdout with infd / outfd if
** one of them are non null (null mean default value 0 / 1)
*/

static void	exec_redir_to_pipes_in_child(int infd[2], int outfd[2])
{
  if (infd[0] > 1)
    {
      if (dup2(infd[0], 0) < 0)
	my_perror("dup2");
      if (infd[1] > 1)
	{
	  if (close(infd[1]) < 0)
	    my_perror("close");
	  infd[1] = -1;
	}
    }
  if (outfd[1] != 1)
    {
      if (dup2(outfd[1], 1) < 0)
	my_perror("dup2");
      if (outfd[0] > 1)
	{
	  if (close(outfd[0]) < 0)
	    my_perror("close");
	  outfd[0] = -1;
	}
    }
}

/*
** return (true) if it worked
** launch any programs precedently parsed: it has nothing to do
** with the tree
*/

static bool	exec_execve(char **args, char **env, t_data *data)
{
  int	filefd;

  (void)data;
  if ((filefd = check_redir_right(args)) != -1)
      dup2(filefd, 1);
  else if ((filefd = check_redir_left(args)) != -1)
      dup2(filefd, 0);
  if (is_builtin(args, data) == true)
    exit(EXIT_SUCCESS);
  else if (execve(args[0], args, env) == RET_ERROR)
    {
      my_perror(args[0]);
      exit(EXIT_FAILURE);
    }
  if (filefd > 1)
    close(filefd);
  return (true);
}

/*
** launch the fork() function and set approrpiately stdin stdout
** wait for the child to exit and catch the ending status;
*/

void	exec_fork(t_data *data, int infd[2], int outfd[2])
{
  setpgid(getpid(), getpid());
  data->built_in_disp = true;
  exec_redir_to_pipes_in_child(infd, outfd);
}

bool	exec_order(t_tree *node, t_data *data, int infd[2], int outfd[2])
{
  pid_t	pid;
  char	**args;
  char  **env;

  data->built_in_disp = false;
  env = list_env_to_tab(&data->env);
  args = my_str_to_wordtab(node->commande_ptr->instruction);
  exec_get_path(data->env, &args[0]);
  is_builtin(args, data);
  if ((pid = fork()) < 0)
    my_perror("fork");
  else if (pid == 0)
    {
      exec_fork(data, infd, outfd);
      exec_execve(args, env, data);
    }
  else
    {
      tcsetpgrp(0, pid);
      exec_parent_side(infd, outfd, pid, data);
      tcsetpgrp(0, getpid());
    }
  free_double_tab(args);
  free_double_tab(env);
  return (true);
}
