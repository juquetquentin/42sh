/*
** exec.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/exec/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Tue May 31 10:41:28 2016 Gabriel de Blois
** Last update Tue May 31 18:32:55 2016 Gabriel de Blois
*/

#include "shell.h"
#include "parsing.h"

static	t_exec_ptr	g_exec_ptr_tab[] =
{
  &exec_order,
  &exec_pipe,
  &exec_and,
  &exec_or,
  &exec_semi_colon
};

static	int	exec_get_order_type(t_tree *node)
{
  if (node->commande_ptr->priority < 2)
    return (node->commande_ptr->priority);
  else if (node->commande_ptr->priority == 2)
    return ((node->commande_ptr->instruction[0] == '&') ? 2 : 3);
  else
    return (4);
  return (0);
}

bool	launch_exec(t_tree *root, t_data *data, int infd[2], int outfd[2])
{
  if (root)
    return (g_exec_ptr_tab[exec_get_order_type(root)](root, data, infd, outfd));
  return (true);
}
