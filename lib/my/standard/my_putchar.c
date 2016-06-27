/*
** my_putchar.c for libmy in /home/flipper/rendu/template/lib/my/standard/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:57:24 2016 Matthis Le Texier
** Last update Mon Apr  4 09:57:25 2016 Matthis Le Texier
*/

#include	"my.h"

int		my_putchar(int c)
{
  return (my_fputchar(STD_OUTPUT, c));
}
