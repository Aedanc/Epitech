/*
** parsing.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jun 22 11:44:18 2016 Forteville Gabriel
** Last update Sat Jun 25 14:00:31 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	<dirent.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<stdio.h>
#include	"basic.h"
#include	"parsing.h"

DIR		*parsing(int ac, char **av)
{
  DIR		*dir;

  if (ac > 3)
    error("to many arguments");
  if (av[1] == NULL)
    error("projTester need a directory") ;
  if ((dir = opendir(av[1])) == NULL)
    error("invalid path");
  chdir(av[1]);
  if (ac == 3)
    if (try_exec(av[2], 0) == 1)
      error("binary not found");
  return (dir);
}
