/*
** my_newvarenv.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Apr 08 17:54:53 2016 Forteville Gabriel
** Last update Wed May 11 17:33:45 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

char		*my_newvarenv(char *str1, char *str2, bool ismall, bool ismall2)
{
  char		*goal;
  int		goendstr1;
  int		goendstr2;

  goendstr1 = -1;
  goal = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 2));
  goal[my_strlen(str1) + my_strlen(str2) + 1] = 0;
  while (str1[++goendstr1] != 0)
    goal[goendstr1] = str1[goendstr1];
  goal[goendstr1] = '=';
  goendstr1++;
  goendstr2 = 0;
  if (str2 != NULL)
    while (str2[goendstr2] != 0)
      {
	goal[goendstr1] = str2[goendstr2];
	goendstr1++;
	goendstr2++;
      }
  goal[goendstr1] = 0;
  if (ismall == TRUE && str1 != NULL)
    free(str1);
  if (ismall2 == TRUE && str2 != NULL)
    free(str2);
  return (goal);
}
