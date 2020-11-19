/*
** fake_printf.c for fake_printf in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Wed Mar 16 12:34:28 2016 Hugo Baldassin
** Last update Wed Mar 23 17:31:39 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"my.h"

void		fake_printf(char *p1, int nb, char *str, char *p2)
{
  my_putstr(p1);
  if (str != NULL)
    my_putstr(str);
  else
    my_put_nbr(nb);
  my_putstr(p2);
}
