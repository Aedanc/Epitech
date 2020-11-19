/*
** print_dir.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jun 24 11:02:08 2016 Forteville Gabriel
** Last update Fri Jun 24 11:51:51 2016 Forteville Gabriel
*/

#include	<stdio.h>

void		print_dir(char *path)
{
  int		i;

  i = 0;
  while (path[i] != 0)
    i++;
  if (i >= 2)
    i -= 2;
  while (i > 0 && path[i] != '/')
    i--;
  while (path[i] != 0)
    {
      if (path[i] != '/')
	printf("%c", path[i]);
      i++;
    }
  printf("/\n");
}
