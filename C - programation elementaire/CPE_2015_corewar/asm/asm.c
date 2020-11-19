/*
** asm.c for asm in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Wed Mar 16 12:17:33 2016 Hugo Baldassin
** Last update Wed Mar 23 17:28:15 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"

int		compile(char **av)
{
  int		y;

  y = 1;
  while (av[y] != NULL)
    {
      if (compile_and_pars(av[y]) == -1)
	return (y);
      y++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  int		arg;

  if (args_errors(ac, av) < 0)
    return (-1);
  arg = compile(av);
  if (arg > 0)
    {
      fake_printf("Error occured while compiling arg ", (arg - 1), NULL, "\n");
      return (-1);
    }
  return (0);
}
