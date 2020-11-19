/*
** is_a_command.c for is_a_command in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Mar 21 19:26:02 2016 Hugo Baldassin
** Last update Wed Mar 23 17:30:25 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"

int		is_a_command(char *arg)
{
  int		y;

  y = 0;
  while (op_tab[y].mnemonique != 0)
    {
      if (my_strcmp(op_tab[y].mnemonique, arg) == 0)
	return (y);
      y++;
    }
  return (-1);
}
