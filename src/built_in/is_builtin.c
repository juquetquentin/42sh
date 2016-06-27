/*
** is_builtin.c for 42 in /home/flipper/rendu/42sh/PSU_2015_42sh/src/built_in/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon May 23 09:52:14 2016 Matthis Le Texier
** Last update Fri Jun 03 17:42:16 2016 moutou_m
*/

#include <string.h>
#include <stdbool.h>
#include "shell.h"
#include "built_in.h"

static t_built_template	g_built_in[NB_BUILT_IN] =
{
  BUILT_IN(echo),
  BUILT_IN(exit),
  BUILT_IN(setenv),
  BUILT_IN(unsetenv),
  BUILT_IN(cd)
};

static char	*remove_path(char *str)
{
  char		*out;
  size_t	i;

  out = str;
  i = 0;
  while (*out != '\0')
    {
      out++;
      i++;
    }
  while (i > 0 && *(out - 1) != '/')
    {
      out--;
      i--;
    }
  return (out);
}

bool		is_builtin(char **cmd, t_data *data)
{
  size_t	i;
  char		*cmd_no_path;

  i = 0;
  cmd_no_path = remove_path(cmd[0]);
  while (i < NB_BUILT_IN)
    {
      if (strcmp(cmd_no_path, g_built_in[i].name) == 0)
	{
	  g_built_in[i].func((const char **)cmd, data);
	  return (true);
	}
      i++;
    }
  return (false);
}
