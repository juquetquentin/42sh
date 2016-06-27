/*
** built_in_exit.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/built_in/exit
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Tue May 31 15:57:19 2016 moutou_m
** Last update Wed Jun 08 09:47:58 2016 moutou_m
*/

#include <stdbool.h>
#include <stdlib.h>
#include "shell.h"
#include "my.h"
#include "built_in.h"

static void	built_in_exit_error_number(t_data *data)
{
  if (data->built_in_disp == true)
    fprintf(stderr, "exit: Badly formed number.\n");
}

static void	built_in_exit_error_syntax(t_data *data)
{
  if (data->built_in_disp == true)
    fprintf(stderr, "exit: Expression Syntax.\n");
}

bool		built_in_exit(const char **cmd, t_data *data)
{
  size_t	cmd_len;
  int		nb_out;

  cmd_len = built_in_tab_len(cmd);
  if (cmd_len == 1)
    nb_out = data->lastreturn;
  else if (cmd_len == 2)
    {
      if (is_charnumber(cmd[1][0]) == true && is_number(cmd[1]) == false)
	return (built_in_exit_error_number(data), false);
      else if (is_number(cmd[1]) == false)
	return (built_in_exit_error_syntax(data), false);
      else
	nb_out = my_getnbr(cmd[1]);
    }
  else
    return (built_in_exit_error_syntax(data), false);
  if (data->built_in_disp == false)
    printf("exit\n");
  exit(nb_out);
  return (true);
}
