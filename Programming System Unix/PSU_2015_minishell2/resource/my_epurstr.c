/*
** my_purgestr.c for PSU_2015_minishell2 in /home/fortevg/rendu/PSU/PSU_2015_minishell2/resource
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Apr 07 23:38:37 2016 Forteville Gabriel
** Last update Wed May 11 19:22:18 2016 Forteville Gabriel
*/

#include        <stdlib.h>
#include        "minishell.h"

char		*my_epurstr(char *str, char separator, bool ismalloc)
{
  char	*clean;
  char	*st;
  char	*result;

  st = str;
  clean = str;
  while (*clean != 0)
    {
      if (*clean == separator && (*(clean + 1) == separator || *(clean + 1) == 0
				  || clean == st))
	{
	  while (clean != st)
	    {
	      *clean = *(clean - 1);
	      clean--;
	    }
	  st++;
	}
      clean++;
    }
  result = my_strcpy(st, 0, 0);
  if (ismalloc == TRUE)
    free(str);
  return (result);
}
