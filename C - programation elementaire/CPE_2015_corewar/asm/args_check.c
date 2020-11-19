/*
** args_check.c for args_check in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Thu Mar 17 21:59:50 2016 Hugo Baldassin
** Last update Thu Mar 24 23:46:04 2016 Hugo Baldassin
*/

#include	<stdlib.h>
#include	"op.h"
#include	"my.h"
#include	"asm.h"

int		is_an_index(char *arg, int y)
{
  if (is_num(arg) == 0 && arg[0] != '-' && my_strlen(arg) != 1)
    return (0);
  if (arg[0] != 'r' && arg[0] != LABEL_CHAR && arg[0] != DIRECT_CHAR &&
      is_num(arg) == 0)
    error_displays(-1, y);
  if (my_getnbr(arg) > IDX_MOD)
    fake_printf("Warning Indirection to far line ", y, NULL, "\n");
  return (1);
}

int		is_a_register(char *arg, int y)
{
  if (arg[0] != 'r')
    return (0);
  if (is_num(arg + 1) == 0)
    error_displays(-1, y);
  if (my_getnbr(arg + 1) < 1 || my_getnbr(arg + 1) > REG_NUMBER)
    error_displays(-4, y);
  return (1);
}

int		is_a_direct(char *arg, int y)
{
  if (arg[0] != DIRECT_CHAR)
    return (0);
  if (is_num(arg + 1) == 0 && is_a_label(arg, y) == 0)
    error_displays(-1, y);
  if (is_a_label(arg, y) == 0)
    if (my_get_long(arg + 1) > power_of_two(DIR_SIZE))
      error_displays(-5, y);
  return (1);
}
