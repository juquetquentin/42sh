/*
** my_strstr.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 10:01:17 2016 Matthis Le Texier
** Last update Mon Apr  4 10:01:18 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

const char	*my_strstr(const char *haystack, const char *needle)
{
  const char	*tmp;

  if (haystack == NULL || needle == NULL)
    return (NULL);
  tmp = haystack;
  while ((tmp = my_strchr(tmp, *needle)))
    {
      if (my_strncmp(tmp, needle, my_strlen(needle)) == 0)
	return (tmp);
      tmp = tmp + sizeof(char);
    }
  return (NULL);
}
