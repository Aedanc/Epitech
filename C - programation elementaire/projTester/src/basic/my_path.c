/*
** my_struni.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sun Jan 24 11:13:52 2016 Forteville Gabriel
** Last update Fri Jun 24 13:32:59 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"basic.h"

char		*my_path(char *str1, char *str2)
{
  int		lenstr1;
  int		goendstr2;

  lenstr1 = my_strlen(str1);
  str1 = realloc(str1, sizeof(char) * (lenstr1 + my_strlen(str2) + 2));
  str1[lenstr1 + my_strlen(str2) + 1] = 0;
  str1[lenstr1] = '/';
  lenstr1++;
  goendstr2 = 0;
  while (str2 != NULL && str2[goendstr2] != 0)
    {
      str1[lenstr1] = str2[goendstr2];
      lenstr1++;
      goendstr2++;
    }
  return (str1);
}
