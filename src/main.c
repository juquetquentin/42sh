/*
** main.c for 42 in /home/gaby/rendu/PSU/PSU_2015_42sh/src/
**
** Made by Gabriel de Blois
** Login   <de-blo_g@epitech.eu>
**
** Started on  Mon May  2 11:12:25 2016 Gabriel de Blois
** Last update Sun Jun 05 16:17:31 2016 lacorr_f
*/

#include <stdlib.h>
#include <signal.h>
#include "shell.h"

void	sig_int()
{
  my_printf("\n");
  my_printf("42sh $>");
}

void	sig_quit()
{
  return;
}

int		main(const int ac, const char **av, const char **env)
{
  t_data	*data;
  int		code;

  (void)ac;
  (void)av;
  signal(SIGINT, sig_int);
  signal(SIGQUIT, sig_quit);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTERM, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGTTIN, SIG_IGN);
  if ((data = preload_shell(env)) == NULL)
    return (RET_FAILURE);
  code = launch_42(data);
  return (code);
}
