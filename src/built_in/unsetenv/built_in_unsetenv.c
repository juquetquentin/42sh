/*
** built_in_unsetenv.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/built_in/unsetenv
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Tue May 31 10:17:26 2016 moutou_m
** Last update Sun Jun 05 14:17:36 2016 moutou_m
*/

#include <stdio.h>
#include <stdbool.h>
#include "shell.h"
#include "environment.h"
#include "built_in.h"

bool		built_in_unsetenv(const char **cmd, t_data *data)
{
  size_t	cmd_size;

  cmd_size = built_in_tab_len(cmd);
  if (cmd_size == 1)
    {
      if (data->built_in_disp == true)
	fprintf(stderr, "unsetenv: Too few arguments.\n");
      return (false);
    }
  while ((cmd_size - 1) > 0)
    {
      data->env = env_delete_by_keyword(data->env, cmd[cmd_size - 1]);
      cmd_size = cmd_size - 1;
    }
  return (true);
}
