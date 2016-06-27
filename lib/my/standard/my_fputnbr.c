/*
** my_fputnbr.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:56:44 2016 Matthis Le Texier
** Last update Mon Apr  4 09:56:45 2016 Matthis Le Texier
*/

#include	"my.h"

int		my_fputnbr(const int fd, int nbr)
{
  return (my_fputnbr_base(fd, nbr, BASE_DEC));
}
