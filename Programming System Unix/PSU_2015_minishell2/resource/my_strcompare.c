/*
** my_strcompare.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Jan  5 18:14:02 2016 Forteville Gabriel
** Last update Tue Apr 26 16:47:12 2016 Forteville Gabriel
*/

#include	<stdlib.h>

int		my_strcompare(char *str1, char *str2, int limit)
{
  int		i;

  i = 0;
  if (str1 == NULL || str2 == NULL)
   return (0);
  while (str1[i] == str2[i] && str1[i] != 0 && str2[i] != 0 && i < limit)
    i++;
   if (((str1[i] == ' ' || str1[i] == '\n' || str1[i] == 0) && str2[i] == 0)
      || i == limit)
    return (i);
  return (-1);
}
