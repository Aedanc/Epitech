/*
** my_put_nbr.c for my_put_nbr in /home/fortev_g/daywork/piscine_j07/library
**
** Made by Gabriel Forteville
** Login   <fortev_g@epitech.net>
**
** Started on  Tue Oct  6 09:53:41 2015 Gabriel Forteille
** Last update Sun Feb 21 23:23:40 2016 Forteville Gabriel
*/

#include "include.h"

int	my_put_nbr_base(int nb, char *base)
{
  int	tamp;

  if ((nb < my_strlen(base) && (nb >= 0)) ||
      (nb > -my_strlen(base) && nb <= 0))
    {
      if (nb < 0)
	{
	  my_putchar('-');
	  my_putchar(base[nb * -1]);
	}
      else
	my_putchar(base[nb]);
      return (0);
    }
  tamp = nb;
  nb = nb / my_strlen(base);
  my_put_nbr_base(nb, base);
  nb = tamp % my_strlen(base);
  if (nb < 0)
    my_putchar(base[nb * (-1)]);
  else
    my_putchar(base[nb]);
  return (my_strlen(base));
}
