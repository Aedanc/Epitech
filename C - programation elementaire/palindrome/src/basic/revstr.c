/*
** revstr.c for palindrome in /home/fortevg/rendu/palindrome/src/basic
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jun 16 16:48:17 2016 Forteville Gabriel
** Last update Sat Jun 18 12:13:22 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	<string.h>

char		*revstr(char *str)
{
  char		*res;
  int		index_str;
  int		index_result;

  if (str == NULL || (res = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  index_str = 0;
  index_result = 0;
  while (str[index_str] != 0)
    index_str++;
  index_str--;
  while (index_str >= 0)
    {
      res[index_result] = str[index_str];
      index_str--;
      index_result++;
    }
  res[strlen(str)] = 0;
  return (res);
}
