/*
** tree.c for t in /home/gaby/rendu/test42/gaby_42/parceur_42/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May 23 10:27:11 2016 Gabriel de Blois
** Last update Sun Jun 05 18:12:32 2016 lacorr_f
*/

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/*
** display recursively a binary tree from the top
*/

void	tree_display(t_tree *root)
{
  if (root == NULL)
    return ;
  printf("---TREE---\n");
  printf("%s\n", root->commande_ptr->instruction);
  if (root->left)
    {
      printf("left\n");
      tree_display(root->left);
    }
  if (root->right)
    {
      printf("right\n");
      tree_display(root->right);
    }
  printf("depop\n");
}

/*
** pop_node créé un node t_tree
** data = expression (ls / cat /echo / etc)
** val = priority; ptr = node correspondant (t_order)
*/

static t_tree	*tree_pop_node(t_order *ptr)
{
  t_tree	*node;

  if ((node = malloc(sizeof(*node))) == NULL)
  return (NULL);
  node->left = NULL;
  node->right = NULL;
  node->commande_ptr = ptr;
  return (node);
}

/*
** return the first node t_order with the highest priority
** take t_order linked list in parameter
*/

static t_order	*get_bigger(t_order *list)
{
  t_order	*bigger;

  if (!list)
    return (NULL);
  bigger = list;
  while (list)
    {
      if (list->priority > bigger->priority)
	bigger = list;
      list = list->next;
    }
  if (bigger->prev)
    bigger->prev->next = NULL;
  return (bigger);
}

/*
** creates recursively a binary tree by the top..
** takes a t_order linked list \
** and a pointer to the last node created (NULL by default)
** returns a pointer to the top of the tree
*/

t_tree		*create_tree(t_order *commande, t_order *last_order)
{
  t_order	*bigger;
  t_tree	*current;
      static int	i = 0;

      if (last_order == NULL)
	i = 0;
      else if (i++ > 500)
	return (NULL);
  if (!commande)
    return (NULL);
  if ((bigger = get_bigger(commande)) == NULL || bigger == last_order)
    return (NULL);
  current = tree_pop_node(bigger);
  current->left = create_tree(commande, bigger);
  current->right = create_tree(bigger->next, bigger);
  return (current);
}
