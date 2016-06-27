/*
** built_in_cd_change_pwd.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/toto/PSU_2015_42sh/src/built_in/cd
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Sat Jun 04 20:27:13 2016 moutou_m
** Last update Sat Jun 04 20:36:43 2016 moutou_m
*/

#include <stdlib.h>
#include "shell.h"
#include "built_in.h"

static char	**init_tab(char *a, char *b, char *c)
{
  char		**tab;

  if (a == NULL || b == NULL || c == NULL)
    exit(EXIT_FAILURE);
  if ((tab = malloc(4 * sizeof(char *))) == NULL)
    exit(EXIT_FAILURE);
  tab[0] = a;
  tab[1] = b;
  tab[2] = c;
  tab[3] = NULL;
  return (tab);
}

void	change_pwd(t_data *data, char *pwd_prev)
{
  char	*current_pwd;
  char	**tab;

  tab = init_tab(strdup("setenv"), strdup("OLDPWD"), pwd_prev);
  built_in_setenv((const char **)tab, data);
  free(tab[0]);
  free(tab[1]);
  free(tab[2]);
  free(tab);
  current_pwd = getcwd(NULL, 0);
  tab = init_tab(strdup("setenv"), strdup("PWD"), current_pwd);
  built_in_setenv((const char **)tab, data);
  free(tab[0]);
  free(tab[1]);
  free(tab[2]);
  free(tab);
}
