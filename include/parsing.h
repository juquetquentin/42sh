/*
** parsing.h for 42 in /home/flipper/rendu/42sh/PSU_2015_42sh/include/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Tue May 31 11:09:17 2016 Matthis Le Texier
** Last update Sun Jun 05 18:13:55 2016 lacorr_f
*/

#ifndef	PARSING_H_
# define PARSING_H_

# include <stdio.h>
# include <stdbool.h>
# include <string.h>

typedef struct  s_token
{
  char  	*str;
  int   	id;
}               t_token;

typedef struct s_linked_list
{
  t_token               token;
  struct s_linked_list  *next;
}               t_linked_list;

typedef struct s_order
{
  char 			*instruction;
  int   		priority;
  int   		intree;
  struct s_order 	*next;
  struct s_order 	*prev;
}               t_order;

typedef struct  s_lexer
{
  int           id;
  t_linked_list *commande;
  t_linked_list *option;
  t_linked_list *operateur;
}               t_lexer;

typedef struct	s_tree
{
  t_order	*commande_ptr;
  struct s_tree	*left;
  struct s_tree	*right;
}		t_tree;

char	*conc_path(char *new, char *new_new, char *paths, char *commande);
char	**test_is_commande(char **paths, char *commande);
int	commande_detect(t_lexer *lex, char **tab, int i);
void	operateur_detect(char **tab, t_lexer *lex, int i);
void	option_detect(char **tab, t_lexer *lex, int i);
void	free_double_tab(char **tab);
void	free_list_linked_list(t_linked_list *stack);
void	free_lexer(t_lexer *lex);
int 	len_double_tab(char **tab);
void    *init_all(void *dest, int c, int size);
char    *str_conc(char *str_1, char *str_2);
int     is_empty_stack(t_linked_list *stack);
int     str_comp_env(char *seek, char *in);
char    *my_getenv(char **env, char *elem);
int	check_full_space(char *str);
int     nb_path(char *str);
t_lexer *malloc_lexer(void);
t_lexer *boucle_lexer(t_lexer *lex, char **paths_sep, char **tab, int i);
t_lexer	*lexer(char **tab, char **env);
int	len_list(t_linked_list **stack);
void	push_commande(t_order **commande, char *str, int prio);
void	print_list_order(t_order **commande, int toto);
char	*pop_commande(t_linked_list **stack);
t_order *create_list_order(t_lexer *lex);
int	search_opp(t_order *commande);
void	print_command_list(t_order *commande);
void	put_prev(t_order *commande);
t_tree	*parsing(char *str, t_data *data);
int     len_stack(t_linked_list **stack);
char    *pop_it(t_linked_list **stack);
void	print_double_tab(char **tab);
void	print_linked_list(t_linked_list **stack, char *name);
void	print_all_stack(t_lexer *lex);
void    push_it(t_linked_list **stack, t_token token);
int     sep_nb_word(char *str, char sep);
char    **sep_malloc_double_tab(char **tab, int nbword, int len);
char    **sep_fill_tab(char **tab, char *line, int nbword, char sep);
char    **sep_str_to_wordtab(char *line, char sep);
void	tree_display(t_tree *root);
t_tree	*create_tree(t_order *commande, t_order *last_order);
void	tree_display(t_tree *root);
t_tree	*create_tree(t_order *commande, t_order *last_order);
void	free_tree(t_tree **tree);
void	free_parsing(char **tab, char **tab_env, t_lexer *lex);
t_lexer *malloc_lexer(void);
t_lexer *boucle_lexer(t_lexer *lex, char **paths_sep, char **tab, int i);
t_lexer	*lexer(char **tab, char **env);
void	push_commande(t_order **commande, char *str, int prio);
char	*pop_commande(t_linked_list **stack);
t_order *create_list_order(t_lexer *lex);
void 	aff_list(t_linked_list **list);
char    **list_env_to_tab(t_env **env);
int     nb_path(char *str);
int	len_list(t_linked_list **stack);
void 	aff_list(t_linked_list **list);
int	search_opp(t_order *commande);
void	print_command_list(t_order *commande);
char    *my_getenv(char **env, char *elem);
int     str_comp_env(char *seek, char *in);
void	print_list_order(t_order **commande, int toto);
void	put_prev(t_order *commande);

#endif
