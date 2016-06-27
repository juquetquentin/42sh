/*
** alias.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Fri Jun 03 15:18:35 2016 juquet_q
** Last update Sat Jun 04 19:05:45 2016 juquet_q
*/

#include <stdlib.h>
#include "bashrc.h"

int		show_alias(char *cmd, t_bashrc *bashrc)
{
  int	len;

  if (my_strlen(cmd) <= (my_strlen(ALIAS_TYPE)) &&
     my_strcmp(cmd, ALIAS_TYPE) == 1)
    {
      while (bashrc->next != NULL)
	{
	  if (bashrc->type == ALIAS)
	    {
	      len = (8 - my_strlen(bashrc->enter));
	      len = (len <= 0) ? 1 : len;
	      write(1, bashrc->enter, my_strlen(bashrc->enter));
	      write(1, "        ", len);
	      write(1, bashrc->retour, my_strlen(bashrc->retour));
	      write(1, "\n", 1);
	    }
	  bashrc = bashrc->next;
	}
      return (0);
    }
  return (1);
}

t_bashrc	*new_alias(t_bashrc *bashrc, char *cmd)
{
  t_bashrc	*add;

  if (show_alias(cmd, bashrc) == 0 || (add = add_bashrc(bashrc)) == NULL)
    return (bashrc);
  else if ((add->type = get_type(cmd)) == BAD_TYPE ||
	   (add->enter = get_enter(cmd, add)) == NULL)
    {
      free(add);
      bashrc->next = NULL;
    }
  else if ((add->retour = get_retour(cmd)) == NULL)
    {
      free(bashrc->enter);
      free(add);
      bashrc->next = NULL;
    }
  else if (check_alias(add, bashrc) == EXIT_FAILURE)
    {
      free(bashrc->enter);
      free(bashrc->retour);
      free(add);
      bashrc->next = NULL;
    }
  while (bashrc->prev != NULL)
    bashrc = bashrc->prev;
  return (bashrc);
}

int	check_alias(t_bashrc *new, t_bashrc *bashrc)
{
  while (bashrc->next != NULL)
    {
      if (my_strcmp(new->enter, bashrc->retour) == 1 ||
	  my_strcmp(new->retour, bashrc->enter) == 1)
	return (EXIT_FAILURE);
      bashrc = bashrc->next;
    }
  return (EXIT_SUCCESS);
}

char	*alias(t_bashrc *bashrc, char *cmd)
{
  char	*retour;

  while ((retour = my_str_intro(cmd, bashrc->enter, bashrc->retour)) == NULL &&
	 bashrc->next != NULL)
    bashrc = bashrc->next;
  if (retour == NULL || bashrc->next == NULL)
    return (cmd);
  return (retour);
}
