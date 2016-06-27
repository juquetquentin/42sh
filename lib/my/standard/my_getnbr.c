/*
** my_getnbr.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:57:07 2016 Matthis Le Texier
** Last update Mon Apr  4 09:57:09 2016 Matthis Le Texier
*/

#include	"my.h"

int		my_getnbr(const char *str)
{
  return (my_getnbr_base(str, BASE_DEC));
}
