/*
** main.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Wed Jun 22 11:37:53 2016 Forteville Gabriel
** Last update Sat Jun 25 13:39:53 2016 Forteville Gabriel
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<dirent.h>
#include	<stdio.h>
#include	<unistd.h>
#include	"main.h"

int		main(int ac, char **av)
{
  DIR		*dir;
  char		*for_free;

  dir = parsing(ac, av);
  if (ac == 2)
    {
      print_dir(av[1]);
      alphabe_tree(dir, 1);
    }
  else
    {
      argment((for_free = getcwd(NULL, 0)), dir, av[2]);
      free(for_free);
    }
  return (0);
}
