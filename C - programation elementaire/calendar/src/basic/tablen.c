/*
** tablen.c for calendar in /home/fortevg/rendu/calendar/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jul 01 15:06:36 2016 Forteville Gabriel
** Last update Fri Jul 01 17:22:57 2016 Forteville Gabriel
*/

#include	<stdlib.h>

int		tablen(char **tab)
{
  int	index;

  index = 0;
  while (tab[index] != NULL)
    index++;
  return (index);
}
