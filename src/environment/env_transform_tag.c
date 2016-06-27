/*
** env_transform_tag.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Tue May  3 18:56:40 2016 Gabriel de Blois
** Last update Tue May  3 19:02:34 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"

/*
** do not EVER pass a null pointer to this function
** this function is not tested yet
**
** it replaces the tags of environment variables by another and returns it
** all cases should work
*/

char	*env_transform_tag(char *str, const char *keyword)
{
  char	buf[strlen(str) + strlen(keyword) + 3];
  int	i;

  if (strncmp(str, keyword, strlen(keyword) - 1) == 0)
    return (str);
  i = -1;
  strcpy(buf, keyword);
  while (str[++i] && str[i] != '=');
  if (str[i] == '=')
    return (strcat(buf, &str[i + 1]), free(str), strdup(buf));
  return (strcat(buf, str), free(str), strdup(buf));
}
