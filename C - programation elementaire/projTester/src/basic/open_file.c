/*
** open_file.c for projTester in /home/fortevg/rendu/projTester/src
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sat Jun 25 16:03:20 2016 Forteville Gabriel
** Last update Sat Jun 25 17:31:03 2016 Forteville Gabriel
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<string.h>

void			open_file(char *name_file)
{
  int			fd;

  name_file[strlen(name_file) - 1] = 0;
  fd = open(name_file, O_RDONLY);
  if (fd != -1)
    dup2(fd, 0);
  else
    dup2(0, 0);
  close(fd);
}
