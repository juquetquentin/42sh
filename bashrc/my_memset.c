/*
** my_memset.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Tue May 31 11:31:59 2016 juquet_q
** Last update Tue May 31 11:35:48 2016 juquet_q
*/

char	*my_memset(char	*ptr, int set, int len)
{
  int	i;

  i = 0;
  while (i < len)
    ptr[i++] = set;
  return (ptr);
}
