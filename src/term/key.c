/*
** key.c for 42 in /home/flipper/rendu/42sh/PSU_2015_42sh/src/term/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Wed Jun  1 16:07:56 2016 Matthis Le Texier
** Last update Wed Jun  1 19:04:12 2016 Matthis Le Texier
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <termios.h>
#include <stdbool.h>
#include <ncurses.h>
#include <term.h>

void		my_tputs(char *str);
void		my_tputs_key(int b0, int b1, int b3);

bool	buff_key_cmp(char *buff, int b0, int b1, int b2)
{
  if (buff[0] == b0 && buff[1] == b1 && buff[2] == b2)
    return (true);
  return (false);
}

bool	check_key(char *buff)
{
  if (buff_key_cmp(buff, 27, 91, 65))
    return (printf("UP ARROW\n"), true);
  if (buff_key_cmp(buff, 27, 91, 66))
    return (printf("DOWN ARROW\n"), true);
  if (buff_key_cmp(buff, 127, 0, 0))
    return (my_tputs(tgetstr("le", NULL)), my_tputs(tgetstr("dc", NULL)), true);
  if (buff_key_cmp(buff, 27, 91, 68))
    return (my_tputs(tgetstr("le", NULL)), true);
  if (buff_key_cmp(buff, 27, 91, 67))
    return (my_tputs_key(27, 91, 67), true);
  return (false);
}
