/*
** my_fputnbr_base.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:56:37 2016 Matthis Le Texier
** Last update Mon Apr  4 09:56:38 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

int		my_fputnbr_base(const int fd, int nbr, const char *base)
{
  int		strlen;
  int		divi;
  int		baselen;

  if (base == NULL)
    return (RET_ERROR);
  baselen = my_strlen(base);
  strlen = 0;
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
      strlen++;
    }
  divi = 1;
  while ((nbr / divi) >= baselen)
    divi *= baselen;
  while (divi)
    {
      my_fputchar(fd, base[(nbr / divi) % baselen]);
      divi /= baselen;
      strlen++;
    }
  return (strlen);
}
