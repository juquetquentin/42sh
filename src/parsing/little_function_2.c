/*
** little_function_2.c for little 2 in /home/lacorr_f/rendu/PSU_2015_42sh/src/parsing
**
** Made by lacorr_f
** Login   <lacorr_f@epitech.net>
**
** Started on  Tue May 31 16:58:42 2016 lacorr_f
** Last update Sat Jun 04 22:20:48 2016 lacorr_f
*/

#include "shell.h"

int     str_comp_env(char *seek, char *in)
{
  int   i;
  int   nb_seek;
  int   nb_found;

  i = 0;
  nb_found = 0;
  nb_seek = strlen(seek);
  while (in[i] != 0 && in[i] != '=')
    {
      if (in[i] == seek[i])
        nb_found++;
      i++;
    }
  if (nb_found == nb_seek)
    return (1);
  else
    return (0);
}

char    *my_getenv(char **env, char *elem)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (env[i] != 0 && str_comp_env(elem, env[i]) != 1)
    i++;
  if (env[i] == 0)
    return (NULL);
  while (env[i][j] != '=' && env[i][j] != 0)
    j++;
  j++;
  return (&env[i][j]);
}

void		print_list_order(t_order **commande, int toto)
{
  t_order 	*tamp;

  tamp = *commande;
  while (tamp != NULL)
    {
      if (tamp->instruction != NULL)
	{
	  printf("commande : %s %d\n", tamp->instruction, toto);
	}
      tamp = tamp->next;
    }
}

void		put_prev(t_order *commande)
{
  t_order	*prev;

  prev = NULL;
  while (commande)
    {
      commande->prev = prev;
      prev = commande;
      commande = commande->next;
    }
}
