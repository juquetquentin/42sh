/*
** get_next_line.c for get_next_line in /home/flipper/rendu/getnextline/CPE_2015_getnextline/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Jan  4 16:05:16 2016 Matthis Le Texier
** Last update Tue Apr  5 11:23:17 2016 Matthis Le Texier
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*init_save()
{
  char *save;
  int i;

  if ((save = malloc(sizeof(char) * (NB_CHAR_READ + 1))) == NULL)
    return (NULL);
  i = 0;
  while (i <= NB_CHAR_READ)
    save[i++] = '\0';
  return (save);
}

char	*realloc_add(char *str, char *add, int *len, int oct)
{
  int i;
  int j;
  char *newstr;

  if ((newstr = malloc(sizeof(char) * (*len + oct + 1))) == NULL)
    return (NULL);
  i = -1;
  while (str != NULL && ++i < *len)
    newstr[i] = str[i];
  j = -1;
  while (add != NULL && ++j < oct)
    newstr[i++] = add[j];
  newstr[i] = '\0';
  *len = i;
  free(str);
  return (newstr);
}

int	check_the_save(char **save, char **line, int *len)
{
  int 	i;

  if (save[0][0] == '\0')
    return (0);
  if (((*line) = malloc(sizeof(char) * (*len + 1))) == NULL)
    return (1);
  i = -1;
  while (++i < *len && save[0][i] != '\n')
    (*line)[i] = save[0][i];
  (*line)[i] = '\0';
  if (save[0][i] == '\0')
    return (0);
  *save = *save + i + 1;
  *len = *len - (i + 1);
  return (1);
}

char	*get_next_line(const int fd)
{
  static char 	*save;
  static int	len;
  char 		buf[NB_CHAR_READ];
  char 		*line;
  int 		oct;

  if (len == 0)
    if ((save = init_save()) == NULL)
	return (NULL);
  line = NULL;
  if (check_the_save(&save, &line, &len) == 1)
    return (line);
  while ((oct = read(fd, buf, NB_CHAR_READ)) > 0 && NB_CHAR_READ > 0)
    {
      if ((save = realloc_add(save, buf, &len, oct)) == NULL)
	return (NULL);
      if (check_the_save(&save, &line, &len) == 1)
	return (line);
      free(line);
    }
  if (oct == 0 && len > 0)
    return (((len = 0) == 0) ? save : NULL);
  return (NULL);
}
