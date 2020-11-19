/*
** error_displays.c for error_displays in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Thu Mar 24 01:26:39 2016 Hugo Baldassin
** Last update Thu Mar 24 23:44:29 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"asm.h"
#include	"my.h"

void		error_displays(int flag, int y)
{
  if (flag == -1)
    {
      fake_printf("Syntax error line ", y, NULL, "\n");
      exit(flag);
    }
  else if (flag == -2)
    fake_printf("Warning indirection ot far line ", y, NULL, "\n");
  else if (flag == -4)
    {
      fake_printf("no such register line ", y, NULL, "\n");
      exit(flag);
    }
  else if (flag == -5)
    fake_printf("Warning Direct too big line ", y, NULL, "\n");
  else if (flag == -7)
    {
      my_putstr("Can't perform malloc");
      exit(flag);
    }
  else if (flag == -9)
    {
      fake_printf("Error: multiple param definition line ", y, NULL, "\n");
      exit(flag);
    }
}
