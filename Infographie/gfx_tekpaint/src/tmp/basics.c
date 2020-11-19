/*
** basics.c for  in /home/baldas/Prog/repos/info/gfx_tekpaint/src/tmp
**
** Made by baldas
** Login   <baldas@epitech.net>
**
** Started on  Tue Jan 26 21:42:57 2016 baldas
** Last update Tue Jan 26 23:11:40 2016 Hugo Willaume
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[++i] != 0);
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
