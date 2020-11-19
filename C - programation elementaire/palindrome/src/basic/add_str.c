/*
** add_str.c for palindrome in /home/fortevg/rendu/palindrome/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jun 17 09:35:57 2016 Forteville Gabriel
** Last update Fri Jun 17 17:29:42 2016 Forteville Gabriel
*/

#include		<stdlib.h>
#include		"basic.h"

char			*add_str(char *str1, char *str2)
{
  int			result;

  result = atoi(str1) + atoi(str2);
  if (result < 0)
    return (NULL);
  return (int_to_str(result));
}
