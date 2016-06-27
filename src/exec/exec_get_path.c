/*
** exec_get_path.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/toto/PSU_2015_42sh/src/exec
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Thu Jun 02 13:10:36 2016 moutou_m
** Last update Sun Jun 05 18:39:40 2016 moutou_m
*/

#include <string.h>
#include "shell.h"

static void	replace_char_by_char(char *str, const char init, const char new)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == init)
	str[i] = new;
      i = i + 1;
    }
}

static char	**get_env_path_tab(const t_env *env)
{
  t_env		*tmp;
  char		*path_str;
  char		**out;

  tmp = (t_env *)env;
  out = NULL;
  while (tmp != NULL)
    {
      if (strncmp(tmp->info, "PATH=", strlen("PATH=")) == 0)
	{
	  if (tmp->info && (path_str = strdup(tmp->info)) != NULL)
	    {
	      while (*(path_str++) != '\0')
		{
		  if (*path_str == '=' && path_str++)
		    break;
		}
	      replace_char_by_char(path_str, ':', ' ');
	      out = my_str_to_wordtab(path_str);
	    }
	  break;
	}
      tmp = tmp->next;
    }
  return (out);
}

void		exec_get_path(const t_env *env, char **cmd)
{
  char		**env_tab;
  size_t	i;
  char		tmp[1024];

  i = 0;
  env_tab = get_env_path_tab(env);
  while (env_tab != NULL && env_tab[i] != NULL)
    {
      strcpy(tmp, env_tab[i]);
      strcat(tmp, "/");
      strcat(tmp, *cmd);
      if (access(tmp, F_OK) == 0)
	{
	  free(*cmd);
	  *cmd = strdup(tmp);
	  return ;
	}
      i++;
    }
}
