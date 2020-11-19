/*
** my_strlen.c for projTester in /home/fortevg/rendu/projTester/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 23 11:40:42 2016 Forteville Gabriel
** Last update Thu Jun 23 11:48:56 2016 Forteville Gabriel
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
