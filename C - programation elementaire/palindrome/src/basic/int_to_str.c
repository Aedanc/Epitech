/*
** my_str_to_int.c for palindrome in /home/fortevg/rendu/palindrome/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jun 17 09:56:21 2016 Forteville Gabriel
** Last update Sat Jun 18 11:05:23 2016 Forteville Gabriel
*/

#include		<stdlib.h>
#include		<stdio.h>
#include		<strings.h>
#include		"basic.h"

char			*int_to_str(int nbr)
{
  char			*result;

  if (nbr < 0)
    return (NULL);
  if ((result = malloc(sizeof(char) * intlen(nbr) + 1)) == NULL)
    return (NULL);
  bzero(result, intlen(nbr) + 1);
  sprintf(result, "%d", nbr);
  return (result);
}
