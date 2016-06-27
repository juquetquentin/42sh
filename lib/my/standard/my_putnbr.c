/*
** my_putnbr.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:57:41 2016 Matthis Le Texier
** Last update Mon Apr  4 09:57:43 2016 Matthis Le Texier
*/

#include	"my.h"

int		my_putnbr(int nbr)
{
  return (my_fputnbr_base(STD_OUTPUT, nbr, BASE_DEC));
}
