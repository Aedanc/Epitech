/*
** freetab.c for calendar in /home/fortevg/rendu/calendar/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 15:20:54 2016 Forteville Gabriel
** Last update Fri Jul 01 15:38:46 2016 Forteville Gabriel
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
