/*
** engine.h for 42sh in /home/flipper/rendu/42sh/PSU_2015_42sh/include/
**
** Made by Matthis Le Texier
** Login   <le-tex_m@epitech.eu>
**
** Started on  Mon May  2 13:32:27 2016 Matthis Le Texier
** Last update Mon May 23 09:39:55 2016 Matthis Le Texier
*/

#include "typedef.h"

#ifndef ENGINE_H_
# define  ENGINE_H_

int	launch_42(t_data *data);
void	aff_prompt(void);
void	clean_buffer(char *buff);

#endif
