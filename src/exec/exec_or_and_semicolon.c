/*
** exec_or_and_semicolon.c for t in /home/gaby/rendu/PSU/PSU_2015_42sh/src/exec/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Thu Jun  2 17:14:39 2016 Gabriel de Blois
** Last update Sun Jun  5 17:40:22 2016 Gabriel de Blois
*/

#include <stdbool.h>
#include "shell.h"

/*
** if the left node (first execution) is (true) then it doesn't launch
** the other, if (false) it executes the right node;
*/

bool	exec_or(t_tree *node, t_data *data, int infd[2], int outfd[2])
{
  (void)outfd;
  (void)infd;
  launch_exec(node->left, data, infd, outfd);
  if (data->lastreturn >= 0)
    return (true);
  launch_exec(node->right, data, infd, outfd);
  if (data->lastreturn >= 0)
    return (true);
  return (false);
}

/*
** if the left node (first execution) it (false) it doesn't launch_exec
** the other, otherwise it does
*/

bool	exec_and(t_tree *node, t_data *data, int infd[2], int outfd[2])
{
  (void)outfd;
  (void)infd;
  launch_exec(node->left, data, infd, outfd);
  if (data->lastreturn < 0)
    return (false);
  launch_exec(node->right, data, infd, outfd);
  if (data->lastreturn < 0)
    return (false);
  return (true);
}

/*
** launch_exec both right and left node
*/

bool	exec_semi_colon(t_tree *node, t_data *data, int infd[2], int outfd[2])
{
  (void)outfd;
  (void)infd;
  if (node->left)
    launch_exec(node->left, data, infd, outfd);
  if (node->right)
    launch_exec(node->right, data, infd, outfd);
  return (true);
}
