/*
** env_search_in_list.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/environment/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Tue May  3 18:17:04 2016 Gabriel de Blois
** Last update Tue May  3 18:19:07 2016 Gabriel de Blois
*/

#include <stdlib.h>
#include <string.h>
#include "shell.h"

/*
** Search for a list->info that matches with the keyword;
*/

t_env	*env_search_in_list(t_env *list, const char *keyword)
{
  while (list)
    {
      if (strncmp(list->info, keyword, strlen(keyword - 1)) == 0)
	return (list);
      list = list->next;
    }
  return (NULL);
}
