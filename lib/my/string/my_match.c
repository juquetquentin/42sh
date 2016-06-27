/*
** my_match.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:58:16 2016 Matthis Le Texier
** Last update Mon Apr  4 09:58:18 2016 Matthis Le Texier
*/

#include	<stdlib.h>
#include	"my.h"

bool		my_match(const char *str, const char *pattern)
{
  if (str == NULL || pattern == NULL)
    return (false);
  if (*pattern != '*')
    {
      if (*str)
	return (*str == *pattern
		&& my_match(str + sizeof(char), pattern + sizeof(char)));
      else
	return (!*pattern);
    }
  return (my_match(str, pattern + sizeof(char))
	  || (*str && my_match(str + sizeof(char), pattern)));
}
