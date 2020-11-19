/*
** check_args.c for myirc in /home/pauline/rendu/psu/PSU_2016_myirc
**
** Made by Pauline Maes
** Login   <maes_p@epitech.eu>
**
** Started on  Thu May 25 16:18:09 2017 Pauline Maes
** Last update Thu May 25 17:28:03 2017 Pauline Maes
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

static int	isnum(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
      i++;
    }
  return (0);
}

int		check_args(int ac, char **av, int *port)
{
  if (ac != 2 || strcmp(av[1], "--help") == 0)
    {
      fprintf(stderr, "USAGE: ./server port\n");
      return (0);
    }
  if (isnum(av[1]) != 0)
    {
      fprintf(stderr, "Error: port must be a positive integer\n");
      return (84);
    }
  *port = atoi(av[1]);
  return (1);
}
