/*
** my_strlen.c for  in /home/fortevg/rendu/PSU/PSU_2015_my_select
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Dec  8 12:43:16 2015 Forteville Gabriel
** Last update Tue Apr 12 13:48:35 2016 Forteville Gabriel
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != 0)
    i++;
  return (i);
}
