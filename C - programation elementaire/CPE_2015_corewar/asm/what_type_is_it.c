/*
** what_type_is_it.c for what_type_is_it in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas@epitech.net>
**
** Started on  Mon Mar 21 20:33:26 2016 Hugo Baldassin
** Last update Wed Mar 23 17:31:25 2016 Hugo Baldassin
*/

#include	"op.h"
#include	"asm.h"

int		what_type_is_it(char *arg, int y)
{
  if (is_a_register(arg, y) == 1)
    return (T_REG);
  if (is_a_direct(arg, y) == 1)
    return (T_DIR);
  if (is_an_index(arg, y) == 1)
    return (T_IND);
  return (0);
}
