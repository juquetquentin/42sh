/*
** main.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Tue May 31 11:00:04 2016 juquet_q
** Last update Sat Jun 04 18:41:51 2016 juquet_q
*/

/*
** fonction a lancer dès le début du shell (bashrc_init)
** ajout des alias et export présents dans .42rc
** built-in alias et export à ajouter en cours d'execution du shell
*/

#include <stdio.h>
#include <stdlib.h>
#include "bashrc.h"

int	main(int ac, char **av, char **ae)
{
  t_bashrc	*bashrc;

  (void)ac;
  (void)av;
  if ((bashrc = malloc(sizeof(t_bashrc))) == NULL)
    return (EXIT_FAILURE);
  bashrc->type = BAD_TYPE;
  bashrc->enter = "";
  bashrc->retour = "";
  bashrc->next = NULL;
  bashrc->prev = NULL;
  if ((bashrc = get_bash_rc(PATH_RC, bashrc)) == NULL)
    return (EXIT_FAILURE);
  show_alias("alias", bashrc);
  write(1, "\n", 1);
  printf("return = %s\n", alias(bashrc, "ls"));
  //add_env(ae, bashrc);
  return (0);
}
