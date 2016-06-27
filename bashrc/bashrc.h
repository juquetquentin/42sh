/*
** bashrc.h for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Tue May 31 11:02:33 2016 juquet_q
** Last update Sat Jun 04 18:31:12 2016 juquet_q
*/

#pragma once

#define ALIAS (0)
#define EXPORT (1)
#define ALIAS_LOOP (42)
#define ALIAS_TYPE ("alias ")
#define ALIAS_LEN (6)
#define EXPORT_LEN (7)
#define EXPORT_TYPE ("export ")
#define BAD_TYPE (-1)
#define PATH_RC ("./.42rc")

typedef struct		s_bashrc
{
  char			*enter;
  char			*retour;
  int			type;
  struct s_bashrc	*next;
  struct s_bashrc	*prev;
}			t_bashrc;

char		*my_str_intro(char *enter, char *find, char *replace);
int		find_cmd(char *enter, char *find);
char		*my_memset(char	*ptr, int set, int len);
int		my_strlen(char *s);
t_bashrc	*get_bash_rc(char *path, t_bashrc *bashrc);
void		add_env(char **env, t_bashrc *bashrc);
void		add_alias(t_bashrc *bashrc);
int		get_type(char *str);
int		my_strcmp(const char *s1, const char *s2);
char		*get_enter(char *buff, t_bashrc *bashrc);
int		my_strlen_alias(char *str);
char		*get_retour(char *str);
char		*get_next_line(const int fd);
t_bashrc	*add_bashrc(t_bashrc *bashrc);
char		*alias(t_bashrc *bashrc, char *cmd);
int		check_alias(t_bashrc *new, t_bashrc *bashrc);
t_bashrc	*new_alias(t_bashrc *bashrc, char *cmd);
int		show_alias(char *cmd, t_bashrc *bashrc);
