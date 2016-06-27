/*
** exec.h for 42 in /home/flipper/rendu/42sh/PSU_2015_42sh/include/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Tue May 31 18:13:10 2016 Matthis Le Texier
** Last update Sun Jun  5 17:35:31 2016 Gabriel de Blois
*/

#ifndef EXEC_H_
# define  EXEC_H_

# include "parsing.h"

# define STR_WORDTAB_VALUE 	(256)
# define SEPARATOR_CHAR 	(' ')

typedef bool	(*t_exec_ptr)(t_tree *root,
		 t_data *data,
		 int infd[2],
		 int outfd[2]);

bool	launch_exec(t_tree *root, t_data *data, int infd[2], int outfd[2]);
bool	exec_order(t_tree *node, t_data *data, int infd[2], int outfd[2]);
bool	exec_pipe(t_tree *node, t_data *data, int infd[2], int outfd[2]);
bool	exec_or(t_tree *node, t_data *data, int infd[2], int outfd[2]);
bool	exec_and(t_tree *node, t_data *data, int infd[2], int outfd[2]);
bool	exec_semi_colon(t_tree *node, t_data *data, int infd[2], int outfd[2]);
void	special_str_to_wordtab(char tab[STR_WORDTAB_VALUE][STR_WORDTAB_VALUE],
			       const char *str,
			       int incr);
void	exec_get_path(const t_env *env, char **cmd);
int 	check_redir_right(char **args);
int 	check_redir_left(char **args);
void	exec_parent_side(int infd[2], int outfd[2], pid_t pid, t_data *data);

#endif
