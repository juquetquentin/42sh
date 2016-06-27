/*
** built_in_additional.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/PSU_2015_42sh/src/built_in
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Tue May 31 16:23:28 2016 moutou_m
** Last update Tue May 31 16:41:23 2016 moutou_m
*/

#include <stdbool.h>

bool	is_charalpha(const char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
      return (true);
    }
  return (false);
}

bool	is_charnumber(const char c)
{
  if (c >= '0' && c <= '9')
    {
      return (true);
    }
  return (false);
}

bool	is_number(const char *str)
{
  while (*str != '\0')
    {
      if (*str < '0' || *str > '9')
	return (false);
      str = str + 1;
    }
  return (true);
}
