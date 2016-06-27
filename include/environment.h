/*
** environment.h for t in /home/gaby/rendu/PSU/PSU_2015_minishell2/include/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon Mar 14 19:08:56 2016 Gabriel de Blois
** Last update Fri Jun 03 17:40:37 2016 moutou_m
*/

#include "typedef.h"

#ifndef	ENVIRONMENT_H_
# define ENVIRONMENT_H_

/*
** TYPEDEF_STRUCTS
*/

typedef	struct	s_env
{
  char		*info;
  t_env		*next;
}		t_env;

t_env	*preload_environment(char **env);

/*
** get PWD
*/

char		*get_pwd(void);
char		*get_env_pwd(void);
void		env_disp_list(t_env *list);
char		*env_transform_tag(char *str, const char *keyword);
t_env		*env_search_in_list(t_env *list, const char *keyword);
const char	*env_search_keyword(const char **env, const char *keyword);
t_env		*env_get_env(t_env *env, const char *keyword);

/*
** add new link to env lists
*/

t_env	*env_new_add(t_env *list, const char *data);
t_env	*env_add(t_env *list, t_env *tmp);

/*
** Free.. Delete
*/

t_env	*env_delete_by_keyword(t_env *env, const char *keyword);
t_env	*free_env_list(t_env *list);
t_env	*free_env(t_env *tmp);

#endif

/*
** ENVIRONMENT_H_
*/
