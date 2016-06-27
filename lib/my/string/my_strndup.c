/*
** my_strndup.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 10:00:10 2016 Matthis Le Texier
** Last update Mon Apr  4 10:00:11 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

char		*my_strndup(const char *str, int n)
{
  char		*dup;

  if (str == NULL)
    return (NULL);
  if ((dup = malloc((n + 1) * sizeof(char))) == NULL)
    return (NULL);
  if (my_strncpy(dup, str, n) == RET_FAILURE)
    return (NULL);
  return (dup);
}
