/*
** clean_buffer.c for 42sh in /home/flipper/rendu/42sh/PSU_2015_42sh/src/engine/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon May  2 14:18:30 2016 Matthis Le Texier
** Last update Wed Jun 08 09:45:11 2016 moutou_m
*/

#include <stdbool.h>
#include <string.h>
#include "shell.h"

bool		is_special_char(char c)
{
  if (c == '|' || c == '<' || c == '>' || c == '&' || c == ';')
    return true;
  return false;
}

int		strclean(char *str)
{
  int		i;
  int		j;
  bool	cleaned;

  if (str == NULL)
    return (RET_FAILURE);
  cleaned = false;
  j = 0;
  i = 0;
  while (str[i])
    {
      if (!cleaned && (str[i] == '\t' || str[i] == ' '))
	cleaned = true;
      else if (str[i] != '\t' && str[i] != ' ')
	{
	  if (j != 0 && cleaned)
	    str[j++] = ' ';
	  str[j++] = str[i];
	  cleaned = false;
	}
      i++;
    }
  str[j] = '\0';
  return (RET_SUCCESS);
}

void	clean_buffer(char *buff)
{
  int	i;
  int	j;
  char  clean[READ_SIZE];

  strclean(buff);
  i = -1;
  j = 0;
  while (buff[++i] && j < READ_SIZE - 1)
    {
      if (buff[i] != '\"' && buff[i] != '\'')
	{
	  clean[j++] = buff[i];
	  if (buff[i + 1] && buff[i] != ' ' && !is_special_char(buff[i])
	  && is_special_char(buff[i + 1]))
	    clean[j++] = ' ';
	  if (is_special_char(buff[i]) && is_special_char(buff[i + 1]) == false
	  && buff[i + 1] != ' ')
	    clean[j++] = ' ';
	}
    }
  clean[j] = '\0';
  strcpy(buff, clean);
}
