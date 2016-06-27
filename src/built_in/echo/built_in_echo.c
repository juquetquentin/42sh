/*
** built_in_echo.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/built_in/echo
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Tue May 31 13:44:04 2016 moutou_m
** Last update Sun Jun 05 18:26:54 2016 moutou_m
*/

#include <string.h>
#include <stdbool.h>
#include "shell.h"

void		built_in_echo_n(const char **cmd, t_data *data)
{
  size_t	cmd_incr;

  cmd_incr = 2;
  while (cmd[cmd_incr] != NULL)
    {
      if (data->built_in_disp == true)
        printf("%s", cmd[cmd_incr]);
      cmd_incr = cmd_incr + 1;
      if (cmd[cmd_incr] != NULL && data->built_in_disp == true)
	printf(" ");
    }
}

bool		built_in_echo(const char **cmd, t_data *data)
{
  size_t	cmd_incr;

  (void)data;
  if (cmd[1] != NULL && strcmp(cmd[1], "-n") == 0)
    {
      built_in_echo_n(cmd, data);
      return (true);
    }
  cmd_incr = 1;
  while (cmd[cmd_incr] != NULL)
    {
      if (data->built_in_disp == true)
	printf("%s", cmd[cmd_incr]);
      cmd_incr = cmd_incr + 1;
      if (cmd[cmd_incr] != NULL && data->built_in_disp == true)
	printf(" ");
    }
  if (data->built_in_disp == true)
    printf("\n");
  return (true);
}
