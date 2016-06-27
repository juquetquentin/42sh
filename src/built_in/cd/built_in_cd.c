/*
** built_in_cd.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/built_in/cd
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Fri Jun 03 10:05:03 2016 moutou_m
** Last update Sun Jun 05 15:31:40 2016 moutou_m
*/

#include <stdbool.h>
#include <errno.h>
#include "shell.h"
#include "built_in.h"

void	built_in_cd_home(int *out, t_env *env)
{
  t_env	*tmp;

  if ((tmp = env_get_env(env, "HOME")) == NULL)
    *out = chdir("/home");
  else
    *out = chdir(&((tmp->info)[5]));
}

void	built_in_cd_multi_args(int *out, const char *cmd, t_data *data)
{
  t_env	*tmp;

  if (strcmp(cmd, "-") == 0)
    {
      if ((tmp = env_get_env(data->env, "OLDPWD")) == NULL)
	built_in_cd_home(out, data->env);
      else
	*out = chdir(&((tmp->info)[7]));
    }
  else
    *out = chdir(cmd);
}

bool	built_in_cd(const char **cmd, t_data *data)
{
  size_t	cmd_len;
  int		out;
  char		*current_pwd;

  current_pwd = getcwd(NULL, 0);
  cmd_len = built_in_tab_len(cmd);
  if (cmd_len == 1)
    built_in_cd_home(&out, data->env);
  else if (cmd_len == 2)
    built_in_cd_multi_args(&out, cmd[1], data);
  else
    {
      if (data->built_in_disp == false)
	fprintf(stderr, "cd: Too many arguments.\n");
      return (false);
    }
  if (out != 0 && data->built_in_disp == false)
    {
      fprintf(stderr, "%s: %s\n", (cmd[1] != NULL) ? cmd[1] : "cd",
	      strerror(errno));
    }
  else
    change_pwd(data, current_pwd);
  return (true);
}
