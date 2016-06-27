/*
** built_in_tablen.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/built_in
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Tue May 31 16:20:35 2016 moutou_m
** Last update Tue May 31 16:42:51 2016 moutou_m
*/

#include <stdlib.h>

size_t		built_in_tab_len(const char **tab)
{
  size_t	incr;

  incr = 0;
  while (tab != NULL && tab[incr] != NULL)
    {
      incr = incr + 1;
    }
  return (incr);
}
