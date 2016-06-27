/*
** get_next_line.h for get_next_line in /home/flipper/rendu/getnextline/CPE_2015_getnextline/include/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon Jan  4 16:03:13 2016 Matthis Le Texier
** Last update Tue Apr  5 10:56:52 2016 Matthis Le Texier
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef NB_CHAR_READ
#  define NB_CHAR_READ (1024)
# endif /* !NB_CHAR_READ */

char *get_next_line(const int fd);

#endif

/*
** !GET_NEXT_LINE_H
*/