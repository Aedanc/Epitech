/*
** tablen.c for projTester in /home/fortevg/rendu/projTester/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 23 16:43:35 2016 Forteville Gabriel
** Last update Thu Jun 23 17:13:47 2016 Forteville Gabriel
*/

#include	<stdlib.h>

int		tablen(char **tab)
{
  int		index;

  index = 0;
  if (tab == NULL)
    return (0);
  while (tab[index] != NULL)
    index++;
  return (index);
}
