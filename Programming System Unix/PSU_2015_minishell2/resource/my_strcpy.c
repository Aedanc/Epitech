/*
** my_strcpy.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Mon Apr 18 15:15:50 2016 Forteville Gabriel
** Last update Wed May 11 17:44:58 2016 Forteville Gabriel
*/

#include <stdlib.h>

char	*my_strcpy(char *src, int start, int end)
{
  int	i;
  char	*goal;

  if (src == NULL)
    return (NULL);
  i = 0;
  if (end == 0)
    while (src[end] != 0)
      end++;
  if ((goal = malloc(sizeof(char) * (end - start + 1))) == NULL)
    return (NULL);
  while ((start + i) != end)
    {
      goal[i] = src[start + i];
      i++;
    }
  goal[i] = 0;
  return (goal);
}
