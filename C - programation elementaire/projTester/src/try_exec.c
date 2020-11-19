/*
** exec.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Fri Jun 24 10:33:54 2016 Forteville Gabriel
** Last update Sat Jun 25 15:26:22 2016 Gabriel Forteville
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"basic.h"

int		try_exec(char *name_exec, int start)
{
  char		*path;
  char		**separate_path;

  if (access(name_exec, X_OK) == 0)
    return (0);
  path = getenv("PATH");
  if (path == NULL)
    error("binary not found");
  separate_path = my_str_to_wordtab(path, ":");
  while (separate_path[start] != NULL)
    {
      separate_path[start] = my_path(separate_path[start], name_exec);
      if (access(separate_path[start], X_OK) == 0)
	{
	  freetab(separate_path);
	  return (0);
	}
      start++;
    }
  return (1);
}
