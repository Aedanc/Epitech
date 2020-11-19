/*
** freetab.c for projTester in /home/fortevg/rendu/projTester/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 23 19:49:36 2016 Forteville Gabriel
** Last update Thu Jun 23 19:50:30 2016 Forteville Gabriel
*/

#include	<stdlib.h>

void		freetab(char **tab)
{
  int		index;

  index = 0;
  while (tab[index] != NULL)
    {
      free(tab[index]);
      index++;
    }
  free(tab);
}
