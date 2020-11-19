/*
** my_strlen.c for  in /home/fortevg/rendu/SBMLparser/src/basic
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Mon Jun 13 12:40:15 2016 Gabriel Forteville
** Last update Mon Jun 13 13:08:19 2016 Forteville Gabriel
*/

#include	<stdlib.h>

int		my_strlen(char *str)
{
  int		result;

  if (str == NULL)
    return (0);
  result = 0;
  while (str[result] != 0)
    result++;
  return (result);
}
