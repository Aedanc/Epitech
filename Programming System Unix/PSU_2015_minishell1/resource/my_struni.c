/*
** my_struni.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sun Jan 24 11:13:52 2016 Forteville Gabriel
** Last update Sun Jan 24 16:20:32 2016 Forteville Gabriel
*/

#include <stdlib.h>

char		*my_struni(char *str1, char *str2)
{
  char		*goal;
  int		len1;
  int		len2;

  len1 = 0;
  len2 = 0;
  while (str1[len1] != 0)
    len1++;
  while (str2[len2] != 0)
    len2++;
  goal = malloc(sizeof(char) * (len1 + len2 + 2));
  len1 = -1;
  len2 = 0;
  while (str1[++len1] != 0)
    goal[len1] = str1[len1];
  goal[len1] = '/';
  len1++;
  while (str2[len2] != 0)
    {
      goal[len1] = str2[len2];
      len1++;
      len2++;
    }
  goal[len1] = 0;
  return (goal);
}
