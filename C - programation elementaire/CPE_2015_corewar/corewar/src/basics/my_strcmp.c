/*
** my_strcmp.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM/src/basics
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 16:54:00 2016 Hugo Willaume
** Last update Sun Mar 27 05:37:44 2016 Hugo Willaume
*/

#include	<stdlib.h>

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  if (str1 == NULL || str2 == NULL)
    return (42);
  i = 0;
  while (str1[i] != 0 && str2[i] != 0 && str1[i] == str2[i])
    i++;
  if (str1[i] != str2[i])
    return (-1);
  else
    return (0);
}
