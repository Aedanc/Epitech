/*
** sum_stdarg.c for bootstrapprintf in /home/fortev_g/Desktop/libmy
** 
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
** 
** Started on  Thu Nov  5 10:39:01 2015 Gabriel Forteville
** Last update Sun Nov 15 22:25:53 2015 Gabriel Forteville
*/
#include <stdarg.h>

int	sum_stdarg(int i, int nb, ...)
{
  va_list ap;
  int	compteur;
  int	res;

  res = 0;
  compteur = -1;
  va_start(ap, nb);
  while (i == 0 && compteur++ != nb)
    res += va_arg(ap, int);
  while (i == 1 && (compteur++ + 1) != nb)
    res += my_strlen(va_arg(ap, char *));
  return (res);
}
