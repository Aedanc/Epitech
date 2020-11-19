/*
** is_num.c for is_num in /home/baldas/Prog/repos/cpe/CPE_2015_corewar/asm/baldas
**
** Made by Hugo Baldassin
** Login   <baldas_h@epitech.net>
**
** Started on  Sat Mar 19 12:00:47 2016 Hugo Baldassin
** Last update Wed Mar 23 17:31:08 2016 Hugo Baldassin
*/

#include	"my.h"

int		is_num(char *str)
{
  int		i;

  i = 0;
  if (my_strlen(str) == 0)
    return (0);
  if (str[0] == '-')
    i++;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  if (str[i - 1] == '-')
    return (0);
  return (1);
}
