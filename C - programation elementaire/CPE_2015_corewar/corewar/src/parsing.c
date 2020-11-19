/*
** parsing.c for  in /home/hurlu/rendu/CPE_2015_corewar/VM
**
** Made by Hugo Willaume
** Login   <willau_h@epitech.net>
**
** Started on  Tue Mar 22 17:29:31 2016 Hugo Willaume
** Last update Sun Mar 27 23:08:07 2016 Hugo Willaume
*/

#include <stdlib.h>
#include "virtual.h"
#include "op.h"
#include "basics.h"

int	scan_error(int error, char **av, int i)
{
  if (error == 0)
    return (error);
  if (error == 2 || error == 21)
    {
      my_putstr(av[i - 1]);
      if (error == 2)
	my_putstr(" is not even a .cor file.\n");
      if (error == 21)
	my_putstr(" is not a good .cor: wrong magic number!\n");
    }
  else if (error == 3)
    my_putstr("Please enter a positive number for -n or -a \n");
  else if (error == 4)
    my_putstr("-a or -n should be followed by a .cor file \n");
  else if (error == 5)
    my_putstr("You cannot do twice -a or -n for one champion!\n");
  else if (error == 42)
    my_putstr(" Malloc error.\n");
  my_putstr("HELP : corewar [-dump nbr_cycle] [[-n prog_number]\
 [-a load_address ] prog_name] \n");
  return (error);
}

int	set_dump_cycles(char *av, t_arena *arena)
{
  if (arena->dump[0] == 1)
    {
      my_putstr("\x1b[31m");
      my_putstr("Why would you even try to dump the arena multiple times?\n");
      my_putstr("\x1b[0m");
      return (1);
    }
  arena->dump[0] = 1;
  if (av == NULL || my_getnbr(av) < 0)
    {
      my_putstr("\x1b[31m");
      if (av == NULL)
      	my_putstr("NULL");
      else
	my_putstr(av);
      my_putstr(" is not a valid argument for dump_nb_cycle: please enter");
      my_putstr(" a positive number.\n");
      my_putstr("\x1b[0m");
      return (1);
    }
  arena->dump[1] = my_getnbr(av);
  return (0);
}

int	parsing_user(int ac, char **av, t_champions **champs, t_arena *arena)
{
  int	i;
  int	error;

  arena->dump[0] = 0;
  arena->dump[1] = 0;
  arena->last_living = -1;
  i = 1;
  error = 0;
  while (i < ac && error == 0)
    {
      if (my_strcmp("-dump", av[i]) == 0)
	{
	  error = set_dump_cycles(av[i + 1], arena);
	  i += 2;
	}
      else if ((my_strcmp("-a", av[i]) == 0 || my_strcmp("-n", av[i]) == 0))
      	error = big_read_cor_file(&av[i], &i, champs);
      else
	error = read_cor_file(av[i++], champs);
    }
  return (scan_error(error, av, i));
}
