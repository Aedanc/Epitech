/*
** my_exit.c for  in /home/fortevg/rendu/PSU/PSU_2015_minishell1/Builtins
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Thu Mar 31 20:08:32 2016 Forteville Gabriel
** Last update Wed May 11 19:31:22 2016 Forteville Gabriel
*/

#include	<stdlib.h>
#include	"minishell.h"

int             my_exit(char **av, char **env, char **need_free)
{
  int           i;
  int           check;

  i = 0;
  if (av == NULL)
    {
      (env != NULL) ? free_tab(env) : (void)env;
      my_putstr("\nexit\n");
      exit (0);
    }
  if (av[1] != NULL && av[2] != NULL)
    return (my_putstr("exit: Expression Syntax.\n"));
  if (av[1] != NULL)
    {
      i = my_get_nbr(av[1], i = 0);
      check = -1;
      while (av[1][++check] != 0)
	if ((av[1][check] < '0' || av[1][check] > '9') && av[1][check] != '-')
	    return (my_putstr("exit: Badly formed number.\n"));
      }
  free_tab(need_free);
  free_tab(av);
  free_tab(env);
  my_putstr("exit\n");
  exit(i);
}
