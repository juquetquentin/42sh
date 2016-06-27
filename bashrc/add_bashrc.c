/*
** add_bashrc.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Fri Jun 03 14:25:40 2016 juquet_q
** Last update Sat Jun 04 18:08:09 2016 juquet_q
*/

#include <stdlib.h>
#include "bashrc.h"

t_bashrc	*add_bashrc(t_bashrc *bashrc)
{
  t_bashrc	*new;

  if ((new = malloc(sizeof(t_bashrc))) == NULL)
    return (NULL);
  new->enter = "";
  new->retour = "";
  new->next = NULL;
  new->type = BAD_TYPE;
  while (bashrc->next != NULL)
    bashrc = bashrc->next;
  new->prev = bashrc;
  bashrc->next = new;
  return (new);
}
