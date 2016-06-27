/*
** my_putstr.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:57:47 2016 Matthis Le Texier
** Last update Mon Apr  4 09:57:49 2016 Matthis Le Texier
*/

#include	"my.h"

int		my_putstr(const char *str)
{
  return (my_fputstr(STD_OUTPUT, str));
}
