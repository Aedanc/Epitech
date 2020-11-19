/*
** my_exit.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/Builtins
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Jan  7 14:25:06 2016 Forteville Gabriel
** Last update Sun Jan 24 12:55:34 2016 Forteville Gabriel
*/

#include <stdlib.h>
#include "../../my.h"

int		main(int ac, char ** av)
{
  int		i;
  int		check;

  if (ac > 2)
    return (my_putstr("exit: Expression Syntax.\n"));
  i = 0;
  if (av[1] != NULL)
    {
      i = my_get_nbr(av[1], 0);
      if (i == 0)
	return (my_putstr("exit: Expression Syntax.\n"));
      check = 0;
      while (av[1][check] != 0)
	{
	  if (av[1][check] < '0' || av[1][check] > '9')
	    return (my_putstr("exit: Badly formed number.\n"));
	  check++;
	}
    }
  exit (i);
}
