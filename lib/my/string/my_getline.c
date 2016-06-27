/*
** my_getline.c for libmy in /home/flipper/rendu/template/lib/my/string/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Apr  4 09:58:07 2016 Matthis Le Texier
** Last update Mon Apr  4 09:58:08 2016 Matthis Le Texier
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"my.h"

static int	stock(char **, int *, char *);
static bool	has_line(char *, char **, bool);
static void	clean_storage(char *, int);

char		*my_getline(const int fd)
{
  static char	*storage = NULL;
  static int	storage_size = READ_SIZE + 1;
  char		*line;
  char		buffer[READ_SIZE + 1];
  int		read_len;

  if (storage == NULL)
    if ((storage = my_calloc(storage_size * sizeof(char))) == NULL)
      return (NULL);
  while ((read_len = read(fd, buffer, READ_SIZE)) > 0)
    {
      buffer[read_len] = '\0';
      if (stock(&storage, &storage_size, buffer) == RET_FAILURE)
	return (NULL);
      while (has_line(storage, &line, false))
	return (line);
    }
  while (has_line(storage, &line, true))
    return (line);
  free(storage);
  return (NULL);
}

static int	stock(char **storage_ptr, int *storage_size, char *buffer)
{
  int		storage_len;
  int		buffer_len;

  storage_len = my_strlen(*storage_ptr);
  buffer_len = my_strlen(buffer);
  if ((*storage_size - 1) - storage_len < buffer_len)
    {
      *storage_ptr = my_realloc(*storage_ptr, *storage_size,
				*storage_size + READ_SIZE * sizeof(char));
      if (*storage_ptr == NULL)
	return (RET_FAILURE);
      *storage_size += READ_SIZE;
    }
  return (my_strcat(*storage_ptr, buffer));
}

static bool	has_line(char *storage, char **line_ptr, bool is_last)
{
  int		pos;

  if ((pos = my_strpos(storage, '\n')) != RET_ERROR)
    {
      if ((*line_ptr = my_calloc((pos + 2) * sizeof(char))))
	my_strncpy(*line_ptr, storage, pos);
      clean_storage(storage, pos + 1);
      return (true);
    }
  else if (is_last && storage[0] != '\0')
    {
      pos = my_strlen(storage);
      if ((*line_ptr = my_calloc((pos + 1) * sizeof(char))))
        my_strcpy(*line_ptr, storage);
      clean_storage(storage, pos);
      return (true);
    }
  return (false);
}

static void	clean_storage(char *storage, int pos)
{
  int		i;

  i = 0;
  while (storage[i + pos])
    {
      storage[i] = storage[i + pos];
      i++;
    }
  storage[i] = '\0';
}
