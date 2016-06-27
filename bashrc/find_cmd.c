/*
** find_cmd.c for PSU_2015_42sh in /home/juquet_q/rendu/PSU/PSU_2015_42sh/bashrc
**
** Made by juquet_q
** Login   <juquet_q@epitech.net>
**
** Started on  Tue May 31 11:44:52 2016 juquet_q
** Last update Tue May 31 15:59:33 2016 juquet_q
*/

int	find_cmd(char *enter, char *find)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (enter[i] != find[j] && enter[i] != '\0')
    i++;
  while (enter[i] != '\0' && find[j] != '\0' && enter[i] == find[j])
    {
      i++;
      j++;
    }
  if (enter[i] == '\0' && find[j] == '\0')
    return (0);
  else
    return (1);
}
