/*
** manage_error.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Mon Jun  5 18:56:04 2017 Pauline Maes
** Last update Sun Jun 11 13:37:51 2017 Pauline Maes
*/

#include	<stdio.h>
#include	<unistd.h>

int		manage_error(char *msg, int fd)
{
  int		ret;

  fprintf(stderr, msg);
  ret = close(fd);
  if (ret == -1)
    fprintf(stderr, "Error: could not close socket\n");
  return (0);
}
