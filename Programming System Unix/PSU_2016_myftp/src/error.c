/*
** error.c for  in /home/fortevg/rendu/PSU/PSU_2016_myftp/src/error
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Thu May 11 15:02:06 2017 Gabriel Forteville
** Last update Sun May 21 20:49:55 2017 Gabriel Forteville
*/

#include		<stdio.h>
#include		<string.h>
#include		<errno.h>
#include		<unistd.h>
#include		"error.h"

int			close_error(int fd, char *error)
{
  if (close(fd) == -1)
    return put_error("close");
  return put_error(error);
}

int			put_error(char *error)
{
  fprintf(stderr, "error [%s]: %s\n", error, strerror(errno));
  return (-1);
}
