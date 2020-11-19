/*
** main.c for PSU in /home/fortevg/Bureau/rendu/PSU/PSU_2015_my_ls
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Tue Nov 24 20:58:29 2015 Forteville Gabriel
** Last update Sun Nov 29 22:39:09 2015 Forteville Gabriel
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int		my_printdir(struct dirent *readthis, DIR *dir, int i, char **av)
{
  while ((readthis = readdir(dir)) != NULL)
    {
      if ((readthis->d_name[0]) != '.')
	{
	  my_printf("%s", readthis->d_name);
	  if (readdir(dir) != NULL)
	    my_putchar(' ');
	}
    }
  my_putchar('\n');
  return (0);
}

int		my_ls(struct dirent *readthis, DIR *dir, char **av, int i)
{
  i = 0;
  if (av[1] == 0)
    {
      dir = opendir(".");
      my_printdir(readthis, dir, i, av);
      closedir(dir);
      return (0);
    }
  while (av[++i] != NULL)
    {
      if (av[2] != 0)
	my_printf("%s:\n", av[i]);
      dir = opendir(av[i]);
      if (dir == NULL)
	{
	  my_printf("my_ls: can't acces to the file/directory: %s\n", av[i]);
	  return (0);
	}
      else
	my_printdir(readthis, dir, i, av);
      closedir(dir);
    }
  return (0);
}

int		main(int ac, char **av)
{
  struct dirent	*readthis;
  DIR		*dir;
  int		i;

  my_ls(readthis, dir, av, i);
  return (0);
}
