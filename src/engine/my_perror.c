/*
** my_perror.c for PSU_2015_42sh in /home/moutou_m/rendu/42SH/toto/PSU_2015_42sh/src/engine
**
** Made by moutou_m
** Login   <moutou_m@epitech.net>
**
** Started on  Sun Jun 05 15:02:02 2016 moutou_m
** Last update Sun Jun 05 15:04:44 2016 moutou_m
*/

#include <errno.h>
#include <stdio.h>
#include <string.h>

void	my_perror(const char *str)
{
  fprintf(stderr, "%s: %s\n", str, strerror(errno));
}
