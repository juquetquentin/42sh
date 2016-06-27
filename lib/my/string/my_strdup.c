/*
** my_strdup.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:59:35 2016 Matthis Le Texier
** Last update Mon Apr  4 09:59:36 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

char		*my_strdup(const char *str)
{
  char		*dup;

  if (str == NULL)
    return (NULL);
  if ((dup = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  if (my_strcpy(dup, str) == RET_FAILURE)
    return (NULL);
  return (dup);
}
