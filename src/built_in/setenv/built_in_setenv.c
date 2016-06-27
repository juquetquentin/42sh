/*
** built_in_setenv.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/built_in/unsetenv
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Tue May 31 10:59:50 2016 moutou_m
** Last update Sun Jun 05 18:31:17 2016 moutou_m
*/

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "shell.h"
#include "environment.h"
#include "built_in.h"

static char	*built_in_setenv_format(const char *keyword, const char *info)
{
  size_t	keyword_len;
  size_t	info_len;
  char		*out;

  keyword_len = (keyword != NULL) ? strlen(keyword) : 0;
  info_len = (info != NULL) ? strlen(info) : 0;
  if ((out = malloc((keyword_len + info_len + 2) * sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  if (keyword != NULL)
    strcpy(out, keyword);
  strcpy(&out[keyword_len], "=");
  if (info != NULL)
    strcpy(&out[keyword_len + 1], info);
  return (out);
}

static void	built_in_setenv_agree(const char **cmd, t_data *data)
{
  t_env		*tmp;

  if ((tmp = env_get_env(data->env, cmd[1])) == NULL)
    {
      data->env = env_new_add(data->env,
				    built_in_setenv_format(cmd[1], cmd[2]));
    }
  else
    {
      tmp->info = built_in_setenv_format(cmd[1], cmd[2]);
    }
}

static void	built_in_setenv_error(t_data *data)
{
  if (data->built_in_disp == true)
    fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
}

bool		built_in_setenv(const char **cmd, t_data *data)
{
  size_t	cmd_size;

  cmd_size = built_in_tab_len(cmd);
  if (cmd_size == 1)
    {
      if (data->built_in_disp == true)
	env_disp_list(data->env);
    }
  else if (cmd_size > 3)
    {
      if (data->built_in_disp == true)
	fprintf(stderr, "setenv: Too many arguments.\n");
      return (false);
    }
  else
    {
      if (is_charalpha(cmd[1][0]) == false)
	return (built_in_setenv_error(data), false);
      built_in_setenv_agree(cmd, data);
    }
  return (true);
}
