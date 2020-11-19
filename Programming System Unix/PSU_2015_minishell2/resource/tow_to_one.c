/*
** 2strto1.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Apr 07 15:17:30 2016 Forteville Gabriel
** Last update Fri May  6 14:37:17 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

char		*tow_to_one(char *str1, char *str2, bool malloc1, bool malloc2)
{
  char		*goal;
  int		goendstr1;
  int		goendstr2;

  goendstr1 = -1;
  if ((goal = malloc(sizeof(char) * (my_strlen(str1)
				     + my_strlen(str2) + 1))) == NULL)
  return (NULL);
  goal[my_strlen(str1) + my_strlen(str2)] = 0;
  while (str1[++goendstr1] != 0)
    goal[goendstr1] = str1[goendstr1];
  goendstr2 = 0;
  while (str2[goendstr2] != 0)
    {
      goal[goendstr1] = str2[goendstr2];
      goendstr1++;
      goendstr2++;
    }
  goal[goendstr1] = 0;
  if (malloc1 == TRUE)
    free(str1);
  if (malloc2 == TRUE)
    free(str2);
  return (goal);
}
