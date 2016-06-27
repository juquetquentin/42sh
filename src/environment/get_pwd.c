/*
** get_pwd.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/built_in/cd/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 15:37:47 2016 Gabriel de Blois
** Last update Mon May  2 15:39:00 2016 Gabriel de Blois
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "shell.h"

char	*get_env_pwd(void)
{
  char	buf[1024];

  strcpy(buf, "PWD=");
  if (getcwd(&buf[4], sizeof(buf) - 4) == NULL)
    return (NULL);
  return (strdup(buf));
}

char	*get_pwd(void)
{
  char	buf[1024];

  if (getcwd(buf, sizeof(buf)) == NULL)
    return (NULL);
  return (strdup(buf));
}
