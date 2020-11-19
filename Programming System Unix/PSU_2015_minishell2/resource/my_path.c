/*
** my_struni.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sun Jan 24 11:13:52 2016 Forteville Gabriel
** Last update Fri May 13 15:32:37 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

char		*my_path(char *str1, char *str2)
{
  char		*goal;
  int		goendstr1;
  int		goendstr2;

  goendstr1 = -1;
  goal = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
  goal[my_strlen(str1) + my_strlen(str2) + 1] = 0;
  while (str1[++goendstr1] != 0)
    goal[goendstr1] = str1[goendstr1];
  goal[goendstr1] = '/';
  goendstr1++;
  goendstr2 = 0;
  while (str2 != NULL && str2[goendstr2] != 0)
    {
      goal[goendstr1] = str2[goendstr2];
      goendstr1++;
      goendstr2++;
    }
  goal[goendstr1] = 0;
  return (goal);
}
