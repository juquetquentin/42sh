/*
** mod_term.c for 42 in /home/flipper/rendu/42sh/PSU_2015_42sh/src/term/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Wed Jun  1 15:54:35 2016 Matthis Le Texier
** Last update Wed Jun  1 19:05:31 2016 Matthis Le Texier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <termios.h>
#include <stdbool.h>
#include <ncurses.h>
#include <term.h>

#define INIT_TERM (0)
#define RESTORE_TERM (1)

bool	buff_key_cmp(char *buff, int b0, int b1, int b2);
bool	check_key(char *buff);

void		my_putstr(char *str)
{
  while (str && *str)
    write(1, str++, 1);
}

void		my_tputs_key(int b0, int b1, int b3)
{
  int		i;

  tab[0] = b0;
  tab[1] = b1;
  tab[2] = b3;
  tab[3] = 0;
  i = -1;
  while (tab[++i])
    write(1, &tab[i], 1);
}

static bool	mod_term(int mod)
{
  static struct termios old_t;
  static struct termios new_t;
  char		*term_name;

  if (mod == INIT_TERM)
    {
      if ((term_name = getenv("TERM")) == NULL)
	return (fprintf(stderr, "error: unknown terminal\n"), false);
      if ((tgetent(NULL, term_name)) == ERR)
	return (fprintf(stderr, "%s\n", strerror(errno)), false);
      if (tcgetattr(0, &old_t) == -1 || tcgetattr(0, &new_t) == -1)
        return (fprintf(stderr, "%s\n", strerror(errno)), false);
      new_t.c_lflag &= ~ICANON;
      new_t.c_lflag &= ~ECHO;
      new_t.c_cc[VMIN] = 1;
      new_t.c_cc[VTIME] = 0;
      if ((tcsetattr(0, TCSANOW, &new_t)) == -1)
	return (fprintf(stderr, "%s\n", strerror(errno)), false);
    }
  if (mod == RESTORE_TERM)
    {
      if ((tcsetattr(0, TCSANOW, &old_t)) == -1)
	return (fprintf(stderr, "%s\n", strerror(errno)), false);
    }
  return (true);
}

void		my_tputs(char *str)
{
  if (str == NULL)
    {
      fprintf(stderr, "error: problem with tgetstr\n");
      mod_term(RESTORE_TERM);
      exit(EXIT_FAILURE);
    }
  while (str && *str)
    write(0, str++, 1);
}

void		reset_buff(char *buff, int size)
{
  int		i;

  i = -1;
  while (++i < size)
    buff[i] = 0;
}

int		main()
{
  char		buff[10];

  mod_term(INIT_TERM);
  reset_buff(buff, 10);
  my_putstr("42 $> ");
  my_tputs(tgetstr("cl", NULL));
  while (read(0, buff, 10) > 0)
    {
      // printf("buff: [%d] [%d] [%d]\n", buff[0], buff[1], buff[2]);
      if (!check_key(buff))
	write(1, &buff, 1);
      reset_buff(buff, 10);
    }
  mod_term(RESTORE_TERM);
}
