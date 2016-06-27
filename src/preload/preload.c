/*
** preload.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/preload/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 11:40:08 2016 Gabriel de Blois
** Last update Sun Jun  5 17:38:03 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include "shell.h"

static t_pwd	*load_pwd_list(const char **env)
{
  const char	*pwd;
  t_pwd	*list;

  list = NULL;
  if ((pwd = env_search_keyword(env, "OLDPWD")) != NULL)
    list = env_new_add(list, pwd);
  if ((pwd = env_search_keyword(env, "PWD")) != NULL)
    list = env_new_add(list, pwd);
  else
    list = env_new_add(list, get_env_pwd());
  return (list);
}

static t_env	*load_env(const char **env)
{
  int	i;
  t_env	*list;

  i = -1;
  list = NULL;
  while (env[++i])
    list = env_new_add(list, env[i]);
  return (list);
}

t_data	*preload_shell(const char **env)
{
  t_data	*data;

  if ((data = malloc(sizeof(*data))) == NULL)
    return (NULL);
  data->lastreturn = 0;
  data->plist = load_pwd_list(env);
  data->env = load_env(env);
  data->run = 1;
  return (data);
}
