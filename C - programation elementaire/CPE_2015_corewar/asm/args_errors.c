/*
** args_errors.c for arg_errors in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Wed Mar 16 12:21:30 2016 Hugo Baldassin
** Last update Wed Mar 23 17:26:55 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"my.h"

int		is_asm_file(char *file_name)
{
  int		len;

  len = my_strlen(file_name);
  if (len < 3)
    return (0);
  if (file_name[len - 2] == '.' && file_name[len - 1] == 's')
    return (1);
  else
    return (0);
}

int		args_errors(int ac, char **av)
{
  int	y;

  y = 1;
  if (ac == 1)
    {
      my_putstr("Usage: ./asm file_name[.s] file_name2[.s]...\n");
      return (-1);
    }
  while (av[y] != NULL)
    {
      if (is_asm_file(av[y]) == 0)
	{
	  fake_printf("File ", 0, av[y], " invalid.\n");
	  return (-2);
	}
      y++;
    }
  return (0);
}
