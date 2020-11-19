/*
** my_strcp.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan  7 14:57:50 2016 Forteville Gabriel
** Last update Sun Jan 24 15:32:05 2016 Forteville Gabriel
*/

#include <stdlib.h>

char	*my_strcpy(char *src, int start, int end)
{
  int	i;
  char	*goal;

  i = 0;
  if (end == 0)
    while (src[end] != 0)
      end++;
  goal = malloc(sizeof(char) * (end - start + 1));
  while ((start + i) != end)
    {
      goal[i] = src[start + i];
      i++;
    }
  goal[i] = 0;
  return (goal);
}
